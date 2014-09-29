/*
* GameState.hpp
* The gameplay portion of the game (aka the most important part)
* Most of the gameplay logic is actually done inside the battle class, 
* This class jsut handles the state itself
*/

#ifndef _GAMESTATE
#define _GAMESTATE

#include "State.hpp"
#include "Battle.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>


class GameState : public State
{
	public:
							GameState(StateStack& stack, Context context);

		virtual void		draw();
		virtual bool		update(sf::Time dt);
		virtual bool		handleEvent(const sf::Event& event);


	private:
		Battle				mBattle;
};

#endif // GameState.hpp