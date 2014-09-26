#include "Battle.hpp"
#include "BattleData.hpp"
#include "Terrain.hpp"

#include <SFML\Graphics\RenderWindow.hpp>

Battle::Battle(sf::RenderWindow& window)
	: mWindow(window)
	, mPlayer(0, sf::Vector2f(300, 100))
	, mStage(selectedStage)
{
	mWorldView = mWindow.getDefaultView();
	mWorldBounds = mWindow.getDefaultView().getSize();
}

void Battle::update(sf::Time dt)
{
	mStage.update(dt);

	checkCollisions(dt);

	mPlayer.update(dt);
	mPlayer.handleRealtimeInput();
}

void Battle::handleEvent(sf::Event event)
{
	mPlayer.handleEvent(event);
}

void Battle::draw()
{
	mStage.draw(mWindow);
	mPlayer.draw(mWindow);
}

void Battle::checkCollisions(sf::Time dt)
{
	bool colided = false;

	for (Terrain t : mStage.getTerrain())
	{
		if(t.getBoundBox().intersects(mPlayer.getGroundBox()))
		{
			mPlayer.setGrounded(true);
			colided = true;
		}
	}

	if(!colided)
		mPlayer.setGrounded(false);
}

