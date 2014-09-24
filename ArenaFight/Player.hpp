#ifndef _PLAYER
#define _PLAYER

#include "Fighter.hpp"

#include <SFML/Window/Event.hpp>

#include <map>
#include <functional>

class Player
{
public:
	enum Action
	{ MoveLeft, MoveRight, MoveUp, MoveDown, ActionCount };

public:
			Player();

	void	handleEvent(const sf::Event& event);
	void	handleRealtimeInput();

	void				assignKey(Action action, sf::Keyboard::Key key);
	sf::Keyboard::Key	getAssignedKey(Action action) const;

private:	
	void		initializeActions();
	static bool	isRealtimeAction(Action action);

private:
	Fighter											character;
	std::map<sf::Keyboard::Key, Action>				mKeyBinding;
	std::map<Action, std::function<void()>>			mActionBinding;
};

#endif // Player.hpp