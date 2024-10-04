#pragma once
#include<iostream>

//��� ������� ?
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
		std::cout << this << "�� ���Ͽ� �������ϴ�." << std::endl;
		//SetIsSturnt = true;
	};
	void ExitState()override {
		std::cout << this << "�� ���Ͽ��� Ǯ�������ϴ�." << std::endl;
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