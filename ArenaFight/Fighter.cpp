#include "Fighter.hpp"
#include "Utility.hpp"
#include "CharacterDataTables.hpp"

#include <iostream>

#include <SFML\Graphics\RenderWindow.hpp>

Fighter::Fighter(Type type, sf::Vector2f position)
	: mType(type)
	, mTextures()
	, mCurrentAnim()
	, mAnimations()
	, mGrounded(false)
	, mPosition(position)
	, mVelocity(0.f, 0.f)
{
	load();
}

void Fighter::update(sf::Time dt)
{
	if(mGrounded)
		mVelocity.y = 0;
	else
		mVelocity.y = 19.f;

	if(mVelocity.x != 0)
		changeAnimation(Animation::Run);
	else
		changeAnimation(Animation::Stand);

	mPosition.x += (mVelocity.x * dt.asSeconds());
	mPosition.y += (mVelocity.y * dt.asSeconds());

	mCurrentAnim.update(dt, mPosition);

	mGroundBox = sf::FloatRect(mPosition.x, mPosition.y, (float)mCurrentAnim.getFrameSize().x, 1.f);
	mGroundBox.left = mPosition.x;
	mGroundBox.top = mPosition.y + mCurrentAnim.getFrameSize().y;
}

void Fighter::load()
{
	CharData data = initializeCharData(mType);

	mTextures.load(Textures::Stand, "Textures/Fighter/" + typeToString() + "/Stand.png");
	mTextures.load(Textures::Run, "Textures/Fighter/" + typeToString() + "/Run.png");
	mTextures.load(Textures::Guard, "Textures/Fighter/" + typeToString() + "/Guard.png");

	mAnimations.add(&mTextures.get(Textures::Stand), Animation::Stand, data.standData, true); 
	mAnimations.add(&mTextures.get(Textures::Run), Animation::Run, data.runData, true); 
	mAnimations.add(&mTextures.get(Textures::Guard), Animation::Guard, data.guardData, true);

	mCurrentAnim = mAnimations.get(Animation::Stand, false);
}

void Fighter::draw(sf::RenderWindow& window) const
{
	mCurrentAnim.draw(window);

	/*sf::RectangleShape rectangle;
	rectangle.setFillColor(sf::Color::Black);
	rectangle.setPosition(mGroundBox.left, mGroundBox.top);
	rectangle.setSize(sf::Vector2f(mGroundBox.width, mGroundBox.height));

	window.draw(rectangle);*/

}

void Fighter::setPosition(float x, float y)
{
	mPosition.x = x;
	mPosition.y = y;
}

sf::Vector2f Fighter::getPosition() const
{ return mVelocity; }

void Fighter::setVelocity(float x, float y)
{
	mVelocity.x = x;
	mVelocity.y = y;
}

sf::Vector2f Fighter::getVelocity() const
{ return mPosition; }

void Fighter::setGrounded(bool grounded)
{ mGrounded = grounded; }

sf::FloatRect Fighter::getGroundBox() const
{ return mGroundBox; }

void Fighter::changeAnimation(Animation::Type type)
{
	if(mCurrentAnim.getType() != type)
		mCurrentAnim = mAnimations.get(type, false);
}

std::string Fighter::typeToString()
{
	switch (mType)
	{
	case Kenshiro:
		return "Kenshiro";
	default:
		return "";
	}
}

void Fighter::MoveLeft()
{ mVelocity.x = -19.f; }

void Fighter::MoveRight()
{ mVelocity.x = 19.f; }

void Fighter::Guard()
{ changeAnimation(Animation::Guard); }