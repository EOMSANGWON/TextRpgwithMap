#include "MonsterSnail.h"
SnailClass::SnailClass(int SnailLevel) {
	name = "������";
	level = SnailLevel; // ���� 1 ~ 5
	maxHP = 10 + 2 * level;
	maxMP = 0;
	maxEXP = 3 + level;
	currentHP = maxHP;
	currentMP = maxMP;
	currentEXP = 3 + level;
	attack = 3 + level;
	defence = 1;
	std::cout << "Lv " << level << " �����̰� �����߽��ϴ�.������ ���۵˴ϴ�." << std::endl;
}

