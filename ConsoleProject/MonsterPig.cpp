#include "MonsterPig.h"
PigClass::PigClass(int PigLevel) {
	name = "����";
	level = PigLevel; // ���� 11 ~ 15
	maxHP = 50 + 3 * level;
	maxMP = 0;
	maxEXP = 20 + 3 * level;
	currentHP = maxHP;
	currentMP = maxMP;
	currentEXP = 20 + 3 * level;
	attack = 15 + 2 * level;
	defence = 15 + 1 * level;
	std::cout << "Lv " << level << " ������ �����߽��ϴ�.������ ���۵˴ϴ�." << std::endl;
}

