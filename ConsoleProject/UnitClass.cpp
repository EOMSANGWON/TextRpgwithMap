#include "UnitClass.h"

UnitClass::UnitClass()
{
	curState = new NormalState();
}



int UnitClass::Attack()
{
	std::cout << name << "�� ������ ����Ͽ����ϴ�." << std::endl;
	return attack;
}
void UnitClass::GotDamaged(int n) {
	int damage = n - GetDefence() / 2;
	currentHP = currentHP - damage;
	std::cout << name << "�� " << damage << "��ŭ�� �������� �Ծ����ϴ�." << endl;
}


void UnitClass::ShowStatus() {
	cout << "���� : " << level << "\n" << "���ݷ� : " << attack << "\n" << "���� : " << defence << "\n" << "HP : " << currentHP << " / " << maxHP << "\n" << "MP : " << currentMP << " / " << maxMP << "\n" << "����ġ : " << currentEXP << " / " << maxEXP << endl;
}