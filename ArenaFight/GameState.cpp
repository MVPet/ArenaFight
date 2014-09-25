#include "GameState.hpp"
#include "BattleData.hpp"


GameState::GameState(StateStack& stack, Context context)
: State(stack, context)
, mBattle(*context.window)
{
	// Temporary until I create character and stage select
	selectedFighters[0] = Fighter::Kenshiro;
	selectedStage = Stage::Training;
}

void GameState::draw()
{ mBattle.draw(); }

bool GameState::update(sf::Time dt)
{
	mBattle.update(dt);

	return true;
}

bool GameState::handleEvent(const sf::Event& event)
{
	// Game input handling
	mBattle.handleEvent(event);

	// Escape pressed, trigger the pause screen
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		requestStackPush(States::Pause);

	return true;
}