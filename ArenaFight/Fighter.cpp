#include "Fighter.hpp"
/*#include "Utility.hpp"
#include "CharacterDataTables.hpp"

#include <SFML\Graphics\RenderWindow.hpp>

Fighter::Fighter(Type type)
	: mType(type)
	, mSprite()
	, mTextures()
{}

void Fighter::update(sf::Time dt)
{}

void Fighter::load()
{
	mTextures.load(Textures::Stand, "Textures/Fighter/" + typeToString() + "/Stand.png");

	mSprite.setTexture(mTextures.get(Textures::Stand));
	mSprite.setPosition(100, 100);
}

void Fighter::draw(sf::RenderWindow& window) const
{
	window.draw(mSprite);
}

std::string Fighter::typeToString()
{
	switch (mType)
	{
	case Kenshiro:
		return "Kenshiro";
	default:
		return "";
	}
}*/