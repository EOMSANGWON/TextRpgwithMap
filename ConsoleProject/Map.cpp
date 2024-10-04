#include "Map.h"
#include<iostream>

int GameMap[20][20];

void ShownMap() {

	for (int i = 0; i < 20; i++) {
		GameMap[0][i] = 1;
		GameMap[i][0] = 1;
		GameMap[i][19] = 1;
		GameMap[19][i] = 1;
	}

	for (int i = 0; i < 20; i++) {
		for (int k = 0; k < 20; k++) {
			switch (GameMap[i][k]) {
			case 0: std::cout << "  ";
				break;
			case 1: std::cout << "¡á";
				break;
			case 2: std::cout << "¡Ú";
				break;
			case 3: std::cout << "¡Ü";
				break;
			case 4: std::cout << "¡Ý";
				break;
			case 5: std::cout << " ";
				break;
			}

		}
		std::cout << std::endl;
	}
};