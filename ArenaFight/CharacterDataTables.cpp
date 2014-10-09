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

	//Right
	data.standData.push_back(AnimFrame(sf::IntRect(8,0,24,60), .3f));
	data.standData.push_back(AnimFrame(sf::IntRect(8,0,24,60), .3f));
	data.standData.push_back(AnimFrame(sf::IntRect(8,0,24,60), .3f));
	data.standData.push_back(AnimFrame(sf::IntRect(8,0,24,60), .3f));

	// Left
	data.LstandData.push_back(AnimFrame(sf::IntRect(8,0,24,60), .3f));
	data.LstandData.push_back(AnimFrame(sf::IntRect(8,0,24,60), .3f));
	data.LstandData.push_back(AnimFrame(sf::IntRect(8,0,24,60), .3f));
	data.LstandData.push_back(AnimFrame(sf::IntRect(8,0,24,60), .3f));

	//Right
	data.runData.push_back(AnimFrame(sf::IntRect(12,2,29,55), .1f));
	data.runData.push_back(AnimFrame(sf::IntRect(12,2,29,55), .1f));
	data.runData.push_back(AnimFrame(sf::IntRect(12,2,29,55), .1f));
	data.runData.push_back(AnimFrame(sf::IntRect(12,2,29,55), .1f));
	data.runData.push_back(AnimFrame(sf::IntRect(12,2,29,55), .1f));
	data.runData.push_back(AnimFrame(sf::IntRect(12,2,29,55), .1f));
	data.runData.push_back(AnimFrame(sf::IntRect(12,2,29,55), .1f));
	data.runData.push_back(AnimFrame(sf::IntRect(12,2,29,55), .1f));

	// Left
	data.LrunData.push_back(AnimFrame(sf::IntRect(11,2,29,55), .1f));
	data.LrunData.push_back(AnimFrame(sf::IntRect(11,2,29,55), .1f));
	data.LrunData.push_back(AnimFrame(sf::IntRect(11,2,29,55), .1f));
	data.LrunData.push_back(AnimFrame(sf::IntRect(11,2,29,55), .1f));
	data.LrunData.push_back(AnimFrame(sf::IntRect(11,2,29,55), .1f));
	data.LrunData.push_back(AnimFrame(sf::IntRect(11,2,29,55), .1f));
	data.LrunData.push_back(AnimFrame(sf::IntRect(11,2,29,55), .1f));
	data.LrunData.push_back(AnimFrame(sf::IntRect(11,2,29,55), .1f));

	//Right
	data.fallData.push_back(AnimFrame(sf::IntRect(0, 0, 41, 59), .1f));

	// Left
	data.LfallData.push_back(AnimFrame(sf::IntRect(0, 0, 41, 59), .1f));

	//Right
	data.landingData.push_back(AnimFrame(sf::IntRect(0, 0, 39, 55), .2f));
	data.landingData.push_back(AnimFrame(sf::IntRect(0, 9, 39, 46), .2f));

	// Left
	data.LlandingData.push_back(AnimFrame(sf::IntRect(0, 0, 39, 55), .2f));
	data.LlandingData.push_back(AnimFrame(sf::IntRect(0, 9, 39, 46), .2f));

	//Right
	data.hurtData.push_back(AnimFrame(sf::IntRect(7,5,29,55), .1f));
	data.hurtData.push_back(AnimFrame(sf::IntRect(9,1,31,59), .1f));
	data.hurtData.push_back(AnimFrame(sf::IntRect(6,0,26,60), .1f));

	// Left
	data.LhurtData.push_back(AnimFrame(sf::IntRect(13,5,29,55), .1f));
	data.LhurtData.push_back(AnimFrame(sf::IntRect(9,1,31,59), .1f));
	data.LhurtData.push_back(AnimFrame(sf::IntRect(17,0,26,60), .1f));

	//Right
	data.guardData.push_back(AnimFrame(sf::IntRect(5,0,24,60), .3f));
	data.guardData.push_back(AnimFrame(sf::IntRect(5,0,24,60), .3f));
	data.guardData.push_back(AnimFrame(sf::IntRect(5,0,24,60), .3f));

	// Left
	data.LguardData.push_back(AnimFrame(sf::IntRect(8,0,24,60), .3f));
	data.LguardData.push_back(AnimFrame(sf::IntRect(8,0,24,60), .3f));
	data.LguardData.push_back(AnimFrame(sf::IntRect(8,0,24,60), .3f));

	//Right
	data.nLightData.push_back(AnimFrame(sf::IntRect(6,0, 22, 60), sf::IntRect(28, 9, 10, 18), .1f, 10, .5f, 1, 0, 0));
	data.nLightData.push_back(AnimFrame(sf::IntRect(6,0, 22, 60), sf::IntRect(28, 9, 17, 19), .1f, 10, .5f, 1, 0, 0));
	data.nLightData.push_back(AnimFrame(sf::IntRect(6,0, 22, 60), sf::IntRect(35, 13, 24, 12), .1f, 10, .5f, 1, 0, 0));
	data.nLightData.push_back(AnimFrame(sf::IntRect(6,0, 22, 60), sf::IntRect(39, 13, 20, 12), .1f, 10, .5f, 1, 0, 0));
	data.nLightData.push_back(AnimFrame(sf::IntRect(6,0, 22, 60), .1f));

	// Left
	data.LnLightData.push_back(AnimFrame(sf::IntRect(31,0, 22, 60), sf::IntRect(21, 9, 10, 18), .1f, 10, .5f, 1, 0, 0));
	data.LnLightData.push_back(AnimFrame(sf::IntRect(31,0, 22, 60), sf::IntRect(14, 9, 17, 19), .1f, 10, .5f, 1, 0, 0));
	data.LnLightData.push_back(AnimFrame(sf::IntRect(31,0, 22, 60), sf::IntRect(0, 13, 24, 12), .1f, 10, .5f, 1, 0, 0));
	data.LnLightData.push_back(AnimFrame(sf::IntRect(31,0, 22, 60), sf::IntRect(0, 13, 20, 12), .1f, 10, .5f, 1, 0, 0));
	data.LnLightData.push_back(AnimFrame(sf::IntRect(31,0, 22, 60), .1f));

	//Right
	data.sLightData.push_back(AnimFrame(sf::IntRect(6,0,22,60), .1f));
	data.sLightData.push_back(AnimFrame(sf::IntRect(6,0,22,60), .1f));
	data.sLightData.push_back(AnimFrame(sf::IntRect(6,0,22,60), .1f));
	data.sLightData.push_back(AnimFrame(sf::IntRect(6,0,22,60), sf::IntRect(22,22,14,10), .1f, 10, 1.f, 1, 5, 0));
	data.sLightData.push_back(AnimFrame(sf::IntRect(6,0,22,60), sf::IntRect(34,13,30,21), .1f, 10, 1.f, 1, 5, 0));
	data.sLightData.push_back(AnimFrame(sf::IntRect(6,0,22,60), sf::IntRect(41,17,23,13),.1f, 10, 1.f, 1, 5, 0));
	data.sLightData.push_back(AnimFrame(sf::IntRect(6,0,22,60), .1f));
	data.sLightData.push_back(AnimFrame(sf::IntRect(6,0,22,60), .1f));

	// Left
	data.LsLightData.push_back(AnimFrame(sf::IntRect(36,0,22,60), .1f));
	data.LsLightData.push_back(AnimFrame(sf::IntRect(36,0,22,60), .1f));
	data.LsLightData.push_back(AnimFrame(sf::IntRect(36,0,22,60), .1f));
	data.LsLightData.push_back(AnimFrame(sf::IntRect(36,0,22,60), sf::IntRect(28,22,14,10), .1f, 10, 1.f, 1, 5, 0));
	data.LsLightData.push_back(AnimFrame(sf::IntRect(36,0,22,60), sf::IntRect(0,13,30,21), .1f, 10, 1.f, 1, 5, 0));
	data.LsLightData.push_back(AnimFrame(sf::IntRect(36,0,22,60), sf::IntRect(0,17,23,13),.1f, 10, 1.f, 1, 5, 0));
	data.LsLightData.push_back(AnimFrame(sf::IntRect(36,0,22,60), .1f));
	data.LsLightData.push_back(AnimFrame(sf::IntRect(36,0,22,60), .1f));

	//Right
	data.uLightData.push_back(AnimFrame(sf::IntRect(7,11,19,58), .1f));
	data.uLightData.push_back(AnimFrame(sf::IntRect(7,11,19,58), .1f));
	data.uLightData.push_back(AnimFrame(sf::IntRect(7,11,19,58), .1f));
	data.uLightData.push_back(AnimFrame(sf::IntRect(5,9,24,60), sf::IntRect(32,3,25,59),.1f, 7, 0, 1, 0, 10));
	data.uLightData.push_back(AnimFrame(sf::IntRect(5,9,24,60), sf::IntRect(31,0,26,34),.1f, 7, 0, 1, 0, 10));
	data.uLightData.push_back(AnimFrame(sf::IntRect(5,9,24,60), sf::IntRect(32,0,16,19),.1f, 7, 0, 1, 0, 10));
	data.uLightData.push_back(AnimFrame(sf::IntRect(7,11,19,58), .1f));
	data.uLightData.push_back(AnimFrame(sf::IntRect(7,11,19,58), .1f));

	// Left
	data.LuLightData.push_back(AnimFrame(sf::IntRect(31,11,19,58), .1f));
	data.LuLightData.push_back(AnimFrame(sf::IntRect(31,11,19,58), .1f));
	data.LuLightData.push_back(AnimFrame(sf::IntRect(31,11,19,58), .1f));
	data.LuLightData.push_back(AnimFrame(sf::IntRect(28,9,24,60), sf::IntRect(0,3,25,59),.1f, 7, 0, 1, 0, 10));
	data.LuLightData.push_back(AnimFrame(sf::IntRect(28,9,24,60), sf::IntRect(0,0,26,34),.1f, 7, 0, 1, 0, 10));
	data.LuLightData.push_back(AnimFrame(sf::IntRect(28,9,24,60), sf::IntRect(9,0,16,19),.1f, 7, 0, 1, 0, 10));
	data.LuLightData.push_back(AnimFrame(sf::IntRect(31,11,19,58), .1f));
	data.LuLightData.push_back(AnimFrame(sf::IntRect(31,11,19,58), .1f));

	//Right
	data.dLightData.push_back(AnimFrame(sf::IntRect(27,0,22,63), .1f));
	data.dLightData.push_back(AnimFrame(sf::IntRect(27,0,22,63), .1f));
	data.dLightData.push_back(AnimFrame(sf::IntRect(27,0,22,63), .1f));
	data.dLightData.push_back(AnimFrame(sf::IntRect(29,7,20,56), sf::IntRect(17,43,46,20),.1f, 13, 1.f, 1, 120, 0));
	data.dLightData.push_back(AnimFrame(sf::IntRect(29,7,20,56), sf::IntRect(7,34,66,29),.1f, 13, 1.f, 1, 120, 0));
	data.dLightData.push_back(AnimFrame(sf::IntRect(29,7,20,56), sf::IntRect(7,34,66,29),.1f, 13, 1.f, 1, 120, 0));
	data.dLightData.push_back(AnimFrame(sf::IntRect(29,7,20,56), sf::IntRect(7,34,66,29),.1f, 13, 1.f, 1, 120, 0));
	data.dLightData.push_back(AnimFrame(sf::IntRect(29,7,20,56), sf::IntRect(7,34,66,29),.1f, 13, 1.f, 1, 120, 0));
	data.dLightOrigin = sf::Vector2f(40, 63);

	// Left
	data.LdLightData.push_back(AnimFrame(sf::IntRect(31,0,22,63), .1f));
	data.LdLightData.push_back(AnimFrame(sf::IntRect(31,0,22,63), .1f));
	data.LdLightData.push_back(AnimFrame(sf::IntRect(31,0,22,63), .1f));
	data.LdLightData.push_back(AnimFrame(sf::IntRect(31,7,20,56), sf::IntRect(17,43,46,20),.1f, 13, 1.f, 1, 120, 0));
	data.LdLightData.push_back(AnimFrame(sf::IntRect(31,7,20,56), sf::IntRect(7,34,66,29),.1f, 13, 1.f, 1, 120, 0));
	data.LdLightData.push_back(AnimFrame(sf::IntRect(31,7,20,56), sf::IntRect(7,34,66,29),.1f, 13, 1.f, 1, 120, 0));
	data.LdLightData.push_back(AnimFrame(sf::IntRect(31,7,20,56), sf::IntRect(7,34,66,29),.1f, 13, 1.f, 1, 120, 0));
	data.LdLightData.push_back(AnimFrame(sf::IntRect(31,7,20,56), sf::IntRect(7,34,66,29),.1f, 13, 1.f, 1, 120, 0));
	data.LdLightOrigin = sf::Vector2f(40, 63);

	return data;
}