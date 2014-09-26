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
	std::vector<AnimFrame> runData;
	std::vector<AnimFrame> guardData;
};

CharData	initializeCharData(Fighter::Type);

CharData	kenshiroData();

#endif // CharacterDataTable.hpp