#include "Player.hpp"

Player::Player()
{
	mKeyBinding[sf::Keyboard::Left] = MoveLeft;
	mKeyBinding[sf::Keyboard::Right] = MoveRight;
	mKeyBinding[sf::Keyboard::Up] = MoveUp;
	mKeyBinding[sf::Keyboard::Down] = MoveDown;
}

void Player::handleEvent(const sf::Event& event)
{
	if(event.type == sf::Event::KeyPressed)
	{
		auto found = mKeyBinding.find(event.key.code);
		if(found != mKeyBinding.end() && !isRealtimeAction(found->second))
			mActionBinding[found->second]();
	}
}

void Player::handleRealtimeInput()
{
	for(auto pair : mKeyBinding)
	{
		if(sf::Keyboard::isKeyPressed(pair.first) && isRealtimeAction(pair.second))
			mActionBinding[pair.second]();
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

void Player::initializeActions()
{}

bool Player::isRealtimeAction(Action action)
{
	switch (action)
	{
		case MoveLeft:
		case MoveRight:
		case MoveDown:
		case MoveUp:
			return true;
		default:
			return false;
	}
}