#include "WarriorClass.h"
WarriorClass::WarriorClass() {
	name = "����";
	level = 1;
	maxHP = 50;
	maxMP = 30;
	maxEXP = 10;
	currentHP = 50;
	currentMP = 30;
	currentEXP = 0;
	attack = 4;
	defence = 4;
	std::cout << "���簡 ��ȯ�Ǿ����ϴ�." << std::endl;
	ShowStatus();

}
WarriorClass::~WarriorClass() {
	std::cout << "WarriorClass�� �Ҹ�Ǿ����ϴ�." << std::endl;
}
//�⺻��ų
//�̱��� ��ų
void WarriorClass::DefenceWithShield() {
	std::cout << "���и��Ⱑ �ߵ� �Ǿ����ϴ�." << std::endl;
	srand(time(NULL));
	int randNumber = rand() % 10;
	if (randNumber > 3) return;
	else {
		//State Ȱ���ϱ��ؼ� ���� ���� �����ϱ�.
		//SetCurState(new AvoidState());
		//1�� �Ŀ� 
		//SetCurState(new NormalState());
	}
}
//�̱��� ��ų
void WarriorClass::DrainBlood(int damage) {
	std::cout << "������ �ߵ��Ǿ����ϴ�." << std::endl;
	int amount = damage * 0.05;
	int tempHP = GetCurrentHP();
	SetCurrentHP(tempHP + amount);
}

//Ư����ų
int WarriorClass::Strike() {
	std::cout << "��Ʈ����ũ�� ����Ͽ����ϴ�." << std::endl;
	int MPafterSkill = GetCurrentMP() - 10;
	SetCurrentMP(MPafterSkill);
	return attack * 1.5;
}

//�̱��� ��ų
int WarriorClass::CounterAttack() {
	std::cout << "ī���;����� ����Ͽ����ϴ�." << std::endl;
	int MPafterSkill = GetCurrentMP() - 20;
	SetCurrentMP(MPafterSkill);
	srand(time(NULL));
	int randNumber = rand() % 10;
	if (randNumber > 4) {
		//State Ȱ���Ͽ� ȸ�� �����ϱ�
		//SetCurState(new AvoidState());
		//1���Ŀ�
		//SetCurState(new NormalState());
	}
	return attack * 2;
}
//������ ��ų
int WarriorClass::FinalCrush() {
	std::cout << "[������]���̳�ũ������ ����Ͽ����ϴ�." << std::endl;
	/*int MPafterSkill = GetCurrentMP() - 50;
	SetCurrentMP(MPafterSkill);*/
	return attack * 100; //���� Ŭ������ GotDamaged �������̵� �ʿ�
}

void WarriorClass::LevelUp() {
	std::cout << "\n***" << name << "�� ������ �ö����ϴ�.***" << endl;
	level++;
	maxHP += 5;
	maxMP += 3;
	//maxEXP�� main�Լ����� ��ȯ
	currentHP = maxHP;
	currentMP = maxMP;
	currentEXP = currentEXP - maxEXP;
	attack += 2;
	defence += 2;
}
