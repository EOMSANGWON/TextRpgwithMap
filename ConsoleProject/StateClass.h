#pragma once
#include<iostream>

//어떻게 써야할지 ?
enum class STATE
{
	NORMAL,
	STURN,
	AVOID
};

class IState
{
public:
	virtual void EnterState() = 0;
	virtual void ExitState() = 0;
};

//State class
class NormalState : public IState
{
public:
	void EnterState()override {
		//SetIsSturnt = false;
		//SetIsAvoiding = false;
	}
	void ExitState()override {}

};

class SturnState : public IState
{
public:
	void EnterState()override {
		std::cout << this << "가 스턴에 빠졌습니다." << std::endl;
		//SetIsSturnt = true;
	};
	void ExitState()override {
		std::cout << this << "가 스턴에서 풀려났습니다." << std::endl;
	};
};

class AvoidState : public IState
{
public:
	void EnterState()override {
		//SetIsAvoiding = true;
	}
	void ExitState()override {}
};