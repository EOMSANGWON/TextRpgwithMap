#include "MonsterWolf.h"
WolfClass::WolfClass(int WolfLevel) {
	name = "늑대";
	level = WolfLevel; // 레벨 16 ~ 20
	maxHP = 80 + 4 * level;
	maxMP = 0;
	maxEXP = 40 + 4 * level;
	currentHP = maxHP;
	currentMP = maxMP;
	currentEXP = 40 + 4 * level;
	attack = 20 + 2 * level;
	defence = 20 + 2 * level;
	std::cout << "Lv " << level << " 늑대가 출현했습니다.전투가 시작됩니다." << std::endl;
}

