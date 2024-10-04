#include "UnitClass.h"

UnitClass::UnitClass()
{
	curState = new NormalState();
}



int UnitClass::Attack()
{
	std::cout << name << "가 어택을 사용하였습니다." << std::endl;
	return attack;
}
void UnitClass::GotDamaged(int n) {
	int damage = n - GetDefence() / 2;
	currentHP = currentHP - damage;
	std::cout << name << "는 " << damage << "만큼의 데미지를 입었습니다." << endl;
}


void UnitClass::ShowStatus() {
	cout << "레벨 : " << level << "\n" << "공격력 : " << attack << "\n" << "방어력 : " << defence << "\n" << "HP : " << currentHP << " / " << maxHP << "\n" << "MP : " << currentMP << " / " << maxMP << "\n" << "경험치 : " << currentEXP << " / " << maxEXP << endl;
}