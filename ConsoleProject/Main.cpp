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

//���� ������
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
	//����ġ ��
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

	// ���� : ������
	WeaponAndArmorList.push_back(WeaponAndArmor("���", 1000, 200, 2, 0, 1, 0)); //0 
	WeaponAndArmorList.push_back(WeaponAndArmor("û����", 3000, 600, 10, 0, 10, 1)); //1
	WeaponAndArmorList.push_back(WeaponAndArmor("�ռҵ�", 5000, 1000, 20, 0, 15, 2)); //2
	WeaponAndArmorList.push_back(WeaponAndArmor("�ʱ��ڿ� ����", 800, 160, 0, 1, 1, 3)); //3
	WeaponAndArmorList.push_back(WeaponAndArmor("�߱��ڿ� ����", 2000, 400, 0, 5, 10, 4)); //4
	WeaponAndArmorList.push_back(WeaponAndArmor("����ڿ� ����", 4000, 800, 0, 10, 15, 5)); //5
	WeaponAndArmorList.push_back(WeaponAndArmor("�ʱ��ڿ� ����", 800, 160, 0, 1, 1, 6)); //6
	WeaponAndArmorList.push_back(WeaponAndArmor("�߱��ڿ� ����", 2000, 400, 0, 5, 10, 7)); //7
	WeaponAndArmorList.push_back(WeaponAndArmor("����ڿ� ����", 4000, 800, 0, 10, 15, 8)); //8

	PotionList.push_back(Potion("HP����(��)", 50, 10, 30, 0)); //0
	PotionList.push_back(Potion("HP����(��)", 100, 20, 50, 0)); //1
	PotionList.push_back(Potion("HP����(��)", 200, 40, 70, 0)); //2
	PotionList.push_back(Potion("MP����(��)", 70, 14, 0, 30)); //3
	PotionList.push_back(Potion("MP����(��)", 150, 30, 0, 50)); //4
	PotionList.push_back(Potion("MP����(��)", 280, 64, 0, 70)); //5



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
		std::cout << "���� Stage " << stageNumber << " �Դϴ�.\nStage �� �������� ���� ����˴ϴ�.\n1 ~ 5 : ������ ���� // 6 ~ 10 : ������ �� // 11 ~ 15 : ���� �غ� // 16 ~ 20 : ������ ��\n\n======================================================================================================\n1. ������ �����մϴ�.\n2. ĳ���� ���¸� Ȯ���մϴ�.\n3. �κ��丮�� Ȯ���մϴ�.\n\n======================================================================================================\n�Է°� : ";
		std::cin >> gameMenu;
		std::cout << "======================================================================================================" << std::endl;
		switch (gameMenu) {
		case 1:
			break;
		case 2:
			warrior->ShowStatus();
			std::cout << std::endl;
			ShowEquippedItem();
			std::cout << "���ڸ� �Է��Ͽ� ��� ������ �� �ֽ��ϴ�.\n\n1. ��������\n2. ��������\n3. ��������\n4. �޴��� ����\n\n======================================================================================================\n�Է°� : ";
			std::cin >> unEquipItem;
			std::cout << "======================================================================================================" << std::endl;
			switch (unEquipItem) {
			case 1: {
				std::string UnEquippedWeapon = EquippedWeapon[0].GetName();
				unEquippedPoint = EquippedWeapon[0].GetAtk();
				EquipInventory.push_back(EquippedWeapon[0]);
				warrior->SetAttack(warrior->GetAttack() - unEquippedPoint);
				EquippedWeapon.pop_back();
				std::cout << UnEquippedWeapon << "�� �����Ͽ����ϴ�." << std::endl;
				WeaponEquipped = false;
				break;
			}
			case 2: {
				std::string UnEquippedArmor = EquippedArmor[0].GetName();
				unEquippedPoint = EquippedArmor[0].GetDef();
				EquipInventory.push_back(EquippedArmor[0]);
				warrior->SetDefence(warrior->GetDefence() - unEquippedPoint);
				EquippedArmor.pop_back();
				std::cout << UnEquippedArmor << "�� �����Ͽ����ϴ�." << std::endl;
				ArmorEquipped = false;
				break;
			}
			case 3: {
				std::string UnEquippedShield = EquippedShield[0].GetName();
				unEquippedPoint = EquippedShield[0].GetDef();
				EquipInventory.push_back(EquippedShield[0]);
				warrior->SetDefence(warrior->GetDefence() - unEquippedPoint);
				EquippedShield.pop_back();
				std::cout << UnEquippedShield << "�� �����Ͽ����ϴ�." << std::endl;
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
				std::cout << "������ ��ȣ�� ������ �����ϰų� ����� �� �ֽ��ϴ�.\n\n==================================================== \n�Է°� : ";
				std::cin >> selectItem;
				std::cout << "=======================================================================================================" << std::endl;
				int powerPoint = Equip(selectItem);
				//�����϶�
				if (powerPoint == -1) {
					int recoveryPoint = UsePotion(selectItem);
					if (isMPPotion == false) {
						if (warrior->GetMaxHP() > warrior->GetCurrentHP() + recoveryPoint) {
							warrior->SetCurrentHP(warrior->GetCurrentHP() + recoveryPoint);
							std::cout << "HP�� " << recoveryPoint << " �����Ͽ����ϴ�." << std::endl;
						}
						else {
							int gap = warrior->GetMaxHP() - warrior->GetCurrentHP();
							warrior->SetCurrentHP(warrior->GetMaxHP());
							std::cout << "HP�� " << gap << " �����Ͽ����ϴ�." << std::endl;
						}
					}
					else {
						if (warrior->GetMaxMP() > warrior->GetCurrentMP() + recoveryPoint) {
							warrior->SetCurrentMP(warrior->GetCurrentMP() + recoveryPoint);
							std::cout << "MP�� " << recoveryPoint << " �����Ͽ����ϴ�." << std::endl;
						}
						else {
							int gap = warrior->GetMaxMP() - warrior->GetCurrentMP();
							warrior->SetCurrentMP(warrior->GetMaxMP());
							std::cout << "MP�� " << gap << " �����Ͽ����ϴ�." << std::endl;
						}
					}
					warrior->ShowStatus();
					std::cout << std::endl;
					continue;
				}
				//�����϶�
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
			//	//����
			//	continue;
		};

		PlayerInMap* player = new PlayerInMap();
		MonsterInMap* mon1 = new MonsterInMap(rand1, rand2);
		MonsterInMap* mon2 = new MonsterInMap(rand3, rand4);


		while (true) {
			std::cout << "������ �����մϴ�." << std::endl;
			system("pause");
			system("cls");
			ShownMap();
			player->PlayerMove();
			system("cls");
			//��������
			std::cout << "���Ϳ� �������ϴ�.\n " << std::endl;

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
				std::cout << "�ش� ���������� Ŭ���� �Ͽ����ϴ�. �������������� �Ѿ�ϴ�." << std::endl;
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
	�����ϱ� = 1,
	�����ۻ��,
	���º���
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

		std::cout << "<" << battleRound << " ����> �÷��̾� ���Դϴ�.�ൿ�� ������.\n1.�����ϱ�\n2.�����ۻ��\n3.���º���\n\n=================================================== \n�Է°� : ";
		std::cin >> playerActing;
		std::cout << "=================================================== " << std::endl;
		switch (playerActing) {
		case �����ϱ�: {
			std::cout << "���ݽ�ų�� �����ϼ���.\n1.����\n2.��Ʈ����ũ\n\n===================================================\n�Է°� : ";
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
				else std::cout << "MP�� �����մϴ�(10�ҿ�). ���� MP : " << warrior->GetCurrentMP() << " / " << warrior->GetMaxMP() << std::endl;
				continue;
			}
					   //�̱�����ų
			case COUNTERATTACK: {
				if (warrior->GetCurrentMP() >= 20) {
					Monster->GotDamaged(warrior->CounterAttack());
					break;
				}
				else std::cout << "MP�� �����մϴ�.(20�ҿ�) ���� MP : " << warrior->GetCurrentMP() << " / " << warrior->GetMaxMP() << std::endl;
				continue;
			}
							  //�����ڽ�ų
			case FINALCRUSH: {
				//if (warrior->GetCurrentMP() >= 50) {
				Monster->GotDamaged(warrior->FinalCrush());
				break;
				//}
				//else std::cout << "MP�� �����մϴ�.(50�ҿ�) ���� MP : " << warrior->GetCurrentMP() << " / " << warrior->GetMaxMP() << std::endl;
				//continue;
			}
			}
			break;
		}
		case �����ۻ��: {
			std::cout << "�������� �����ϼ���" << std::endl;
			ShowInventory();
			if (SomthingShown) {
				std::cout << "������ ��ȣ�� ������ �����ϰų� ����� �� �ֽ��ϴ�.\n\n==================================================== \n�Է°� : ";
				std::cin >> selectItem;
				std::cout << "=======================================================================================================" << std::endl;
				int powerPoint = Equip(selectItem);
				//�����϶�
				if (powerPoint == -1) {
					int recoveryPoint = UsePotion(selectItem);
					if (isMPPotion == false) {
						if (warrior->GetMaxHP() > warrior->GetCurrentHP() + recoveryPoint) {
							warrior->SetCurrentHP(warrior->GetCurrentHP() + recoveryPoint);
							std::cout << "HP�� " << recoveryPoint << " �����Ͽ����ϴ�." << std::endl;
						}
						else {
							int gap = warrior->GetMaxHP() - warrior->GetCurrentHP();
							warrior->SetCurrentHP(warrior->GetMaxHP());
							std::cout << "HP�� " << gap << " �����Ͽ����ϴ�." << std::endl;
						}
					}
					else {
						if (warrior->GetMaxMP() > warrior->GetCurrentMP() + recoveryPoint) {
							warrior->SetCurrentMP(warrior->GetCurrentMP() + recoveryPoint);
							std::cout << "MP�� " << recoveryPoint << " �����Ͽ����ϴ�." << std::endl;
						}
						else {
							int gap = warrior->GetMaxMP() - warrior->GetCurrentMP();
							warrior->SetCurrentMP(warrior->GetMaxMP());
							std::cout << "MP�� " << gap << " �����Ͽ����ϴ�." << std::endl;
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
		case ���º���: {
			warrior->ShowStatus();
			std::cout << std::endl;
			continue;
		}
		}

		if (Monster->GetCurrentHP() > 0) {
			std::cout << "���� ü�� :" << Monster->GetCurrentHP() << " / " << Monster->GetMaxHP() << "\n" << std::endl;
			system("pause");
			system("cls");
			std::cout << "������ ���Դϴ�." << Monster->GetName() << "�� ����!" << std::endl;
			warrior->GotDamaged(Monster->Attack());
			Sleep(1000);
			std::cout << "\n������ ü�� : " << warrior->GetCurrentHP() << " / " << warrior->GetMaxHP() << std::endl;
			battleRound++;
		}
		//���� �¸�
		else if (Monster->GetCurrentHP() <= 0) {
			warrior->SetCurrentEXP(Monster->GetCurrentEXP() + warrior->GetCurrentEXP());
			std::cout << "\n<< �������� >> \n����ġ�� " << Monster->GetCurrentEXP() << "ȹ���Ͽ����ϴ�.���� ����ġ : " << warrior->GetCurrentEXP() << "\n" << std::endl;
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
			std::cout << "HP����(��)�� ȹ���Ͽ����ϴ�." << std::endl;
		}
		if (DropRate1 < 50) {
			PotionInventory.push_back(PotionList[3]);
			std::cout << "MP����(��)�� ȹ���Ͽ����ϴ�." << std::endl;
		}
		if (DropRate2 < 70) {
			EquipInventory.push_back(WeaponAndArmorList[0]);
			std::cout << "����� ȹ���Ͽ����ϴ�." << std::endl;
		}
		if (DropRate3 < 70) {
			EquipInventory.push_back(WeaponAndArmorList[3]);
			std::cout << "�ʱ��ڿ� ������ ȹ���Ͽ����ϴ�." << std::endl;
		}
		if (DropRate4 < 70) {
			EquipInventory.push_back(WeaponAndArmorList[6]);
			std::cout << "�ʱ��ڿ� ���и� ȹ���Ͽ����ϴ�." << std::endl;
		}
		if (DropRate5 < 60) {
			haveMoney += MoneyRate;
			std::cout << MoneyRate << "���� ȹ���Ͽ����ϴ�" << std::endl;
		}
		break;
	case Slime:
		MoneyRate = rand() % 11 + 10;
		if (DropRate0 < 15) {
			PotionInventory.push_back(PotionList[0]);
			std::cout << "HP����(��)�� ȹ���Ͽ����ϴ�." << std::endl;
		}
		if (DropRate1 < 15) {
			PotionInventory.push_back(PotionList[3]);
			std::cout << "MP����(��)�� ȹ���Ͽ����ϴ�." << std::endl;
		}
		if (DropRate2 < 10) {
			PotionInventory.push_back(PotionList[1]);
			std::cout << "HP����(��)�� ȹ���Ͽ����ϴ�." << std::endl;
		}
		if (DropRate3 < 10) {
			PotionInventory.push_back(PotionList[4]);
			std::cout << "MP����(��)�� ȹ���Ͽ����ϴ�." << std::endl;
		}
		if (DropRate4 < 8) {
			EquipInventory.push_back(WeaponAndArmorList[0]);
			std::cout << "����� ȹ���Ͽ����ϴ�." << std::endl;
		}
		if (DropRate5 < 3) {
			EquipInventory.push_back(WeaponAndArmorList[1]);
			std::cout << "û������ ȹ���Ͽ����ϴ�." << std::endl;
		}
		if (DropRate6 < 10) {
			EquipInventory.push_back(WeaponAndArmorList[3]);
			std::cout << "�ʱ��ڿ� ������ ȹ���Ͽ����ϴ�." << std::endl;
		}
		if (DropRate7 < 4) {
			EquipInventory.push_back(WeaponAndArmorList[4]);
			std::cout << "�߱��ڿ� ������ ȹ���Ͽ����ϴ�." << std::endl;
		}
		if (DropRate8 < 10) {
			EquipInventory.push_back(WeaponAndArmorList[6]);
			std::cout << "�ʱ��ڿ� ���и� ȹ���Ͽ����ϴ�." << std::endl;
		}
		if (DropRate9 < 4) {
			EquipInventory.push_back(WeaponAndArmorList[7]);
			std::cout << "�߱��ڿ� ���и� ȹ���Ͽ����ϴ�." << std::endl;
		}
		if (DropRate10 < 60) {
			haveMoney += MoneyRate;
			std::cout << MoneyRate << "���� ȹ���Ͽ����ϴ�" << std::endl;
		}
		break;

	case Pig:
		MoneyRate = rand() % 21 + 20;
		if (DropRate1 < 15) {
			PotionInventory.push_back(PotionList[1]);
			std::cout << "HP����(��)�� ȹ���Ͽ����ϴ�." << std::endl;
		}
		if (DropRate2 < 15) {
			PotionInventory.push_back(PotionList[4]);
			std::cout << "MP����(��)�� ȹ���Ͽ����ϴ�." << std::endl;
		}
		if (DropRate3 < 4) {
			EquipInventory.push_back(WeaponAndArmorList[1]);
			std::cout << "û������ ȹ���Ͽ����ϴ�." << std::endl;
		}
		if (DropRate4 < 6) {
			EquipInventory.push_back(WeaponAndArmorList[4]);
			std::cout << "�߱��ڿ� ������ ȹ���Ͽ����ϴ�." << std::endl;
		}
		if (DropRate5 < 6) {
			EquipInventory.push_back(WeaponAndArmorList[7]);
			std::cout << "�߱��ڿ� ���и� ȹ���Ͽ����ϴ�." << std::endl;
		}
		if (DropRate6 < 60) {
			haveMoney += MoneyRate;
			std::cout << MoneyRate << "���� ȹ���Ͽ����ϴ�" << std::endl;
		}
		break;

	case Wolf:
		MoneyRate = rand() % 21 + 40;
		if (DropRate1 < 15) {
			PotionInventory.push_back(PotionList[1]);
			std::cout << "HP����(��)�� ȹ���Ͽ����ϴ�." << std::endl;
		}
		if (DropRate2 < 10) {
			PotionInventory.push_back(PotionList[2]);
			std::cout << "HP����(��)�� ȹ���Ͽ����ϴ�." << std::endl;
		}
		if (DropRate3 < 15) {
			PotionInventory.push_back(PotionList[4]);
			std::cout << "MP����(��)�� ȹ���Ͽ����ϴ�." << std::endl;
		}
		if (DropRate4 < 15) {
			PotionInventory.push_back(PotionList[5]);
			std::cout << "MP����(��)�� ȹ���Ͽ����ϴ�." << std::endl;
		}
		if (DropRate5 < 6) {
			EquipInventory.push_back(WeaponAndArmorList[1]);
			std::cout << "û������ ȹ���Ͽ����ϴ�." << std::endl;
		}
		if (DropRate6 < 3) {
			EquipInventory.push_back(WeaponAndArmorList[2]);
			std::cout << "�ռҵ��� ȹ���Ͽ����ϴ�." << std::endl;
		}
		if (DropRate7 < 7) {
			EquipInventory.push_back(WeaponAndArmorList[4]);
			std::cout << "�߱��ڿ� ������ ȹ���Ͽ����ϴ�." << std::endl;
		}
		if (DropRate8 < 4) {
			EquipInventory.push_back(WeaponAndArmorList[5]);
			std::cout << "����ڿ� ������ ȹ���Ͽ����ϴ�." << std::endl;
		}
		if (DropRate9 < 7) {
			EquipInventory.push_back(WeaponAndArmorList[7]);
			std::cout << "�߱��ڿ� ���и� ȹ���Ͽ����ϴ�." << std::endl;
		}
		if (DropRate10 < 4) {
			EquipInventory.push_back(WeaponAndArmorList[8]);
			std::cout << "����ڿ� ���и� ȹ���Ͽ����ϴ�." << std::endl;
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
		std::cout << "������ ���������� �����ϴ�." << std::endl;
		IsEmptyEquip = true;
	}
	else {
		std::cout << "���� ��� ������ : " << std::endl;
		for (int i = 0; i < equipInvenSize; i++) {
			EquipInventory[i].SetItemOrder(i + 1);
			std::cout << EquipInventory[i].GetItemOrder() << ". " << EquipInventory[i].GetName() << std::endl;
			tempToSkip++;
		}
		std::cout << std::endl;
	}

	if (potionInvenSize == NULL) {
		std::cout << "������ ����������� �����ϴ�." << std::endl;
		IsEmptyPotion = true;
	}
	else {
		std::cout << "���� ���� ������ : " << std::endl;
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
					std::cout << EquipInventory[i].GetName() << "�� �����Ͽ����ϴ�.\n���ݷ��� " << EquipInventory[i].GetAtk() << " �����Ͽ����ϴ�.\n" << std::endl;
					WeaponEquipped = true;
					returnVal = EquipInventory[i].GetAtk();
				}
				else {
					std::cout << "���⸦ �̹� �����ϰ� �ֽ��ϴ�. ���� �� �ٽ� �õ��ϼ���." << std::endl;
					continue;
				}
			}
			else if ((EquipInventory[i].GetItemCode() == 3) || (EquipInventory[i].GetItemCode() == 4) || (EquipInventory[i].GetItemCode() == 5)) {
				if (ArmorEquipped == false) {
					EquippedArmor.push_back(EquipInventory[i]);
					isWeapon = false;
					std::cout << EquipInventory[i].GetName() << "�� �����Ͽ����ϴ�.\n������ " << EquipInventory[i].GetDef() << " �����Ͽ����ϴ�.\n" << std::endl;
					ArmorEquipped = true;
					returnVal = EquipInventory[i].GetDef();
				}
				else {
					std::cout << "������ �̹� �����ϰ� �ֽ��ϴ�. ���� �� �ٽ� �õ��ϼ���." << std::endl;
					continue;
				}
			}
			else if ((EquipInventory[i].GetItemCode() == 6) || (EquipInventory[i].GetItemCode() == 7) || (EquipInventory[i].GetItemCode() == 8)) {
				if (ShieldEquipped == false) {
					EquippedShield.push_back(EquipInventory[i]);
					isWeapon = false;
					std::cout << EquipInventory[i].GetName() << "�� �����Ͽ����ϴ�.\n������ " << EquipInventory[i].GetDef() << " �����Ͽ����ϴ�.\n" << std::endl;
					ShieldEquipped = true;
					returnVal = EquipInventory[i].GetDef();
				}
				else {
					std::cout << "���и� �̹� �����ϰ� �ֽ��ϴ�. ���� �� �ٽ� �õ��ϼ���." << std::endl;
					continue;
				}
			}
			else {
				std::cout << "�������� �ʴ� �������ڵ��Դϴ�." << std::endl;
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
	if (!EquippedWeapon.empty())std::cout << "���� ���� : " << EquippedWeapon.back().GetName() << std::endl;
	else std::cout << "���� ���� : ����" << std::endl;
	if (!EquippedArmor.empty())std::cout << "���� ���� : " << EquippedArmor.back().GetName() << std::endl;
	else std::cout << "���� ���� : ����" << std::endl;
	if (!EquippedShield.empty())std::cout << "���� ���� : " << EquippedShield.back().GetName() << std::endl;
	else std::cout << "���� ���� : ����" << std::endl;
	std::cout << std::endl;
}


int UsePotion(int itemNumber) {

	int returnVal2 = 0;

	for (int i = 0; i < potionInvenSize + equipInvenSize; i++) {
		if (PotionInventory[i].GetItemOrder() == itemNumber) {
			if (PotionInventory[i].GetHP() > 0) {
				std::cout << PotionInventory[i].GetName() << "�� ����Ͽ����ϴ�. " << std::endl;
				isMPPotion = false;
				returnVal2 = PotionInventory[i].GetHP();
			}
			else if (PotionInventory[i].GetMP() > 0) {
				std::cout << PotionInventory[i].GetName() << "�� ����Ͽ����ϴ�. " << std::endl;
				isMPPotion = true;
				returnVal2 = PotionInventory[i].GetMP();
			}
			else {
				std::cout << "Get HP�� MP�� �ɷ���������" << std::endl;
			}

			PotionInventory.erase(PotionInventory.begin() + i);
			break;
		}
	}
	PotionInventory.shrink_to_fit();
	return returnVal2;
}

