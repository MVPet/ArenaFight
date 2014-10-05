#include "Battle.hpp"
#include "BattleData.hpp"
#include "Terrain.hpp"

#include <SFML\Graphics\RenderWindow.hpp>

// Set everything up
Battle::Battle(sf::RenderWindow& window)
	: mWindow(window)
	, mStage(selectedStage)
{
	mPlayers[0] = new Player(0, sf::Vector2f(300, 100));
	mPlayers[1] = new Player(1, sf::Vector2f(400, 200));

	mWorldView = mWindow.getDefaultView();
	mWorldBounds = mWindow.getDefaultView().getSize();
}

// Update everything in the battle once per frame
void Battle::update(sf::Time dt)
{
	mStage.update(dt);

	checkCollisions(dt);

	for(int i = 0; i < 2; i++)
	{
		if(mPlayers[i] != NULL)
		{
			mPlayers[i]->update(dt);
			mPlayers[i]->handleRealtimeInput();
		}
	}
}

// Handle events that occur in the battle
// Pass them to everything that could be affected byt he event
void Battle::handleEvent(sf::Event event)
{
	for(int i = 0; i < 2; i++)
	{
		if(mPlayers[i] != NULL)
		{
			mPlayers[i]->handleEvent(event);
		}
	}
}

// Draw everything in the battle
void Battle::draw()
{
	mStage.draw(mWindow);

	for(int i = 0; i < 2; i++)
		if(mPlayers[i] != NULL)
			mPlayers[i]->draw(mWindow);
}

// Checks collisions within the battle
// Currently only checks y coordinates
// Is only temporary, needs huge overhaul
void Battle::checkCollisions(sf::Time dt)
{
	bool colided = false;

	// Stage against Players
	for(int i = 0; i < 2; i++)
	{
		colided = false;

		if(mPlayers[i] != NULL)
		{
			for (Terrain t : mStage.getTerrain())
			{
				if(t.getBoundBox().intersects(mPlayers[i]->getGroundBox()))
				{
					mPlayers[i]->setGrounded(true);
					colided = true;
				}
			}

			if(!colided)
				mPlayers[i]->setGrounded(false);
		}
	}

	// Player against Player
	for (int i = 0; i < 1; i++)
		if(mPlayers[i] != NULL)
			for (int j = 1; j < 2; j++)
				if(mPlayers[i]->getAttackBox().intersects(mPlayers[j]->getBoundBox()))
					mPlayers[j]->takeDamage();
}

