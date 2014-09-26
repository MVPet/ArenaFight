#include "Player.hpp"
#include "BattleData.hpp"

#include <SFML\Graphics\RenderWindow.hpp>

Player::Player(int playerNo, sf::Vector2f position)
	: mPlayerNo(playerNo)
	, mCharacter(selectedFighters[mPlayerNo], position)
{
	mKeyBinding[sf::Keyboard::Left] = MoveLeft;
	mKeyBinding[sf::Keyboard::Right] = MoveRight;
	//mKeyBinding[sf::Keyboard::Up] = MoveUp;
	mKeyBinding[sf::Keyboard::Down] = Guard;
}

void Player::update(sf::Time dt)
{
	mCharacter.update(dt);
}

void Player::draw(sf::RenderWindow& window) const
{
	mCharacter.draw(window);
}

void Player::handleEvent(const sf::Event& event)
{
	if(event.type == sf::Event::KeyPressed)
	{
		auto found = mKeyBinding.find(event.key.code);
		if(found != mKeyBinding.end() && !isRealtimeAction(found->second))
		{}
	}
}

void Player::handleRealtimeInput()
{
	for(auto pair : mKeyBinding)
	{
		if(sf::Keyboard::isKeyPressed(pair.first))
		{
			switch (pair.second)
			{
			case MoveLeft:
				mCharacter.MoveLeft();
				break;

			case MoveRight:
				mCharacter.MoveRight();
				break;
			}
		}
	}
}

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