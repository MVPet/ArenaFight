#include "Battle.hpp"
#include "BattleData.hpp"

#include <SFML\Graphics\RenderWindow.hpp>

Battle::Battle(sf::RenderWindow& window)
	: mWindow(window)
	//, mPlayer(0)
	, mStage(selectedStage)
{
	mWorldView = mWindow.getDefaultView();
	mWorldBounds = mWindow.getDefaultView().getSize();
}

void Battle::update(sf::Time dt)
{
	mStage.update(dt);
	//mPlayer.handleRealtimeInput();
}

void Battle::handleEvent(sf::Event event)
{
	//mPlayer.handleEvent(event);
}

void Battle::draw()
{
	mStage.draw(mWindow);
	//mPlayer.draw(mWindow);
}

