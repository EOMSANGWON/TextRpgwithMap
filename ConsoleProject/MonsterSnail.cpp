#include "MonsterSnail.h"
SnailClass::SnailClass(int SnailLevel) {
	name = "달팽이";
	level = SnailLevel; // 레벨 1 ~ 5
	maxHP = 10 + 2 * level;
	maxMP = 0;
	maxEXP = 3 + level;
	currentHP = maxHP;
	currentMP = maxMP;
	currentEXP = 3 + level;
	attack = 3 + level;
	defence = 1;
	std::cout << "Lv " << level << " 달팽이가 출현했습니다.전투가 시작됩니다." << std::endl;
}

