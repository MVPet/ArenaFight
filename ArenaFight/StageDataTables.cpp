#include "StageDataTables.hpp"
#include "Stage.hpp"

StageData initializeStageData(Stage::Type id)
{
	switch (id)
	{
	case Stage::Training:
		return trainingData();

	default:
		return StageData();
	}
}

StageData trainingData()
{
	StageData data;

	data.hasBase = true;
	data.basePosition = sf::Vector2f(256, 235);

	data.platformLocations.push_back(sf::Vector2f(128, 128));

	return data;
}