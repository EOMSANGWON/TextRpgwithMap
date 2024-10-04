#pragma once
#include "StateClass.h"


using namespace std;

class UnitClass abstract
{
	IState* curState;

protected:
	string name = "";
	int level = 0;
	int maxHP = 0;
	int maxMP = 0;
	int maxEXP = 0;
	int currentHP = 0;
	int currentMP = 0;
	int currentEXP = 0;
	int attack = 0;
	int defence = 0;

	bool isSturnt = false;
	bool isAvoiding = false;
	int damage = 0;

public:
	string GetName() { return name; }
	int GetLevel() { return level; }
	int GetMaxHP() { return maxHP; }
	void SetMaxHP(int n) { maxHP = n; }
	int GetMaxMP() { return maxMP; }
	void SetMaxMP(int n) { maxMP = n; }
	int GetMaxEXP() { return maxEXP; }
	void SetMaxEXP(int n) { maxEXP = n; }
	int GetCurrentHP() { return currentHP; }
	void SetCurrentHP(int n) { currentHP = n; }
	int GetCurrentMP() { return currentMP; }
	void SetCurrentMP(int n) { currentMP = n; }
	int GetCurrentEXP() { return currentEXP; }
	void SetCurrentEXP(int n) { currentEXP = n; }
	int GetAttack() { return attack; }
	void SetAttack(int n) { attack = n; }
	int GetDefence() { return defence; }
	void SetDefence(int n) { defence = n; }
	int GetDamage() { return damage; }
	void SetDamge(int n) { damage = n; }

	bool GetIsSturnt() { return isSturnt; }
	void SetIsSturnt(bool b) { isSturnt = b; }
	bool GetIsAvoiding() { return isAvoiding; }
	void SetIsAvoiding(bool b) { isAvoiding = b; }

	int Attack();
	void GotDamaged(int n); // 가상클래스 

	void ShowStatus();


	UnitClass();

	//State  -> 대기
	/*
	void SetCurState(IState* s) {
		curState->ExitState();
		curState = s;
		curState->EnterState();
	};

	void ExitState() {
		curState->ExitState();
	};
	*/
};
