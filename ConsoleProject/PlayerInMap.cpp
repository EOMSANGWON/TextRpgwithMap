#include "PlayerInMap.h"
#include "map.h"
#include<iostream>
#include<conio.h>

PlayerInMap::PlayerInMap() { GameMap[raw][col] = 2; };

void PlayerInMap::PlayerMove() {
	while (true) {

		bool isBattle = false;

		input = _getch();
		switch (input) {
		case 'w':
		{
			if (GameMap[raw - 1][col] == 0) {
				GameMap[raw][col] = 0;
				GameMap[raw -= 1][col] = 2;
			}
			else if (GameMap[raw - 1][col] == 3) {
				GameMap[raw][col] = 0;
				GameMap[raw -= 1][col] = 2;
				isBattle = true;
			}
			break;
		}

		case 's':
		{
			if (GameMap[raw + 1][col] == 0) {
				GameMap[raw][col] = 0;
				GameMap[raw += 1][col] = 2;
			}
			else if (GameMap[raw + 1][col] == 3) {
				GameMap[raw][col] = 0;
				GameMap[raw += 1][col] = 2;
				isBattle = true;
			}
			break;
		}

		case 'a':
		{
			if (GameMap[raw][col - 1] == 0) {
				GameMap[raw][col] = 0;
				GameMap[raw][col -= 1] = 2;
			}
			else if (GameMap[raw][col - 1] == 3) {
				GameMap[raw][col] = 0;
				GameMap[raw][col -= 1] = 2;
				isBattle = true;
			}
			break;
		}

		case 'd':
		{
			if (GameMap[raw][col + 1] == 0) {
				GameMap[raw][col] = 0;
				GameMap[raw][col += 1] = 2;
			}
			else if (GameMap[raw][col + 1] == 3) {
				GameMap[raw][col] = 0;
				GameMap[raw][col += 1] = 2;
				isBattle = true;
			}
			break;
		}
		}
		system("cls");
		ShownMap();
		if (isBattle == true)	break;
	}
}
