#pragma once
#include<iostream>


class ItemList
{
public:
	ItemList(const std::string& n, int b, int s) : itemOrder(0), name(n), buyCost(b), sellCost(s) {};
	std::string GetName();
	int GetBuyCost();
	void SetBuyCost(int price);
	int GetSellCost();
	void SetSellCost(int price);
	int GetItemOrder();
	void SetItemOrder(int order);

protected:
	std::string name;
	int itemOrder;
	int buyCost;
	int sellCost;

};

class WeaponAndArmor : public ItemList
{
public:
	WeaponAndArmor(const std::string& n, int b, int s, int Atk, int Def, int level, int ItemCode) : ItemList(n, b, s), Atk(Atk), Def(Def), LimitedLv(level), ItemCode(ItemCode) {}; // Item class 생성자에 들어가는 매개변수임.

	void SeeInfo();
	void SeeAtk();
	int GetAtk();
	void SeeDef();
	int GetDef();
	void SeeLimitedLv();
	int GetLimotedLv();
	int GetItemCode();

protected:
	int Atk;
	int Def;
	int LimitedLv;
	int ItemCode;
};

class Potion : public ItemList
{
public:
	Potion(const std::string& n, int b, int s, int HP, int MP) : ItemList(n, b, s), HP(HP), MP(MP) {};
	void SeeInfo();
	void SeeHP();
	void SeeMP();
	int GetHP();
	int GetMP();

protected:
	int HP;
	int MP;

};
