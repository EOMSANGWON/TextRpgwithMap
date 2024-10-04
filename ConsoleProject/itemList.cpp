#include "ItemList.h"

std::string ItemList::GetName() { return name; }
int ItemList::GetBuyCost() { return buyCost; }
void ItemList::SetBuyCost(int price) { buyCost = price; }
int ItemList::GetSellCost() { return sellCost; }
void ItemList::SetSellCost(int price) { sellCost = price; }
int ItemList::GetItemOrder() { return itemOrder; }
void ItemList::SetItemOrder(int order) { itemOrder = order; }


void WeaponAndArmor::SeeInfo() {
	std::cout << "���� : " << name << " , ���ݷ� : " << Atk << " , ���� : " << Def << " , ���ѷ��� : " << LimitedLv << std::endl;
};

void WeaponAndArmor::SeeAtk() {
	std::cout << "��� ���ݷ� : " << Atk << std::endl;
};

void WeaponAndArmor::SeeDef() {
	std::cout << "��� ���� : " << Def << std::endl;
};

void WeaponAndArmor::SeeLimitedLv() {
	std::cout << "��� ���� ���� : " << LimitedLv << std::endl;
}
int WeaponAndArmor::GetAtk() { return Atk; }
int WeaponAndArmor::GetDef() { return Def; }
int WeaponAndArmor::GetLimotedLv() { return LimitedLv; }
int WeaponAndArmor::GetItemCode() { return ItemCode; }

void Potion::SeeInfo() {
	std::cout << "�����۸� : " << name << ", HP ȸ���� :" << HP << " , MP ȸ���� : " << MP << std::endl;
}

void Potion::SeeHP() {
	std::cout << "HP ȸ���� : " << HP << std::endl;
}

void Potion::SeeMP() {
	std::cout << "MP ȸ���� : " << MP << std::endl;
}

int Potion::GetHP() { return HP; }
int Potion::GetMP() { return MP; }