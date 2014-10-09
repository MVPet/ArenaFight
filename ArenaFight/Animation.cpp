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

void Animation::update(sf::Time deltaTime, sf::Vector2f position)
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

	mFrameData[mFrameIndex].setBoundBoxPosition(position.y - mSprite.getTextureRect().height, position.x);
	mFrameData[mFrameIndex].setAttackBoxPosition(position.y - mSprite.getTextureRect().height, position.x);
}

void Animation::draw(sf::RenderWindow& window) const
{ 
	window.draw(mSprite);

	/*sf::RectangleShape rectangle;
	rectangle.setFillColor(sf::Color::Black);
	rectangle.setPosition(mFrameData[mFrameIndex].getBoundBox().left, mFrameData[mFrameIndex].getBoundBox().top);
	rectangle.setSize(sf::Vector2f(mFrameData[mFrameIndex].getBoundBox().width, mFrameData[mFrameIndex].getBoundBox().height));

	window.draw(rectangle);

	sf::RectangleShape Arectangle;
	Arectangle.setFillColor(sf::Color::Blue);
	Arectangle.setPosition(mFrameData[mFrameIndex].getAttackBox().left, mFrameData[mFrameIndex].getAttackBox().top);
	Arectangle.setSize(sf::Vector2f(mFrameData[mFrameIndex].getAttackBox().width, mFrameData[mFrameIndex].getAttackBox().height));

	window.draw(Arectangle);*/
}

Animation::Type Animation::getType() const
{ return mType; }

sf::Vector2i Animation::getFrameSize() const
{ return sf::Vector2i(mFrameWidth, mFrameHeight); }

bool Animation::getIsDone() const
{ return mIsDone; }

void Animation::setScale(float x, float y)
{ mSprite.setScale(x, y); }

sf::IntRect Animation::getAttackBox() const
{ return mFrameData[mFrameIndex].getAttackBox(); }

sf::IntRect Animation::getBoundBox() const
{ return mFrameData[mFrameIndex].getBoundBox(); }

void Animation::setFrameDuration(int frameIndex, float duration)
{ mFrameData[frameIndex].setFrameTime(duration); }

int Animation::getDamage() const
{ return mFrameData[mFrameIndex].getDamage(); }

int Animation::getNumOfHits() const
{ return mFrameData[mFrameIndex].getNumOfHits(); }

float Animation::getHitStun() const
{ return mFrameData[mFrameIndex].getHitStun(); }

sf::Vector2f Animation::getKnockBack() const
{ return mFrameData[mFrameIndex].getKnockBack(); }