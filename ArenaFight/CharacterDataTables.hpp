/*
* CharacterDataTables.hpp
* The data for everything ebout each charcter is stored here
* This allows us to have a dynamic Fighter clas sinstead of a class for each character
*/

#ifndef _CHARACTERDATATABLE
#define _CHARACTERDATATABLE

#include "Fighter.hpp"

#include <SFML\System\Vector2.hpp>

#include <vector>

struct CharData
{
	int health;
	int weight;

	std::vector<AnimFrame> standData;
	sf::Vector2f standOrigin;

	std::vector<AnimFrame> runData;
	sf::Vector2f runOrigin;

	std::vector<AnimFrame> fallData;
	sf::Vector2f fallOrigin;

	std::vector<AnimFrame> landingData;
	sf::Vector2f landingOrigin;

	std::vector<AnimFrame> hurtData;
	sf::Vector2f hurtOrigin;

	std::vector<AnimFrame> guardData;
	sf::Vector2f guardOrigin;

	std::vector<AnimFrame> nLightData;
	sf::Vector2f nLightOrigin;

	std::vector<AnimFrame> sLightData;
	sf::Vector2f sLightOrigin;

	std::vector<AnimFrame> uLightData;
	sf::Vector2f uLightOrigin;

	std::vector<AnimFrame> dLightData;
	sf::Vector2f dLightOrigin;

	//Left facing data---------------------------------------------------------------------------------------------
	std::vector<AnimFrame> LstandData;
	sf::Vector2f LstandOrigin;

	std::vector<AnimFrame> LrunData;
	sf::Vector2f LrunOrigin;

	std::vector<AnimFrame> LfallData;
	sf::Vector2f LfallOrigin;

	std::vector<AnimFrame> LlandingData;
	sf::Vector2f LlandingOrigin;

	std::vector<AnimFrame> LhurtData;
	sf::Vector2f LhurtOrigin;

	std::vector<AnimFrame> LguardData;
	sf::Vector2f LguardOrigin;

	std::vector<AnimFrame> LnLightData;
	sf::Vector2f LnLightOrigin;

	std::vector<AnimFrame> LsLightData;
	sf::Vector2f LsLightOrigin;

	std::vector<AnimFrame> LuLightData;
	sf::Vector2f LuLightOrigin;

	std::vector<AnimFrame> LdLightData;
	sf::Vector2f LdLightOrigin;
};

CharData	initializeCharData(Fighter::Type);

CharData	kenshiroData();

#endif // CharacterDataTable.hpp