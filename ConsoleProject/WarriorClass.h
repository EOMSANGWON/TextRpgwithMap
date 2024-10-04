#pragma once
#include "UnitClass.h"
class WarriorClass : public UnitClass {

private:

	bool IsDrainBloodLearned = false;
	bool IsCounterAttackLearned = false;
	bool IsFinalCrushLearned = false;

public:
	// �⺻��ų
	void DefenceWithShield();
	void DrainBlood(int n);

	// Ư����ų
	int Strike();
	int CounterAttack();
	int FinalCrush();

	WarriorClass();
	~WarriorClass();

	void LevelUp();
};