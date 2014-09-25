#ifndef _FIGHTER
#define _FIGHTER

#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"

#include <SFML\System\Time.hpp>
#include <SFML\Graphics\Transformable.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Drawable.hpp>

#include <string>

namespace sf
{
	class RenderWindow;
}

class Fighter : public sf::Transformable
{
public:
	enum Type
	{ Kenshiro };

public:
			Fighter(Type type);

	void	update(sf::Time dt);
	void	load();
	void	draw(sf::RenderWindow& window) const;

private:
	std::string typeToString();

private:
	Type			mType;
	sf::Sprite		mSprite;
	TextureHolder	mTextures;
};

#endif // Fighter.hpp