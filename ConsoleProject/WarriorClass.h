#pragma once
#include "UnitClass.h"
class WarriorClass : public UnitClass {

private:

	bool IsDrainBloodLearned = false;
	bool IsCounterAttackLearned = false;
	bool IsFinalCrushLearned = false;

public:
	// 기본스킬
	void DefenceWithShield();
	void DrainBlood(int n);

	// 특수스킬
	int Strike();
	int CounterAttack();
	int FinalCrush();

	WarriorClass();
	~WarriorClass();

	void LevelUp();
};