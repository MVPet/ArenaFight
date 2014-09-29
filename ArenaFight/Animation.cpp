#include "Animation.hpp"

// Default constructor
Animation::Animation()
{}

// constructor initializes and "creates" the animation
Animation::Animation(sf::Texture* texture, Type type, std::vector<AnimFrame> frameData, bool loop) 
	: mTexture(texture)
	, mFrameData(frameData)
	, mNumOfFrames(mFrameData.size())
	, mType(type)
	, mLoop(loop)
	, mUpdateTime(0.0) 
	, mFrameIndex(0)
	, mIsDone(false)
{
	mFrameWidth = mTexture->getSize().x / mNumOfFrames;
	mFrameHeight = mTexture->getSize().y;

	mSprite.setTexture(*mTexture);
	mSprite.setTextureRect(sf::IntRect(0, 0, mFrameWidth, mFrameHeight));
	mSprite.setPosition(0,0);

	// Temporary fix, need to implement animation origin system
	mSprite.setOrigin(0, mFrameHeight);
}

void Animation::update(sf::Time deltaTime, sf::Vector2f position, float xScale)
{
	mUpdateTime += deltaTime.asSeconds();

	if(!mIsDone && mUpdateTime >= mFrameData[mFrameIndex].getFrameTime())
	{
		mFrameIndex++;
		mUpdateTime = 0.0f;

		if(mFrameIndex >= mNumOfFrames)
		{
			if(mLoop)
				mFrameIndex = 0;
			else
			{
				mIsDone = true;
				mFrameIndex--;
			}
		}
			
		mSprite.setTextureRect(sf::IntRect(mFrameIndex * mFrameWidth, 0, mFrameWidth, mFrameHeight));
	}

	mSprite.setPosition(position);
	mSprite.setScale(xScale, 1.f);
}

void Animation::draw(sf::RenderWindow& window) const
{ window.draw(mSprite); }

Animation::Type Animation::getType() const
{ return mType; }

sf::Vector2i Animation::getFrameSize() const
{ return sf::Vector2i(mFrameWidth, mFrameHeight); }

bool Animation::getIsDone() const
{ return mIsDone; }

void Animation::setScale(float x, float y)
{ mSprite.setScale(x, y); }