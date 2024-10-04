#include "MonsterInMap.h"
#include "Map.h"
#include<iostream>
MonsterInMap::MonsterInMap(int row, int col) {
	GameMap[row][col] = 3;
}
