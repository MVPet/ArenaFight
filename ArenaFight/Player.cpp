#include "Player.hpp"
#include "BattleData.hpp"

#include <SFML\Graphics\RenderWindow.hpp>

// Set up our player
Player::Player(int playerNo, sf::Vector2f position)
	: mPlayerNo(playerNo)
	, mCharacter(selectedFighters[mPlayerNo], position)
{
	setUpControls();
}

// Update the player
// Takes into account the input provided by the user and the state the user's character is in.
void Player::update(sf::Time dt)
{
	if(mCharacter.getState() != Fighter::Hurt && mCharacter.getState() != Fighter::Lag && mCharacter.getState() != Fighter::Attacking)
	{
		if(mActionStatus[MoveLeft])
			mCharacter.MoveLeft();
		else if (mActionStatus[MoveRight])
			mCharacter.MoveRight();
		else
			mCharacter.setVelocity(0.f,0.f);

		if(mActionStatus[Guard])
		{
			mCharacter.setState(Fighter::Guarding);
			mCharacter.Guard();
		}
		else
			mCharacter.setState(Fighter::None);

		if(mActionStatus[LightAttack])
		{
			if(mActionStatus[MoveLeft])
				mCharacter.SideLightAttack(-1.f);
			else if (mActionStatus[MoveRight])
				mCharacter.SideLightAttack(1.f);
			else if(mActionStatus[Up])
				mCharacter.UpLightAttack();
			else if(mActionStatus[Guard])
				mCharacter.DownLightAttack();
			else
				mCharacter.NeutralLightAttack();
		}
	}

	mCharacter.update(dt);
}

// Draw the character the player is controlling
void Player::draw(sf::RenderWindow& window) const
{
	mCharacter.draw(window);
}

// Handle events that are thrown at the player
// Currently no events could happen to the player
void Player::handleEvent(const sf::Event& event)
{
	if(event.type == sf::Event::KeyPressed)
	{
		auto found = mKeyBinding.find(event.key.code);
		if(found != mKeyBinding.end() && !isRealtimeAction(found->second))
		{}
	}
}

// Handle input that is provided by the user
void Player::handleRealtimeInput()
{
	for(auto pair : mKeyBinding)
	{
		if(sf::Keyboard::isKeyPressed(pair.first))
			mActionStatus[pair.second] = true;
		else
			mActionStatus[pair.second] = false;
	}
}

void Player::takeDamage(int amount, float hitStun, float xKnockBack, float yKnockBack)
{ mCharacter.takeDamage(amount, hitStun, xKnockBack, yKnockBack); }

// Assign the keys that the player will use to control the character
void Player::assignKey(Action action, sf::Keyboard::Key key)
{
	for (auto itr = mKeyBinding.begin(); itr != mKeyBinding.end(); )
	{
		if(itr->second == action)
			mKeyBinding.erase(itr++);
		else
			++itr;
	}

	mKeyBinding[key] = action;
}

sf::Keyboard::Key Player::getAssignedKey(Action action) const
{
	for(auto pair : mKeyBinding)
		if(pair.second == action)
			return pair.first;

	return sf::Keyboard::Unknown;
}

void Player::setPosition(float x, float y)
{ mCharacter.setPosition(x, y); }

sf::Vector2f Player::getPosition() const
{ return mCharacter.getPosition(); }

void Player::setVelocity(float x, float y)
{ mCharacter.setVelocity(x, y); }

sf::Vector2f Player::getVelocity() const
{ return mCharacter.getVelocity(); }

void Player::setGrounded(bool value)
{ mCharacter.setGrounded(value); }

sf::FloatRect Player::getGroundBox() const
{ return mCharacter.getGroundBox(); }

sf::IntRect Player::getAttackBox() const
{ return mCharacter.getAttackBox(); }

sf::IntRect Player::getBoundBox() const
{ return mCharacter.getBoundBox(); }

int Player::getDamage() const
{ return mCharacter.getDamage(); }

int Player::getNumOfHits() const
{ return mCharacter.getNumOfHits(); }

float Player::getHitStun() const
{ return mCharacter.getHitStun(); }

sf::Vector2f Player::getKnockBack() const
{ return mCharacter.getKnockBack(); }

void Player::addHit() 
{ mCharacter.addHit(); }

int Player::getTotalHits() const
{ return mCharacter.getTotalHits(); }

// Checks if the action is an action that should be done in real time
// Currently serves a miniscule purpose and will probably be removed
bool Player::isRealtimeAction(Action action)
{
	switch (action)
	{
	case MoveLeft:
	case MoveRight:
		return true;
	default:
		return false;
	}
}

void Player::setUpControls()
{
	switch(mPlayerNo)
	{
	case 0:
		mKeyBinding[sf::Keyboard::Left] = MoveLeft;
		mKeyBinding[sf::Keyboard::Right] = MoveRight;
		mKeyBinding[sf::Keyboard::Up] = Up;
		mKeyBinding[sf::Keyboard::Down] = Guard;
		mKeyBinding[sf::Keyboard::A] = LightAttack;
		break;
	case 1:
		mKeyBinding[sf::Keyboard::J] = MoveLeft;
		mKeyBinding[sf::Keyboard::L] = MoveRight;
		mKeyBinding[sf::Keyboard::I] = Up;
		mKeyBinding[sf::Keyboard::K] = Guard;
		mKeyBinding[sf::Keyboard::T] = LightAttack;
		break;
	}

	mActionStatus[MoveLeft] = false;
	mActionStatus[MoveRight] = false;
	mActionStatus[Guard] = false;
	mActionStatus[Up] = false;
	mActionStatus[LightAttack] = false;
}