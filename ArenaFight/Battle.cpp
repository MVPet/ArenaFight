#include "Battle.hpp"
#include "BattleData.hpp"
#include "Terrain.hpp"

#include <SFML\Graphics\RenderWindow.hpp>

// Set everything up
Battle::Battle(sf::RenderWindow& window)
	: mWindow(window)
	, mPlayer(0, sf::Vector2f(300, 100))
	, mStage(selectedStage)
{
	mWorldView = mWindow.getDefaultView();
	mWorldBounds = mWindow.getDefaultView().getSize();
}

// Update everything in the battle once per frame
void Battle::update(sf::Time dt)
{
	mStage.update(dt);

	checkCollisions(dt);

	mPlayer.update(dt);
	mPlayer.handleRealtimeInput();
}

// Handle events that occur in the battle
// Pass them to everything that could be affected byt he event
void Battle::handleEvent(sf::Event event)
{
	mPlayer.handleEvent(event);
}

// Draw everything in the battle
void Battle::draw()
{
	mStage.draw(mWindow);
	mPlayer.draw(mWindow);
}

// Checks collisions within the battle
// Currently only checks y coordinates
// Is only temporary, needs huge overhaul
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

