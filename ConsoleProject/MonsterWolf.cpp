#include "MonsterWolf.h"
WolfClass::WolfClass(int WolfLevel) {
	name = "����";
	level = WolfLevel; // ���� 16 ~ 20
	maxHP = 80 + 4 * level;
	maxMP = 0;
	maxEXP = 40 + 4 * level;
	currentHP = maxHP;
	currentMP = maxMP;
	currentEXP = 40 + 4 * level;
	attack = 20 + 2 * level;
	defence = 20 + 2 * level;
	std::cout << "Lv " << level << " ���밡 �����߽��ϴ�.������ ���۵˴ϴ�." << std::endl;
}

