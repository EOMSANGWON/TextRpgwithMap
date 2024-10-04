#include "MonsterSlime.h"
SlimeClass::SlimeClass(int SlimeLevel) {
	name = "슬라임";
	level = SlimeLevel; //레벨 6 ~ 10
	maxHP = 30 + 2 * level;
	maxMP = 0;
	maxEXP = 10 + 2 * level;
	currentHP = maxHP;
	currentMP = maxMP;
	currentEXP = 10 + 2 * level;
	attack = 5 + level;
	defence = 5 + level;
	std::cout << "Lv " << level << " 슬라임이 출현했습니다.전투가 시작됩니다." << std::endl;

}
