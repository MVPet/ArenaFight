#include "Terrain.hpp"
#include "Utility.hpp"

#include <SFML\System\Time.hpp>
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Graphics\RectangleShape.hpp>

// Set up our terrain
Terrain::Terrain(Type id, sf::Vector2f position, sf::Texture* texture)
	: mType(id)
{
	mTexture = texture;
	mSprite.setTexture(*mTexture);
	centerOrigin(mSprite);
	mSprite.setPosition(position);

	// Depending on the type of terrain, the bounding box could be different
	switch (mType)
	{
	case Platform:
		mBoundBox.left = (int)(position.x - (mTexture->getSize().x / 2));
		mBoundBox.top =  (int)(position.y - (mTexture->getSize().y / 2));
		mBoundBox.width = mTexture->getSize().x;
		mBoundBox.height = mTexture->getSize().y;
		return;
	case Ground:
		mBoundBox.left = (int)(position.x - (mTexture->getSize().x / 2));
		mBoundBox.top =  (int)(position.y - ((mTexture->getSize().y / 2) * .3));
		mBoundBox.width = mTexture->getSize().x;
		mBoundBox.height = mTexture->getSize().y * .95;
		return;
	}
}

// Updates our terrain
// Empty now, but will probably be used for moving terrain
void Terrain::update(sf::Time dt)
{}

// draw the terrain
// Commented out is drawing the bounding box for the terrain
void Terrain::draw(sf::RenderWindow& window) const
{ 
	window.draw(mSprite); 

	/*sf::RectangleShape rectangle;
	rectangle.setFillColor(sf::Color::Black);
	rectangle.setPosition(mBoundBox.left, mBoundBox.top);
	rectangle.setSize(sf::Vector2f(mBoundBox.width, mBoundBox.height));

	window.draw(rectangle);*/
}

sf::FloatRect Terrain::getBoundBox() const
{ return mBoundBox; }