#include "StageDataTables.hpp"
#include "Stage.hpp"

// Initialize only the data for the state we want data for
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

// The data for the Training Stage
StageData trainingData()
{
	StageData data;

	data.hasBase = true;
	data.basePosition = sf::Vector2f(256, 235);

	data.platformLocations.push_back(sf::Vector2f(128, 128));

	return data;
}