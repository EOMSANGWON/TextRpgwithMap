#include "WarriorClass.h"
WarriorClass::WarriorClass() {
	name = "전사";
	level = 1;
	maxHP = 50;
	maxMP = 30;
	maxEXP = 10;
	currentHP = 50;
	currentMP = 30;
	currentEXP = 0;
	attack = 4;
	defence = 4;
	std::cout << "전사가 소환되었습니다." << std::endl;
	ShowStatus();

}
WarriorClass::~WarriorClass() {
	std::cout << "WarriorClass가 소멸되었습니다." << std::endl;
}
//기본스킬
//미구현 스킬
void WarriorClass::DefenceWithShield() {
	std::cout << "방패막기가 발동 되었습니다." << std::endl;
	srand(time(NULL));
	int randNumber = rand() % 10;
	if (randNumber > 3) return;
	else {
		//State 활용하기해서 피해 절감 구현하기.
		//SetCurState(new AvoidState());
		//1턴 후에 
		//SetCurState(new NormalState());
	}
}
//미구현 스킬
void WarriorClass::DrainBlood(int damage) {
	std::cout << "흡혈이 발동되었습니다." << std::endl;
	int amount = damage * 0.05;
	int tempHP = GetCurrentHP();
	SetCurrentHP(tempHP + amount);
}

//특수스킬
int WarriorClass::Strike() {
	std::cout << "스트라이크를 사용하였습니다." << std::endl;
	int MPafterSkill = GetCurrentMP() - 10;
	SetCurrentMP(MPafterSkill);
	return attack * 1.5;
}

//미구현 스킬
int WarriorClass::CounterAttack() {
	std::cout << "카운터어택을 사용하였습니다." << std::endl;
	int MPafterSkill = GetCurrentMP() - 20;
	SetCurrentMP(MPafterSkill);
	srand(time(NULL));
	int randNumber = rand() % 10;
	if (randNumber > 4) {
		//State 활용하여 회피 구현하기
		//SetCurState(new AvoidState());
		//1턴후에
		//SetCurState(new NormalState());
	}
	return attack * 2;
}
//관리자 스킬
int WarriorClass::FinalCrush() {
	std::cout << "[관리자]파이널크러쉬를 사용하였습니다." << std::endl;
	/*int MPafterSkill = GetCurrentMP() - 50;
	SetCurrentMP(MPafterSkill);*/
	return attack * 100; //몬스터 클레스에 GotDamaged 오버라이딩 필요
}

void WarriorClass::LevelUp() {
	std::cout << "\n***" << name << "의 레벨이 올랐습니다.***" << endl;
	level++;
	maxHP += 5;
	maxMP += 3;
	//maxEXP는 main함수에서 변환
	currentHP = maxHP;
	currentMP = maxMP;
	currentEXP = currentEXP - maxEXP;
	attack += 2;
	defence += 2;
}
