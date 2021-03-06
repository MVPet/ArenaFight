/*
* Stage.hpp
* Each stage is the arena that players fight in
* An example is Battlefield in Super Smash Bros
*/

#ifndef _STAGE
#define _STAGE

#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"
#include "Terrain.hpp"

#include <SFML\System\Time.hpp>
#include <SFML\Graphics\Drawable.hpp>

#include <vector>
#include <string>

namespace sf
{
	class RenderWindow;
}

class Stage
{
public:
	enum Type
	{ Training, TypeCount };

public:	
							Stage(Type id);

	void					update(sf::Time dt);
	void					load();
	void					draw(sf::RenderWindow& window) const;

	std::vector<Terrain>	getTerrain() const;

private:
	std::string typeToString();

private:
	Type					mType;
	std::vector<Terrain>	mTerrain;
	sf::Sprite				mBackground;
	TextureHolder			mTextures;
};

#endif // Stage.hpp