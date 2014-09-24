#include "Battle.hpp"

#include <SFML\Graphics\RenderWindow.hpp>

#include <algorithm>
#include <cassert>

Battle::Battle(sf::RenderWindow& window)
	: mWindow(window)
	, mPlayer()
	, mStage()
{
	buildBattle();
	mWorldView = mWindow.getDefaultView();
	mWorldBounds = mWindow.getDefaultView().getSize();
}

void Battle::update(sf::Time dt)
{
	mPlayer.handleRealtimeInput();
}

void Battle::handleEvent(sf::Event event)
{
	mPlayer.handleEvent(event);
}

void Battle::draw()
{}

void Battle::buildBattle()
{
	loadPlayers();
}

void Battle::loadPlayers()
{}

