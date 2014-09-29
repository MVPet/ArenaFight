/*
* BattleData.hpp
* The data for our battle
* Tells the program what characters and stage were selected
*/

#ifndef _BATTLEDATA
#define _BATTLEDATA

#include "Stage.hpp"
#include "Fighter.hpp"

static Stage::Type selectedStage;

static Fighter::Type selectedFighters [4];

#endif // BattleData.hpp