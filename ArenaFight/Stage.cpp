#include "Stage.hpp"
#include "Utility.hpp"
#include "StageDataTables.hpp"

#include <SFML\Graphics\RenderWindow.hpp>

// Set up our stage
Stage::Stage(Type id)
	: mType(id)
	, mTerrain()
	, mBackground()
	, mTextures()
{ 
	load(); 
}

// Updates the stage
// Empty now, but will be used for moving terrain
void Stage::update(sf::Time dt)
{}

// Load the terrain we need for the stage
void Stage::load()
{
	StageData data = initializeStageData(mType);

	if(data.hasBase)
	{
		mTextures.load(Textures::Ground, "Textures/Stages/" + typeToString() + "/Ground.png");
		
		mTerrain.push_back(Terrain(Terrain::Ground, data.basePosition, &mTextures.get(Textures::Ground)));
	}

	if(!data.platformLocations.empty())
	{
		mTextures.load(Textures::Platform, "Textures/Stages/" + typeToString() + "/Platform.png");

		for (sf::Vector2f coord : data.platformLocations)
			mTerrain.push_back(Terrain(Terrain::Platform, coord, &mTextures.get(Textures::Platform)));
	}

	mTextures.load(Textures::Background, "Textures/Stages/" + typeToString() + "/Background.png");

	mBackground.setTexture(mTextures.get(Textures::Background));
	centerOrigin(mBackground);
	mBackground.setPosition(256.f, 128.f);

}

// Draw all the terrain in the stage
void Stage::draw(sf::RenderWindow& window) const
{
	window.draw(mBackground);

	if(!mTerrain.empty())
		for (Terrain t : mTerrain)
			t.draw(window);
}

std::vector<Terrain> Stage::getTerrain() const
{ return mTerrain; }

// "Converts" the type of the stage into a string
// Used for loading the Stage/Terrain textures
std::string Stage::typeToString()
{
	switch (mType)
	{
	case Training:
		return "Train";
	default:
		return "";
	}
}