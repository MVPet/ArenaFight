#include "CharacterDataTables.hpp"

CharData initializeCharData(Fighter::Type type)
{
	switch (type)
	{
	case Fighter::Kenshiro:
		return kenshiroData();

	default:
		return CharData();
	}
}

CharData kenshiroData()
{
	CharData data;

	data.health = 100;
	data.weight = 100;

	data.standData.push_back(AnimFrame(sf::IntRect(8,0,24,60), .3f));
	data.standData.push_back(AnimFrame(sf::IntRect(8,0,24,60), .3f));
	data.standData.push_back(AnimFrame(sf::IntRect(8,0,24,60), .3f));
	data.standData.push_back(AnimFrame(sf::IntRect(8,0,24,60), .3f));

	data.runData.push_back(AnimFrame(sf::IntRect(12,2,29,55), .1f));
	data.runData.push_back(AnimFrame(sf::IntRect(12,2,29,55), .1f));
	data.runData.push_back(AnimFrame(sf::IntRect(12,2,29,55), .1f));
	data.runData.push_back(AnimFrame(sf::IntRect(12,2,29,55), .1f));
	data.runData.push_back(AnimFrame(sf::IntRect(12,2,29,55), .1f));
	data.runData.push_back(AnimFrame(sf::IntRect(12,2,29,55), .1f));
	data.runData.push_back(AnimFrame(sf::IntRect(12,2,29,55), .1f));
	data.runData.push_back(AnimFrame(sf::IntRect(12,2,29,55), .1f));

	data.guardData.push_back(AnimFrame(sf::IntRect(5,0,24,60), .3f));
	data.guardData.push_back(AnimFrame(sf::IntRect(5,0,24,60), .3f));
	data.guardData.push_back(AnimFrame(sf::IntRect(5,0,24,60), .3f));

	return data;
}