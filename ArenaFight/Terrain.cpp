#include "Terrain.hpp"
#include "Utility.hpp"

#include <SFML\System\Time.hpp>
#include <SFML\Graphics\RenderWindow.hpp>

Terrain::Terrain(Type id, sf::Vector2f position, sf::Texture* texture)
	: mType(id)
{
	mTexture = texture;
	mSprite.setTexture(*mTexture);
	centerOrigin(mSprite);
	mSprite.setPosition(position);
}

void Terrain::update(sf::Time dt)
{}

void Terrain::draw(sf::RenderWindow& window) const
{
	window.draw(mSprite);
}