#include "GameState.hpp"
#include "BattleData.hpp"

// Create the game state
GameState::GameState(StateStack& stack, Context context)
: State(stack, context)
, mBattle(*context.window)
{
	// Temporary until I create character and stage select
	selectedFighters[0] = Fighter::Kenshiro;
	selectedStage = Stage::Training;
}

// Draw our epic battle
void GameState::draw()
{ mBattle.draw(); }

// update the epic battle
bool GameState::update(sf::Time dt)
{
	mBattle.update(dt);

	return true;
}

// handle events during our game state, such as Pausing
bool GameState::handleEvent(const sf::Event& event)
{
	// Game input handling
	mBattle.handleEvent(event);

	// Escape pressed, trigger the pause screen
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		requestStackPush(States::Pause);

	return true;
}