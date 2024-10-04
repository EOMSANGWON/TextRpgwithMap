#pragma once
#include"WarriorClass.h"
#include<map>
#include"Map.h"
#include"PlayerInMap.h"
#include"MonsterInMap.h"
#include"MonsterSnail.h"
#include"MonsterSlime.h"
#include"MonsterPig.h"
#include"MonsterWolf.h"
#include"ItemList.h"
#include<iostream>
#include<vector>
#include<Windows.h> // system(cls), system(pause)
#include<cstdlib>

std::map<int, int>ExpMap;
int haveMoney = 0;
int insertMonster;
int stageNumber = 1;
int MapNumber = 0;
int unEquippedPoint;

bool SomthingShown = true;
bool isWeapon = false;
bool isMPPotion = false;
bool WeaponEquipped = false;
bool ArmorEquipped = false;
bool ShieldEquipped = false;


vector<WeaponAndArmor>WeaponAndArmorList;
vector<Potion>PotionList;

vector<Potion>PotionInventory;
vector<WeaponAndArmor>EquipInventory;

//착용 아이템
vector<WeaponAndArmor>EquippedWeapon;
vector<WeaponAndArmor>EquippedArmor;
vector<WeaponAndArmor>EquippedShield;

void ShowInventory();
void ShowEquippedItem();
void Battle(int insertMonster, WarriorClass* warrior);
void DropItem();

int UsePotion(int itemNumber);
int Equip(int itemNumber);
int equipInvenSize = EquipInventory.size();
int potionInvenSize = PotionInventory.size();


int main()
{
	//경험치 맵
	ExpMap.insert(std::make_pair(2, 15));
	ExpMap.insert(std::make_pair(3, 20));
	ExpMap.insert(std::make_pair(4, 25));
	ExpMap.insert(std::make_pair(5, 50));
	ExpMap.insert(std::make_pair(6, 60));
	ExpMap.insert(std::make_pair(7, 70));
	ExpMap.insert(std::make_pair(8, 80));
	ExpMap.insert(std::make_pair(9, 90));
	ExpMap.insert(std::make_pair(10, 150));
	ExpMap.insert(std::make_pair(11, 170));
	ExpMap.insert(std::make_pair(12, 190));
	ExpMap.insert(std::make_pair(13, 210));
	ExpMap.insert(std::make_pair(14, 230));
	ExpMap.insert(std::make_pair(15, 300));
	ExpMap.insert(std::make_pair(16, 350));
	ExpMap.insert(std::make_pair(17, 400));
	ExpMap.insert(std::make_pair(18, 450));
	ExpMap.insert(std::make_pair(19, 500));
	ExpMap.insert(std::make_pair(20, 0));

	// 벡터 : 아이템
	WeaponAndArmorList.push_back(WeaponAndArmor("목검", 1000, 200, 2, 0, 1, 0)); //0 
	WeaponAndArmorList.push_back(WeaponAndArmor("청동검", 3000, 600, 10, 0, 10, 1)); //1
	WeaponAndArmorList.push_back(WeaponAndArmor("롱소드", 5000, 1000, 20, 0, 15, 2)); //2
	WeaponAndArmorList.push_back(WeaponAndArmor("초급자용 갑옷", 800, 160, 0, 1, 1, 3)); //3
	WeaponAndArmorList.push_back(WeaponAndArmor("중급자용 갑옷", 2000, 400, 0, 5, 10, 4)); //4
	WeaponAndArmorList.push_back(WeaponAndArmor("고급자용 갑옷", 4000, 800, 0, 10, 15, 5)); //5
	WeaponAndArmorList.push_back(WeaponAndArmor("초급자용 방패", 800, 160, 0, 1, 1, 6)); //6
	WeaponAndArmorList.push_back(WeaponAndArmor("중급자용 방패", 2000, 400, 0, 5, 10, 7)); //7
	WeaponAndArmorList.push_back(WeaponAndArmor("고급자용 방패", 4000, 800, 0, 10, 15, 8)); //8

	PotionList.push_back(Potion("HP물약(소)", 50, 10, 30, 0)); //0
	PotionList.push_back(Potion("HP물약(중)", 100, 20, 50, 0)); //1
	PotionList.push_back(Potion("HP물약(대)", 200, 40, 70, 0)); //2
	PotionList.push_back(Potion("MP물약(소)", 70, 14, 0, 30)); //3
	PotionList.push_back(Potion("MP물약(중)", 150, 30, 0, 50)); //4
	PotionList.push_back(Potion("MP물약(대)", 280, 64, 0, 70)); //5



	WarriorClass* warrior = new WarriorClass();

	while (true) {

		int gameMenu;
		int selectItem;
		int unEquipItem;

		bool isMon1Dead = false;
		bool isMon2Dead = false;

		srand(time(NULL));
		int rand1 = rand() % 14 + 4;
		int rand2 = rand() % 14 + 4;
		int rand3 = rand() % 15 + 3;
		int rand4 = rand() % 15 + 3;

		system("pause");
		system("cls");
		std::cout << "현재 Stage " << stageNumber << " 입니다.\nStage 가 높아지면 맵이 변경됩니다.\n1 ~ 5 : 달팽이 마을 // 6 ~ 10 : 슬라임 숲 // 11 ~ 15 : 돼지 해변 // 16 ~ 20 : 금지된 숲\n\n======================================================================================================\n1. 여행을 시작합니다.\n2. 캐릭터 상태를 확인합니다.\n3. 인벤토리를 확인합니다.\n\n======================================================================================================\n입력값 : ";
		std::cin >> gameMenu;
		std::cout << "======================================================================================================" << std::endl;
		switch (gameMenu) {
		case 1:
			break;
		case 2:
			warrior->ShowStatus();
			std::cout << std::endl;
			ShowEquippedItem();
			std::cout << "숫자를 입력하여 장비를 해제할 수 있습니다.\n\n1. 무기해제\n2. 갑옷해제\n3. 방패해제\n4. 메뉴로 가기\n\n======================================================================================================\n입력값 : ";
			std::cin >> unEquipItem;
			std::cout << "======================================================================================================" << std::endl;
			switch (unEquipItem) {
			case 1: {
				std::string UnEquippedWeapon = EquippedWeapon[0].GetName();
				unEquippedPoint = EquippedWeapon[0].GetAtk();
				EquipInventory.push_back(EquippedWeapon[0]);
				warrior->SetAttack(warrior->GetAttack() - unEquippedPoint);
				EquippedWeapon.pop_back();
				std::cout << UnEquippedWeapon << "를 해제하였습니다." << std::endl;
				WeaponEquipped = false;
				break;
			}
			case 2: {
				std::string UnEquippedArmor = EquippedArmor[0].GetName();
				unEquippedPoint = EquippedArmor[0].GetDef();
				EquipInventory.push_back(EquippedArmor[0]);
				warrior->SetDefence(warrior->GetDefence() - unEquippedPoint);
				EquippedArmor.pop_back();
				std::cout << UnEquippedArmor << "을 해제하였습니다." << std::endl;
				ArmorEquipped = false;
				break;
			}
			case 3: {
				std::string UnEquippedShield = EquippedShield[0].GetName();
				unEquippedPoint = EquippedShield[0].GetDef();
				EquipInventory.push_back(EquippedShield[0]);
				warrior->SetDefence(warrior->GetDefence() - unEquippedPoint);
				EquippedShield.pop_back();
				std::cout << UnEquippedShield << "를 해제하였습니다." << std::endl;
				ShieldEquipped = false;
				break;
			}
			case 4:
				break;
			}
			continue;
		case 3:
			ShowInventory();
			if (SomthingShown) {
				std::cout << "아이템 번호를 누르면 착용하거나 사용할 수 있습니다.\n\n==================================================== \n입력값 : ";
				std::cin >> selectItem;
				std::cout << "=======================================================================================================" << std::endl;
				int powerPoint = Equip(selectItem);
				//포션일때
				if (powerPoint == -1) {
					int recoveryPoint = UsePotion(selectItem);
					if (isMPPotion == false) {
						if (warrior->GetMaxHP() > warrior->GetCurrentHP() + recoveryPoint) {
							warrior->SetCurrentHP(warrior->GetCurrentHP() + recoveryPoint);
							std::cout << "HP가 " << recoveryPoint << " 증가하였습니다." << std::endl;
						}
						else {
							int gap = warrior->GetMaxHP() - warrior->GetCurrentHP();
							warrior->SetCurrentHP(warrior->GetMaxHP());
							std::cout << "HP가 " << gap << " 증가하였습니다." << std::endl;
						}
					}
					else {
						if (warrior->GetMaxMP() > warrior->GetCurrentMP() + recoveryPoint) {
							warrior->SetCurrentMP(warrior->GetCurrentMP() + recoveryPoint);
							std::cout << "MP가 " << recoveryPoint << " 증가하였습니다." << std::endl;
						}
						else {
							int gap = warrior->GetMaxMP() - warrior->GetCurrentMP();
							warrior->SetCurrentMP(warrior->GetMaxMP());
							std::cout << "MP가 " << gap << " 증가하였습니다." << std::endl;
						}
					}
					warrior->ShowStatus();
					std::cout << std::endl;
					continue;
				}
				//무기일때
				else {
					if (isWeapon == true)warrior->SetAttack(warrior->GetAttack() + powerPoint);
					else warrior->SetDefence(warrior->GetDefence() + powerPoint);
					warrior->ShowStatus();
					std::cout << std::endl;
					continue;
				}
			}
			else continue;

			//case 4:
			//	//상점
			//	continue;
		};

		PlayerInMap* player = new PlayerInMap();
		MonsterInMap* mon1 = new MonsterInMap(rand1, rand2);
		MonsterInMap* mon2 = new MonsterInMap(rand3, rand4);


		while (true) {
			std::cout << "여행을 시작합니다." << std::endl;
			system("pause");
			system("cls");
			ShownMap();
			player->PlayerMove();
			system("cls");
			//전투시작
			std::cout << "몬스터와 만났습니다.\n " << std::endl;

			if (stageNumber <= 5) MapNumber = 0;
			else if (stageNumber <= 10) MapNumber = 1;
			else if (stageNumber <= 15) MapNumber = 2;
			else if (stageNumber > 15) MapNumber = 3;

			Battle(MapNumber, warrior);

			if (GameMap[rand1][rand2] == 2) {
				delete mon1;
				mon1 = nullptr;
				isMon1Dead = true;
			}
			if (GameMap[rand3][rand4] == 2) {
				delete mon2;
				mon2 = nullptr;
				isMon2Dead = true;
			}
			if (isMon1Dead && isMon2Dead) {
				std::cout << "해당 스테이지를 클리어 하였습니다. 다음스테이지로 넘어갑니다." << std::endl;
				GameMap[rand1][rand2] = 0;
				GameMap[rand3][rand4] = 0;
				stageNumber++;
				delete player;
				player = nullptr;
				break;
			}
		}
	}
}

enum MonsterList {
	Snail, // 0
	Slime,
	Pig,
	Wolf
};

enum PlayerActingList {
	공격하기 = 1,
	아이템사용,
	상태보기
};

enum SkillList {
	ATTACK = 1,
	STRIKE,
	COUNTERATTACK,
	FINALCRUSH
};

void Battle(int MapNumber, WarriorClass* warrior)
{

	int playerActing;
	int skillNumber;
	UnitClass* Monster = nullptr;
	int tempdam;
	srand(time(NULL));
	int SnailLvRandom = rand() % 5 + 1;
	int SlimeLvRandom = rand() % 5 + 6;
	int PigLvRandom = rand() % 5 + 11;
	int WolfLvRandom = rand() % 5 + 16;
	int battleRound = 1;
	int selectItem;

	switch (MapNumber) {
	case Snail: {
		Monster = new SnailClass(SnailLvRandom);
		break;
	}
	case Slime: {
		Monster = new SlimeClass(SlimeLvRandom);
		break;
	}
	case Pig: {
		Monster = new PigClass(PigLvRandom);
		break;
	}
	case Wolf: {
		Monster = new WolfClass(WolfLvRandom);
		break;
	}
	}

	while (true) {

		system("pause");
		system("cls");

		std::cout << "<" << battleRound << " 라운드> 플레이어 턴입니다.행동을 고르세요.\n1.공격하기\n2.아이템사용\n3.상태보기\n\n=================================================== \n입력값 : ";
		std::cin >> playerActing;
		std::cout << "=================================================== " << std::endl;
		switch (playerActing) {
		case 공격하기: {
			std::cout << "공격스킬을 선택하세요.\n1.어택\n2.스트라이크\n\n===================================================\n입력값 : ";
			std::cin >> skillNumber;
			std::cout << "=================================================== " << std::endl;
			switch (skillNumber) {
			case ATTACK: {
				Monster->GotDamaged(warrior->Attack());
				break;
			}
			case STRIKE: {
				if (warrior->GetCurrentMP() >= 10) {
					Monster->GotDamaged(warrior->Strike());
					break;
				}
				else std::cout << "MP가 부족합니다(10소요). 현재 MP : " << warrior->GetCurrentMP() << " / " << warrior->GetMaxMP() << std::endl;
				continue;
			}
					   //미구현스킬
			case COUNTERATTACK: {
				if (warrior->GetCurrentMP() >= 20) {
					Monster->GotDamaged(warrior->CounterAttack());
					break;
				}
				else std::cout << "MP가 부족합니다.(20소요) 현재 MP : " << warrior->GetCurrentMP() << " / " << warrior->GetMaxMP() << std::endl;
				continue;
			}
							  //관리자스킬
			case FINALCRUSH: {
				//if (warrior->GetCurrentMP() >= 50) {
				Monster->GotDamaged(warrior->FinalCrush());
				break;
				//}
				//else std::cout << "MP가 부족합니다.(50소요) 현재 MP : " << warrior->GetCurrentMP() << " / " << warrior->GetMaxMP() << std::endl;
				//continue;
			}
			}
			break;
		}
		case 아이템사용: {
			std::cout << "아이템을 선택하세요" << std::endl;
			ShowInventory();
			if (SomthingShown) {
				std::cout << "아이템 번호를 누르면 착용하거나 사용할 수 있습니다.\n\n==================================================== \n입력값 : ";
				std::cin >> selectItem;
				std::cout << "=======================================================================================================" << std::endl;
				int powerPoint = Equip(selectItem);
				//포션일때
				if (powerPoint == -1) {
					int recoveryPoint = UsePotion(selectItem);
					if (isMPPotion == false) {
						if (warrior->GetMaxHP() > warrior->GetCurrentHP() + recoveryPoint) {
							warrior->SetCurrentHP(warrior->GetCurrentHP() + recoveryPoint);
							std::cout << "HP가 " << recoveryPoint << " 증가하였습니다." << std::endl;
						}
						else {
							int gap = warrior->GetMaxHP() - warrior->GetCurrentHP();
							warrior->SetCurrentHP(warrior->GetMaxHP());
							std::cout << "HP가 " << gap << " 증가하였습니다." << std::endl;
						}
					}
					else {
						if (warrior->GetMaxMP() > warrior->GetCurrentMP() + recoveryPoint) {
							warrior->SetCurrentMP(warrior->GetCurrentMP() + recoveryPoint);
							std::cout << "MP가 " << recoveryPoint << " 증가하였습니다." << std::endl;
						}
						else {
							int gap = warrior->GetMaxMP() - warrior->GetCurrentMP();
							warrior->SetCurrentMP(warrior->GetMaxMP());
							std::cout << "MP가 " << gap << " 증가하였습니다." << std::endl;
						}
					}
					warrior->ShowStatus();
					std::cout << std::endl;
					break;
				}
				std::cout << std::endl;
				break;
			}
		}
		case 상태보기: {
			warrior->ShowStatus();
			std::cout << std::endl;
			continue;
		}
		}

		if (Monster->GetCurrentHP() > 0) {
			std::cout << "몬스터 체력 :" << Monster->GetCurrentHP() << " / " << Monster->GetMaxHP() << "\n" << std::endl;
			system("pause");
			system("cls");
			std::cout << "몬스터의 턴입니다." << Monster->GetName() << "의 공격!" << std::endl;
			warrior->GotDamaged(Monster->Attack());
			Sleep(1000);
			std::cout << "\n전사의 체력 : " << warrior->GetCurrentHP() << " / " << warrior->GetMaxHP() << std::endl;
			battleRound++;
		}
		//게임 승리
		else if (Monster->GetCurrentHP() <= 0) {
			warrior->SetCurrentEXP(Monster->GetCurrentEXP() + warrior->GetCurrentEXP());
			std::cout << "\n<< 전투종료 >> \n경험치를 " << Monster->GetCurrentEXP() << "획득하였습니다.현재 경험치 : " << warrior->GetCurrentEXP() << "\n" << std::endl;
			DropItem();
			delete Monster;
			Monster = nullptr;
			if (warrior->GetCurrentEXP() > warrior->GetMaxEXP()) {
				warrior->LevelUp();
				warrior->SetMaxEXP(ExpMap[warrior->GetLevel()]);
				warrior->ShowStatus();
			}
			std::cout << std::endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

void DropItem() {
	srand(time(NULL));
	int DropRate0 = rand() % 100;
	int DropRate1 = rand() % 100;
	int DropRate2 = rand() % 100;
	int DropRate3 = rand() % 100;
	int DropRate4 = rand() % 100;
	int DropRate5 = rand() % 100;
	int DropRate6 = rand() % 100;
	int DropRate7 = rand() % 100;
	int DropRate8 = rand() % 100;
	int DropRate9 = rand() % 100;
	int DropRate10 = rand() % 100;
	int MoneyRate = 0;

	switch (MapNumber) {
	case Snail:
		MoneyRate = rand() % 6 + 10;
		if (DropRate0 < 50) {
			PotionInventory.push_back(PotionList[0]);
			std::cout << "HP물약(소)를 획득하였습니다." << std::endl;
		}
		if (DropRate1 < 50) {
			PotionInventory.push_back(PotionList[3]);
			std::cout << "MP물약(소)를 획득하였습니다." << std::endl;
		}
		if (DropRate2 < 70) {
			EquipInventory.push_back(WeaponAndArmorList[0]);
			std::cout << "목검을 획득하였습니다." << std::endl;
		}
		if (DropRate3 < 70) {
			EquipInventory.push_back(WeaponAndArmorList[3]);
			std::cout << "초급자용 갑옷을 획득하였습니다." << std::endl;
		}
		if (DropRate4 < 70) {
			EquipInventory.push_back(WeaponAndArmorList[6]);
			std::cout << "초급자용 방패를 획득하였습니다." << std::endl;
		}
		if (DropRate5 < 60) {
			haveMoney += MoneyRate;
			std::cout << MoneyRate << "원을 획득하였습니다" << std::endl;
		}
		break;
	case Slime:
		MoneyRate = rand() % 11 + 10;
		if (DropRate0 < 15) {
			PotionInventory.push_back(PotionList[0]);
			std::cout << "HP물약(소)를 획득하였습니다." << std::endl;
		}
		if (DropRate1 < 15) {
			PotionInventory.push_back(PotionList[3]);
			std::cout << "MP물약(소)를 획득하였습니다." << std::endl;
		}
		if (DropRate2 < 10) {
			PotionInventory.push_back(PotionList[1]);
			std::cout << "HP물약(중)를 획득하였습니다." << std::endl;
		}
		if (DropRate3 < 10) {
			PotionInventory.push_back(PotionList[4]);
			std::cout << "MP물약(중)를 획득하였습니다." << std::endl;
		}
		if (DropRate4 < 8) {
			EquipInventory.push_back(WeaponAndArmorList[0]);
			std::cout << "목검을 획득하였습니다." << std::endl;
		}
		if (DropRate5 < 3) {
			EquipInventory.push_back(WeaponAndArmorList[1]);
			std::cout << "청동검을 획득하였습니다." << std::endl;
		}
		if (DropRate6 < 10) {
			EquipInventory.push_back(WeaponAndArmorList[3]);
			std::cout << "초급자용 갑옷을 획득하였습니다." << std::endl;
		}
		if (DropRate7 < 4) {
			EquipInventory.push_back(WeaponAndArmorList[4]);
			std::cout << "중급자용 갑옷을 획득하였습니다." << std::endl;
		}
		if (DropRate8 < 10) {
			EquipInventory.push_back(WeaponAndArmorList[6]);
			std::cout << "초급자용 방패를 획득하였습니다." << std::endl;
		}
		if (DropRate9 < 4) {
			EquipInventory.push_back(WeaponAndArmorList[7]);
			std::cout << "중급자용 방패를 획득하였습니다." << std::endl;
		}
		if (DropRate10 < 60) {
			haveMoney += MoneyRate;
			std::cout << MoneyRate << "원을 획득하였습니다" << std::endl;
		}
		break;

	case Pig:
		MoneyRate = rand() % 21 + 20;
		if (DropRate1 < 15) {
			PotionInventory.push_back(PotionList[1]);
			std::cout << "HP물약(중)를 획득하였습니다." << std::endl;
		}
		if (DropRate2 < 15) {
			PotionInventory.push_back(PotionList[4]);
			std::cout << "MP물약(중)를 획득하였습니다." << std::endl;
		}
		if (DropRate3 < 4) {
			EquipInventory.push_back(WeaponAndArmorList[1]);
			std::cout << "청동검을 획득하였습니다." << std::endl;
		}
		if (DropRate4 < 6) {
			EquipInventory.push_back(WeaponAndArmorList[4]);
			std::cout << "중급자용 갑옷을 획득하였습니다." << std::endl;
		}
		if (DropRate5 < 6) {
			EquipInventory.push_back(WeaponAndArmorList[7]);
			std::cout << "중급자용 방패를 획득하였습니다." << std::endl;
		}
		if (DropRate6 < 60) {
			haveMoney += MoneyRate;
			std::cout << MoneyRate << "원을 획득하였습니다" << std::endl;
		}
		break;

	case Wolf:
		MoneyRate = rand() % 21 + 40;
		if (DropRate1 < 15) {
			PotionInventory.push_back(PotionList[1]);
			std::cout << "HP물약(중)를 획득하였습니다." << std::endl;
		}
		if (DropRate2 < 10) {
			PotionInventory.push_back(PotionList[2]);
			std::cout << "HP물약(대)를 획득하였습니다." << std::endl;
		}
		if (DropRate3 < 15) {
			PotionInventory.push_back(PotionList[4]);
			std::cout << "MP물약(중)를 획득하였습니다." << std::endl;
		}
		if (DropRate4 < 15) {
			PotionInventory.push_back(PotionList[5]);
			std::cout << "MP물약(대)를 획득하였습니다." << std::endl;
		}
		if (DropRate5 < 6) {
			EquipInventory.push_back(WeaponAndArmorList[1]);
			std::cout << "청동검을 획득하였습니다." << std::endl;
		}
		if (DropRate6 < 3) {
			EquipInventory.push_back(WeaponAndArmorList[2]);
			std::cout << "롱소드을 획득하였습니다." << std::endl;
		}
		if (DropRate7 < 7) {
			EquipInventory.push_back(WeaponAndArmorList[4]);
			std::cout << "중급자용 갑옷을 획득하였습니다." << std::endl;
		}
		if (DropRate8 < 4) {
			EquipInventory.push_back(WeaponAndArmorList[5]);
			std::cout << "고급자용 갑옷을 획득하였습니다." << std::endl;
		}
		if (DropRate9 < 7) {
			EquipInventory.push_back(WeaponAndArmorList[7]);
			std::cout << "중급자용 방패를 획득하였습니다." << std::endl;
		}
		if (DropRate10 < 4) {
			EquipInventory.push_back(WeaponAndArmorList[8]);
			std::cout << "고급자용 방패를 획득하였습니다." << std::endl;
		}
		if (DropRate10 < 60) haveMoney += MoneyRate;
		break;
	}
}

void ShowInventory() {

	SomthingShown = true;
	int tempToSkip = 0;
	bool IsEmptyEquip = false;
	bool IsEmptyPotion = false;

	equipInvenSize = EquipInventory.size();
	potionInvenSize = PotionInventory.size();

	if (equipInvenSize == NULL) {
		std::cout << "보유한 장비아이템이 없습니다." << std::endl;
		IsEmptyEquip = true;
	}
	else {
		std::cout << "보유 장비 아이템 : " << std::endl;
		for (int i = 0; i < equipInvenSize; i++) {
			EquipInventory[i].SetItemOrder(i + 1);
			std::cout << EquipInventory[i].GetItemOrder() << ". " << EquipInventory[i].GetName() << std::endl;
			tempToSkip++;
		}
		std::cout << std::endl;
	}

	if (potionInvenSize == NULL) {
		std::cout << "보유한 물약아이템이 없습니다." << std::endl;
		IsEmptyPotion = true;
	}
	else {
		std::cout << "보유 물약 아이템 : " << std::endl;
		for (int i = 0; i < potionInvenSize; i++) {
			PotionInventory[i].SetItemOrder(i + tempToSkip + 1);
			std::cout << PotionInventory[i].GetItemOrder() << ". " << PotionInventory[i].GetName() << std::endl;
		}
		std::cout << std::endl;
	}
	if (IsEmptyEquip && IsEmptyPotion) SomthingShown = false;
}

int Equip(int itemNumber) {

	int returnVal = 0;

	if (equipInvenSize < itemNumber)return -1;

	for (int i = 0; i < equipInvenSize; i++) {
		if (EquipInventory[i].GetItemOrder() == itemNumber) {
			if ((EquipInventory[i].GetItemCode() == 0) || (EquipInventory[i].GetItemCode() == 1) || (EquipInventory[i].GetItemCode() == 2)) {
				if (WeaponEquipped == false) {
					EquippedWeapon.push_back(EquipInventory[i]);
					isWeapon = true;
					std::cout << EquipInventory[i].GetName() << "을 착용하였습니다.\n공격력이 " << EquipInventory[i].GetAtk() << " 증가하였습니다.\n" << std::endl;
					WeaponEquipped = true;
					returnVal = EquipInventory[i].GetAtk();
				}
				else {
					std::cout << "무기를 이미 장착하고 있습니다. 해제 후 다시 시도하세요." << std::endl;
					continue;
				}
			}
			else if ((EquipInventory[i].GetItemCode() == 3) || (EquipInventory[i].GetItemCode() == 4) || (EquipInventory[i].GetItemCode() == 5)) {
				if (ArmorEquipped == false) {
					EquippedArmor.push_back(EquipInventory[i]);
					isWeapon = false;
					std::cout << EquipInventory[i].GetName() << "을 착용하였습니다.\n방어력이 " << EquipInventory[i].GetDef() << " 증가하였습니다.\n" << std::endl;
					ArmorEquipped = true;
					returnVal = EquipInventory[i].GetDef();
				}
				else {
					std::cout << "갑옷을 이미 장착하고 있습니다. 해제 후 다시 시도하세요." << std::endl;
					continue;
				}
			}
			else if ((EquipInventory[i].GetItemCode() == 6) || (EquipInventory[i].GetItemCode() == 7) || (EquipInventory[i].GetItemCode() == 8)) {
				if (ShieldEquipped == false) {
					EquippedShield.push_back(EquipInventory[i]);
					isWeapon = false;
					std::cout << EquipInventory[i].GetName() << "을 착용하였습니다.\n방어력이 " << EquipInventory[i].GetDef() << " 증가하였습니다.\n" << std::endl;
					ShieldEquipped = true;
					returnVal = EquipInventory[i].GetDef();
				}
				else {
					std::cout << "방패를 이미 장착하고 있습니다. 해제 후 다시 시도하세요." << std::endl;
					continue;
				}
			}
			else {
				std::cout << "존재하지 않는 아이템코드입니다." << std::endl;
				returnVal = 0;
			}

			EquipInventory.erase(EquipInventory.begin() + i);
			break;
		}
		EquipInventory.shrink_to_fit();
	}
	return returnVal;
}

void ShowEquippedItem() {
	if (!EquippedWeapon.empty())std::cout << "장착 무기 : " << EquippedWeapon.back().GetName() << std::endl;
	else std::cout << "장착 무기 : 없음" << std::endl;
	if (!EquippedArmor.empty())std::cout << "장착 갑옷 : " << EquippedArmor.back().GetName() << std::endl;
	else std::cout << "장착 갑옷 : 없음" << std::endl;
	if (!EquippedShield.empty())std::cout << "장착 방패 : " << EquippedShield.back().GetName() << std::endl;
	else std::cout << "장착 방패 : 없음" << std::endl;
	std::cout << std::endl;
}


int UsePotion(int itemNumber) {

	int returnVal2 = 0;

	for (int i = 0; i < potionInvenSize + equipInvenSize; i++) {
		if (PotionInventory[i].GetItemOrder() == itemNumber) {
			if (PotionInventory[i].GetHP() > 0) {
				std::cout << PotionInventory[i].GetName() << "를 사용하였습니다. " << std::endl;
				isMPPotion = false;
				returnVal2 = PotionInventory[i].GetHP();
			}
			else if (PotionInventory[i].GetMP() > 0) {
				std::cout << PotionInventory[i].GetName() << "를 사용하였습니다. " << std::endl;
				isMPPotion = true;
				returnVal2 = PotionInventory[i].GetMP();
			}
			else {
				std::cout << "Get HP와 MP로 걸러지지않음" << std::endl;
			}

			PotionInventory.erase(PotionInventory.begin() + i);
			break;
		}
	}
	PotionInventory.shrink_to_fit();
	return returnVal2;
}

