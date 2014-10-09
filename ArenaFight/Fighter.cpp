#include "Fighter.hpp"
#include "Utility.hpp"
#include "CharacterDataTables.hpp"

#include <iostream>

#include <SFML\Graphics\RenderWindow.hpp>

#include <iostream>

// Set up our fighter
Fighter::Fighter(Type type, sf::Vector2f position)
	: mType(type)
	, mState(None)
	, mTextures()
	, mCurrentAnim()
	, mAnimations()
	, mGrounded(false)
	, mFlip(1.f)
	, mVelocity(0.f, 0.f)
{
	setPosition(position);
	load();
}

// Load all the everything for our fighter
// Textures, Animations, framedata, etc.
void Fighter::load()
{
	CharData data = initializeCharData(mType);

	mHealth = data.health;
	mWeight = data.weight;	

	mTextures.load(Textures::Stand, "Textures/Fighter/" + typeToString() + "/Stand.png");
	mTextures.load(Textures::LStand, "Textures/Fighter/" + typeToString() + "/LStand.png");
	mTextures.load(Textures::Run, "Textures/Fighter/" + typeToString() + "/Run.png");
	mTextures.load(Textures::LRun, "Textures/Fighter/" + typeToString() + "/LRun.png");
	mTextures.load(Textures::Falling, "Textures/Fighter/" + typeToString() + "/Falling.png");
	mTextures.load(Textures::LFalling, "Textures/Fighter/" + typeToString() + "/LFalling.png");
	mTextures.load(Textures::Landing, "Textures/Fighter/" + typeToString() + "/Landing.png");
	mTextures.load(Textures::LLanding, "Textures/Fighter/" + typeToString() + "/LLanding.png");
	mTextures.load(Textures::Hurt, "Textures/Fighter/" + typeToString() + "/Hurt.png");
	mTextures.load(Textures::LHurt, "Textures/Fighter/" + typeToString() + "/LHurt.png");

	mTextures.load(Textures::Guard, "Textures/Fighter/" + typeToString() + "/Guard.png");
	mTextures.load(Textures::LGuard, "Textures/Fighter/" + typeToString() + "/LGuard.png");
	mTextures.load(Textures::NLight, "Textures/Fighter/" + typeToString() + "/NLight.png");
	mTextures.load(Textures::LNLight, "Textures/Fighter/" + typeToString() + "/LNLight.png");
	mTextures.load(Textures::SLight, "Textures/Fighter/" + typeToString() + "/SLight.png");
	mTextures.load(Textures::LSLight, "Textures/Fighter/" + typeToString() + "/LSLight.png");
	mTextures.load(Textures::ULight, "Textures/Fighter/" + typeToString() + "/ULight.png");
	mTextures.load(Textures::LULight, "Textures/Fighter/" + typeToString() + "/LULight.png");
	mTextures.load(Textures::DLight, "Textures/Fighter/" + typeToString() + "/DLight.png");
	mTextures.load(Textures::LDLight, "Textures/Fighter/" + typeToString() + "/LDLight.png");

	mAnimations.add(&mTextures.get(Textures::Stand), Animation::Stand, data.standData, true); 
	mAnimations.add(&mTextures.get(Textures::Run), Animation::Run, data.runData, true); 
	mAnimations.add(&mTextures.get(Textures::Falling), Animation::Falling, data.fallData, false);
	mAnimations.add(&mTextures.get(Textures::Landing), Animation::Landing, data.landingData, false);
	mAnimations.add(&mTextures.get(Textures::Hurt), Animation::Hurt, data.hurtData, false);

	mAnimations.add(&mTextures.get(Textures::Guard), Animation::Guard, data.guardData, false);
	mAnimations.add(&mTextures.get(Textures::NLight), Animation::NLight, data.nLightData, false);
	mAnimations.add(&mTextures.get(Textures::SLight), Animation::SLight, data.sLightData, false);
	mAnimations.add(&mTextures.get(Textures::ULight), Animation::ULight, data.uLightData, false);
	mAnimations.add(&mTextures.get(Textures::DLight), Animation::DLight, data.dLightData, false);

	//Left facing animations
	mAnimations.add(&mTextures.get(Textures::LStand), Animation::LStand, data.LstandData, true); 
	mAnimations.add(&mTextures.get(Textures::LRun), Animation::LRun, data.LrunData, true); 
	mAnimations.add(&mTextures.get(Textures::LFalling), Animation::LFalling, data.LfallData, false);
	mAnimations.add(&mTextures.get(Textures::LLanding), Animation::LLanding, data.LlandingData, false);
	mAnimations.add(&mTextures.get(Textures::LHurt), Animation::LHurt, data.LhurtData, false);

	mAnimations.add(&mTextures.get(Textures::LGuard), Animation::LGuard, data.LguardData, false);
	mAnimations.add(&mTextures.get(Textures::LNLight), Animation::LNLight, data.LnLightData, false);
	mAnimations.add(&mTextures.get(Textures::LSLight), Animation::LSLight, data.LsLightData, false);
	mAnimations.add(&mTextures.get(Textures::LULight), Animation::LULight, data.LuLightData, false);
	mAnimations.add(&mTextures.get(Textures::LDLight), Animation::LDLight, data.LdLightData, false);

	mCurrentAnim = mAnimations.get(Animation::Stand);
}

// Update our fighter depending on what state he currently is in
void Fighter::update(sf::Time dt)
{
	if(mGrounded)
	{
		mVelocity.y = 0;

		if (mState != Hurt && mState != Lag && mState != Attacking)
		{
			if(mVelocity.x != 0)
				changeAnimation(Animation::Run);
			else if(mState != Guarding)
				changeAnimation(Animation::Stand);
		}
		else if(mCurrentAnim.getIsDone())
		{
			mState = None;
			changeAnimation(Animation::Stand);
			mTotalHits = 0;
		}
	}
	else if (mState == Hurt && mVelocity.x != 0)
		mVelocity.x = mVelocity.x * -mFlip - .1f;
	else
	{
		mVelocity.y = 80.f;
		changeAnimation(Animation::Falling);
	}

	move(mVelocity.x * dt.asSeconds(), mVelocity.y * dt.asSeconds());
	mCurrentAnim.update(dt, getPosition());
	directionUpdate();


	mGroundBox = sf::FloatRect(getPosition().x, getPosition().y, (float)mCurrentAnim.getFrameSize().x, 1.f);
	mGroundBox.left = getPosition().x;
	mGroundBox.top = getPosition().y;
}

// Draw our fighter
// Commented out code draws the fighter's ground box (the box that determines if the character is on the ground)
void Fighter::draw(sf::RenderWindow& window) const
{
	mCurrentAnim.draw(window);

	/*sf::RectangleShape rectangle;
	rectangle.setFillColor(sf::Color::Black);
	rectangle.setPosition(mGroundBox.left, mGroundBox.top);
	rectangle.setSize(sf::Vector2f(mGroundBox.width, mGroundBox.height));

	window.draw(rectangle);*/

}

void Fighter::setVelocity(float x, float y)
{
	mVelocity.x = x;
	mVelocity.y = y;
}

sf::Vector2f Fighter::getVelocity() const
{ return mVelocity; }

// Set if we're grounded or not
// If we're changing to grounded make sure we play our landing animation
// Incomplete as does not take into account if we are sent flying by an attack
void Fighter::setGrounded(bool grounded)
{ 
	if (grounded != mGrounded)
	{
		if(grounded)
		{
			mState = Lag;
			mVelocity.x = 0.f;
			changeAnimation(Animation::Landing);
		}

		mGrounded = grounded; 
	}
}

sf::FloatRect Fighter::getGroundBox() const
{ return mGroundBox; }

void Fighter::setState(Fighter::State state)
{ mState = state; }

Fighter::State Fighter::getState() const
{ return mState; }

sf::IntRect Fighter::getAttackBox() const
{ return mCurrentAnim.getAttackBox(); }

sf::IntRect Fighter::getBoundBox() const
{ return mCurrentAnim.getBoundBox(); }

int Fighter::getDamage() const
{ return mCurrentAnim.getDamage(); }

int Fighter::getNumOfHits() const
{ return mCurrentAnim.getNumOfHits(); }

float Fighter::getHitStun() const
{ return mCurrentAnim.getHitStun(); }

sf::Vector2f Fighter::getKnockBack() const
{ return mCurrentAnim.getKnockBack(); }

void Fighter::addHit()
{ mTotalHits++; }

int Fighter::getTotalHits() const
{ return mTotalHits; }

Animation::Type Fighter::getLeftAnimEnum(Animation::Type type)
{ return static_cast<Animation::Type>(static_cast<int>(type) + 1); }

Animation::Type Fighter::getRightAnimEnum(Animation::Type type)
{ return static_cast<Animation::Type>(static_cast<int>(type) - 1); }

void Fighter::directionUpdate()
{
	if(mFlip > 0 && (static_cast<int>(mCurrentAnim.getType()) % 2) != 0)
		mCurrentAnim = mAnimations.get(getLeftAnimEnum(mCurrentAnim.getType()));
	else if (mFlip < 0 && (static_cast<int>(mCurrentAnim.getType()) % 2) == 0)
		mCurrentAnim = mAnimations.get(getRightAnimEnum(mCurrentAnim.getType()));
}

// Change the fighter's current animation
// If animation doesn't change then we shouldn't keep assigning it
void Fighter::changeAnimation(Animation::Type type)
{
	if(mCurrentAnim.getType() != type && mCurrentAnim.getType() != getLeftAnimEnum(type))
		if(mFlip < 0)
			mCurrentAnim = mAnimations.get(getLeftAnimEnum(type));
		else
			mCurrentAnim = mAnimations.get(type);
}

void Fighter::takeDamage(int amount, float hitStun, float xKnockBack, float yKnockBack)
{
	mHealth -= amount;
	mVelocity.x = xKnockBack;
	mState = Hurt;
	changeAnimation(Animation::Hurt);
	mCurrentAnim.setFrameDuration(0, hitStun);
	std::cout << mHealth << std::endl;
}

// "Convert" our fighter's type to a string
// Used when loading things
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
{ 
	mFlip = -1.f;

	mVelocity.x = -50.f; 
}

void Fighter::MoveRight()
{ 
	mFlip = 1.f;

	mVelocity.x = 50.f; 
}

void Fighter::Guard()
{ 
	mVelocity = sf::Vector2f(0.f, 0.f);
	changeAnimation(Animation::Guard); 
}

void Fighter::NeutralLightAttack()
{
	mState = Attacking;
	changeAnimation(Animation::NLight);
}

void Fighter::SideLightAttack(float xScale)
{
	mFlip = xScale;

	mState = Attacking;
	mVelocity.x = 0.f;
	changeAnimation(Animation::SLight);
}

void Fighter::UpLightAttack()
{
	mState = Attacking;
	changeAnimation(Animation::ULight);
}

void Fighter::DownLightAttack()
{
	mState = Attacking;
	changeAnimation(Animation::DLight);
}