/*
* Player.hpp
* Our hero, the player
* The Player class only handles controlling the fighter and does no logic on the fighter itself
* Fighter Logic is done in Fighter class
*/

#ifndef _PLAYER
#define _PLAYER

#include "Fighter.hpp"

#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"

#include <SFML/Window/Event.hpp>

#include <map>
#include <functional>

namespace sf
{
	class RenderWindow;
}

class Player
{
public:
	enum Action
	{ MoveLeft, MoveRight, Up, Jump, Guard, LightAttack, ActionCount };

public:
						Player(int playerNo, sf::Vector2f position);

	void				update(sf::Time dt);
	void				draw(sf::RenderWindow& window) const;

	void				handleEvent(const sf::Event& event);
	void				handleRealtimeInput();

	void				takeDamage(int amount, float hitStun, float xKnockBack, float yKnockBack);
		
	void				assignKey(Action action, sf::Keyboard::Key key);
	sf::Keyboard::Key	getAssignedKey(Action action) const;

	void				setVelocity(float x, float y);
	sf::Vector2f		getVelocity() const;

	void				setPosition(float x, float y);
	sf::Vector2f		getPosition() const;

	void				setGrounded(bool grounded);

	sf::FloatRect		getGroundBox() const;
	sf::IntRect			getAttackBox() const;
	sf::IntRect			getBoundBox() const;

	int					getDamage() const;
	int					getNumOfHits() const;
	float				getHitStun() const;
	sf::Vector2f		getKnockBack() const;

	void				addHit();
	int					getTotalHits() const;

private:	
	static bool	isRealtimeAction(Action action);
	void		setUpControls();

private:
	int												mPlayerNo;

	Fighter											mCharacter;
	sf::Vector2f									mPosition;
	std::map<sf::Keyboard::Key, Action>				mKeyBinding;
	std::map<Action, bool>							mActionStatus;
};

#endif // Player.hpp