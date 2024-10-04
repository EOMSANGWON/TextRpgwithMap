#include "ItemList.h"

std::string ItemList::GetName() { return name; }
int ItemList::GetBuyCost() { return buyCost; }
void ItemList::SetBuyCost(int price) { buyCost = price; }
int ItemList::GetSellCost() { return sellCost; }
void ItemList::SetSellCost(int price) { sellCost = price; }
int ItemList::GetItemOrder() { return itemOrder; }
void ItemList::SetItemOrder(int order) { itemOrder = order; }


void WeaponAndArmor::SeeInfo() {
	std::cout << "장비명 : " << name << " , 공격력 : " << Atk << " , 방어력 : " << Def << " , 제한레벨 : " << LimitedLv << std::endl;
};

void WeaponAndArmor::SeeAtk() {
	std::cout << "장비 공격력 : " << Atk << std::endl;
};

void WeaponAndArmor::SeeDef() {
	std::cout << "장비 방어력 : " << Def << std::endl;
};

void WeaponAndArmor::SeeLimitedLv() {
	std::cout << "장비 레벨 제한 : " << LimitedLv << std::endl;
}
int WeaponAndArmor::GetAtk() { return Atk; }
int WeaponAndArmor::GetDef() { return Def; }
int WeaponAndArmor::GetLimotedLv() { return LimitedLv; }
int WeaponAndArmor::GetItemCode() { return ItemCode; }

void Potion::SeeInfo() {
	std::cout << "아이템명 : " << name << ", HP 회복량 :" << HP << " , MP 회복량 : " << MP << std::endl;
}

void Potion::SeeHP() {
	std::cout << "HP 회복량 : " << HP << std::endl;
}

void Potion::SeeMP() {
	std::cout << "MP 회복량 : " << MP << std::endl;
}

int Potion::GetHP() { return HP; }
int Potion::GetMP() { return MP; }