#include "Stage.hpp"
#include "Utility.hpp"
#include "StageDataTables.hpp"

#include <SFML\Graphics\RenderWindow.hpp>

Stage::Stage(Type id)
	: mType(id)
	, mTerrain()
	, mBackground()
	, mTextures()
{ 
	load(); 
}

void Stage::update(sf::Time dt)
{}

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

void Stage::draw(sf::RenderWindow& window) const
{
	window.draw(mBackground);

	if(!mTerrain.empty())
		for (Terrain t : mTerrain)
			t.draw(window);
}

std::vector<Terrain> Stage::getTerrain() const
{ return mTerrain; }

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