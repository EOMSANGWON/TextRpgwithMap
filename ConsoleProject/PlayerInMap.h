#pragma once
class PlayerInMap
{

private:
	int raw = 1;
	int col = 1;

public:
	int input = 0;
	PlayerInMap();
	//플레이어 이동 함수
	void PlayerMove();

};
