#ifndef _BATTLE
#define _BATTLE

#include "Player.hpp"
#include "Stage.hpp"

#include <SFML\System\NonCopyable.hpp>
#include <SFML\System\Time.hpp>
#include <SFML\Window\Event.hpp>
#include <SFML\Graphics\View.hpp>
#include <SFML\Graphics\Texture.hpp>

namespace sf
{
	class RenderWindow;
}

class Battle : private sf::NonCopyable
{
public:
	explicit	Battle(sf::RenderWindow& window);
	void		update(sf::Time dt);
	void		handleEvent(sf::Event event);
	void		draw();

private:
	void	checkCollisions(sf::Time dt);

private:
	sf::RenderWindow&	mWindow;
	sf::View			mWorldView;

	sf::Vector2f		mWorldBounds;
	sf::Vector2f		mSpawnPosition;

	Stage				mStage;
	Player				mPlayer;
};

#endif // Battle.hpp