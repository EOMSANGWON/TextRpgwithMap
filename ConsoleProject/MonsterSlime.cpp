#include "MonsterSlime.h"
SlimeClass::SlimeClass(int SlimeLevel) {
	name = "������";
	level = SlimeLevel; //���� 6 ~ 10
	maxHP = 30 + 2 * level;
	maxMP = 0;
	maxEXP = 10 + 2 * level;
	currentHP = maxHP;
	currentMP = maxMP;
	currentEXP = 10 + 2 * level;
	attack = 5 + level;
	defence = 5 + level;
	std::cout << "Lv " << level << " �������� �����߽��ϴ�.������ ���۵˴ϴ�." << std::endl;

}
