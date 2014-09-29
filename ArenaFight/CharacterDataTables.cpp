#include "CharacterDataTables.hpp"

// Initialize the data for the characters
CharData initializeCharData(Fighter::Type type)
{
	// Only get the fighter we want, not ALL the data
	switch (type)
	{
	case Fighter::Kenshiro:
		return kenshiroData();

	default:
		return CharData();
	}
}

// Kenshiro's data
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

	data.fallData.push_back(AnimFrame(sf::IntRect(0, 0, 41, 59), .1f));

	data.landingData.push_back(AnimFrame(sf::IntRect(0, 0, 39, 55), .2f));
	data.landingData.push_back(AnimFrame(sf::IntRect(0, 9, 39, 46), .2f));

	data.guardData.push_back(AnimFrame(sf::IntRect(5,0,24,60), .3f));
	data.guardData.push_back(AnimFrame(sf::IntRect(5,0,24,60), .3f));
	data.guardData.push_back(AnimFrame(sf::IntRect(5,0,24,60), .3f));

	data.nLightData.push_back(AnimFrame(sf::IntRect(6,0, 22, 60), sf::IntRect(28, 9, 10, 18), .1f));
	data.nLightData.push_back(AnimFrame(sf::IntRect(6,0, 22, 60), sf::IntRect(28, 9, 17, 19), .1f));
	data.nLightData.push_back(AnimFrame(sf::IntRect(6,0, 22, 60), sf::IntRect(35, 13, 24, 12), .1f));
	data.nLightData.push_back(AnimFrame(sf::IntRect(6,0, 22, 60), sf::IntRect(39, 13, 20, 12), .1f));
	data.nLightData.push_back(AnimFrame(sf::IntRect(6,0, 22, 60), .1f));

	data.sLightData.push_back(AnimFrame(sf::IntRect(6,0,22,60), .1f));
	data.sLightData.push_back(AnimFrame(sf::IntRect(6,0,22,60), .1f));
	data.sLightData.push_back(AnimFrame(sf::IntRect(6,0,22,60), .1f));
	data.sLightData.push_back(AnimFrame(sf::IntRect(6,0,22,60), sf::IntRect(22,22,14,10),.1f));
	data.sLightData.push_back(AnimFrame(sf::IntRect(6,0,22,60), sf::IntRect(34,13,30,21),.1f));
	data.sLightData.push_back(AnimFrame(sf::IntRect(6,0,22,60), sf::IntRect(41,17,23,13),.1f));
	data.sLightData.push_back(AnimFrame(sf::IntRect(6,0,22,60), .1f));
	data.sLightData.push_back(AnimFrame(sf::IntRect(6,0,22,60), .1f));

	data.uLightData.push_back(AnimFrame(sf::IntRect(7,11,19,58), .1f));
	data.uLightData.push_back(AnimFrame(sf::IntRect(7,11,19,58), .1f));
	data.uLightData.push_back(AnimFrame(sf::IntRect(7,11,19,58), .1f));
	data.uLightData.push_back(AnimFrame(sf::IntRect(5,9,24,60), sf::IntRect(32,3,25,59),.1f));
	data.uLightData.push_back(AnimFrame(sf::IntRect(5,9,24,60), sf::IntRect(31,0,26,34),.1f));
	data.uLightData.push_back(AnimFrame(sf::IntRect(5,9,24,60), sf::IntRect(32,0,16,19),.1f));
	data.uLightData.push_back(AnimFrame(sf::IntRect(7,11,19,58), .1f));
	data.uLightData.push_back(AnimFrame(sf::IntRect(7,11,19,58), .1f));

	data.dLightData.push_back(AnimFrame(sf::IntRect(27,0,22,63), .1f));
	data.dLightData.push_back(AnimFrame(sf::IntRect(27,0,22,63), .1f));
	data.dLightData.push_back(AnimFrame(sf::IntRect(27,0,22,63), .1f));
	data.dLightData.push_back(AnimFrame(sf::IntRect(29,7,20,56), sf::IntRect(17,43,46,20),.1f));
	data.dLightData.push_back(AnimFrame(sf::IntRect(29,7,20,56), sf::IntRect(7,34,66,29),.1f));
	data.dLightData.push_back(AnimFrame(sf::IntRect(29,7,20,56), sf::IntRect(7,34,66,29),.1f));
	data.dLightData.push_back(AnimFrame(sf::IntRect(29,7,20,56), sf::IntRect(7,34,66,29),.1f));
	data.dLightData.push_back(AnimFrame(sf::IntRect(29,7,20,56), sf::IntRect(7,34,66,29),.1f));
	data.dLightOrigin = sf::Vector2f(40, 63);

	return data;
}