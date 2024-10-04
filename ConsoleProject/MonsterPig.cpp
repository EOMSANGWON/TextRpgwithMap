#include "MonsterPig.h"
PigClass::PigClass(int PigLevel) {
	name = "돼지";
	level = PigLevel; // 레벨 11 ~ 15
	maxHP = 50 + 3 * level;
	maxMP = 0;
	maxEXP = 20 + 3 * level;
	currentHP = maxHP;
	currentMP = maxMP;
	currentEXP = 20 + 3 * level;
	attack = 15 + 2 * level;
	defence = 15 + 1 * level;
	std::cout << "Lv " << level << " 돼지가 출현했습니다.전투가 시작됩니다." << std::endl;
}

