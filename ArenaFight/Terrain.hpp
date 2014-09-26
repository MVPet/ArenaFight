#ifndef _TERRAIN
#define _TERRAIN

#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Texture.hpp>

namespace sf
{
	class Time;
	class RenderWindow;
}

class Terrain
{
public:
	enum Type
	{ Platform, Ground };

public:
					Terrain(Type id, sf::Vector2f position, sf::Texture* texture);

	void			update(sf::Time dt);
	void			draw(sf::RenderWindow& window) const;

	sf::FloatRect		getBoundBox() const;

private:
	Type			mType;
	sf::Texture*	mTexture;
	sf::Sprite		mSprite;
	sf::FloatRect		mBoundBox;
};

#endif // Terrian.hpp