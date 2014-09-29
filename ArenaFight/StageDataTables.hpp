/*
* StageDataTables
* Contains all the data needed for each of the stages
* By having this, we do not need a class for each stage
*/

#ifndef _STAGEDATATABLE
#define _STAGEDATATABLE

#include "Stage.hpp"

#include <SFML\System\Vector2.hpp>

#include <vector>

struct StageData
{
	bool						hasBase;
	sf::Vector2f				basePosition;

	std::vector<sf::Vector2f>	platformLocations;
};

StageData initializeStageData(Stage::Type);

StageData trainingData();

#endif // StageDataTable.hpp