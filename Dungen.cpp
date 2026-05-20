#include "common.h"
#include "Dungen.h"
#include "Monster.h"
#include "M_Monsters_.h"
#include "Player.h"
#include "Inventory.h"


const int MAX_INVENTORY = 10;
Dungen::Dungen() {
	// A 루트 방 배치
	a_route.push_back(new Slime("슬라임", 30, 20, 30, 5));
	a_route.push_back(new Goblin("고블린 대장", 40, 10, 35, 10));
	a_route.push_back(new Ork("오크", 60, 20, 40, 1));
	a_route.push_back(new Boss("고블린 왕", 100, 10, 100, 10));

	// B 루트 방 배치
	b_route.push_back(new Goblin("고블린", 50, 30, 35, 7));
	b_route.push_back(new Ork("오크", 70, 20, 50, 15));
	b_route.push_back(new Slime("강한 슬라임", 50, 45, 45, 7));
	b_route.push_back(new Boss("오크 왕", 100, 20, 100, 15));
}
Dungen::~Dungen() {
	for (Monster* m : a_route) { delete m; }
	for (Monster* m : b_route) { delete m; }
}

void Dungen::enterDungeon(Player* player, Inventory<Item>& inventory) {
	std::vector<Monster*>* route = nullptr;
	if (rand() % 2) {
		route = &a_route;
	}
	else {
		route = &b_route;
	}
	std::cout << "던전 입장!" << std::endl;
	std::cout << std::endl;
	int count_dungen = 0;
	for(Monster* monster : *route){
		if (monster->getHp() <= 0) {
			continue;
		}
		std::cout << "탐색중" << std::endl;
		Util::slowPrint(".", 200);
		Util::slowPrint(".", 200);
		Util::slowPrint(".", 200);
		Util::slowPrint(".", 200);
		Util::slowPrint("!", 100);
		std::cout << std::endl;
		if (count_dungen == 3) {
			std::cout << "★ 보스방 개방!" << std::endl;
			Util::wait(500);
			Util::slowPrint("보스가 나타났다!", 50);
			Util::wait(500);
		}
		else {
			Util::slowPrint("몬스터가 나타났다!", 30);
		}
		bool isVictory = fightMonster(player, monster, inventory);
		count_dungen++;
		if (!isVictory) {
			std::cout << "던전 공략 실패... 마을로 돌아갑니다." << std::endl;
			player->setHp(player->getMaxHp());
			for (Monster* m : a_route) {
				m->ResetHP();
			}
			for (Monster* m : b_route) {
				m->ResetHP();
			}
			return;
		}
		if (count_dungen < 4) {
			std::cout << count_dungen << "번째 몬스터 격파!" << std::endl;
			Util::wait(1000);
			std::cout << "던전 탐험을 계속합니다..." << std::endl;
			Util::waitForKey();
		}
		else { 
			std::cout << "보스 몬스터 격파!" << std::endl;
		}

	}
	Util::slowPrint("던전 클리어!", 50);
	Util::wait(500);
	for (Monster* m : a_route) {
		m->ResetHP();
	}
	for (Monster* m : b_route) {
		m->ResetHP();
	}
	Util::waitForKey();
}
bool Dungen::fightMonster(Player* player, Monster* monster, Inventory<Item>& inventory) {
	std::cout << std::endl;
	std::cout << "[ 전투 시작! ] " << player->getName() << " vs " << monster->getName() << std::endl;
	while (player->getHp() > 0 && monster->getHp() > 0)
	{
		Util::wait(300);
		std::cout << std::endl;
		std::cout << "<" << player->getName() << ": " << player->getHp() << "/" << player->getMaxHp() << " vs " << monster->getName() << ": " << monster->getHp() << "/" << monster->getMaxHp() << ">" << std::endl;
		std::cout << "--- 플레이어 턴---" << std::endl;
		std::cout << "1. 공격한다  2. 아이템 사용  3. 도망간다" << std::endl;
		std::cout << "선택: ";
		int choice = 0;
		std::cin >> choice;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "잘못된 입력입니다. 다시 입력해주세요: ";
			std::cout << std::endl;
			continue;
		}
		switch (choice)
		{
		case 1:
			player->attack(monster);
			if (monster->getHp() <= 0) {
				break;
			}
			monster->attack(player);
			break;
		case 2:
			inventory.printInventory();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			inventory.useItem(player);
			break;
		case 3:
			std::cout << "도망에 성공했습니다!" << std::endl;
			return false;
		default:
			std::cout << "잘못된 입력입니다. 다시 입력해주세요: ";
			std::cout << std::endl;
			break;
		}
	}
	if (player->getHp() <= 0) {
		std::cout << "플레이어가 패배했습니다." << std::endl;
		return false;
	}
	else if (monster->getHp() <= 0) {
		std::cout << std::endl;
		Util::slowPrint("몬스터를 처치했습니다.", 10);
		std::cout << std::endl;
		Util::wait(30);
		std::cout << "★ 전투 승리!" << std::endl;
		player->GainExp(monster);
		std::cout << std::endl;
		
		Util::wait(500);
		std::cout << " -> " << monster->monsterLoot.name << " 획득!" << std::endl;
		
		inventory.AddItem(monster->monsterLoot);

		std::cout << std::endl;
		return true;
	}
	return false;
}

//#include "common.h"
//
//const int MAX_INVENTORY = 10;
//
//void Dungen::enterDungeon() {
//	cout << "던전 입장!" << endl;
//	cout << endl;
//	cout << "탐색중" << endl;
//	Util::slowPrint(".", 200);
//	Util::slowPrint(".", 200);
//	Util::slowPrint(".", 200);
//	Util::slowPrint(".", 200);
//	Util::slowPrint("!", 100);
//	cout << endl;
//	Util::slowPrint("몬스터가 나타났다!", 30);
//}
//bool Dungen::fightMonster(Player* player, Inventory<Item>& inventory) {
//	cout << endl;
//	Monster* monster = nullptr;
//	if (rand() % 2) {
//		monster = new Slim("슬라임", 30, 20, 10, 5);
//	}
//	else {
//		monster = new Goblin("고블린", 40, 10, 5, 10);
//	}
//	cout << "[ 전투 시작! ] " << player->getName() << " vs " << monster->getName() << endl;
//	while (player->getHp() > 0 && monster->getHp() > 0)
//	{
//		Util::wait(300);
//		cout << endl;
//		cout << "<" << player->getName() << ": " << player->getHp() << "/" << player->getMaxHp() << " vs " << monster->getName() << ": " << monster->getHp() << "/" << monster->getMaxHp() << ">" << endl;
//		cout << "--- 플레이어 턴---" << endl;
//		cout << "1. 공격한다  2. 아이템 사용  3. 도망간다" << endl;
//		cout << "선택: ";
//		int choice = 0;
//		cin >> choice;
//		if (cin.fail()) {
//			cin.clear();
//			cin.ignore(numeric_limits<streamsize>::max(), '\n');
//			cout << "잘못된 입력입니다. 다시 입력해주세요: ";
//			cout << endl;
//			continue;
//		}
//		switch (choice)
//		{
//		case 1:
//			player->attack(monster);
//			if (monster->getHp() <= 0) {
//				break;
//			}
//			monster->attack(player);
//			break;
//		case 2:
//			inventory.printInventory();
//			cin.ignore(numeric_limits<streamsize>::max(), '\n');
//			inventory.useItem(player);
//			break;
//		case 3:
//			cout << "도망에 성공했습니다!" << endl;
//			delete monster;
//			return false;
//		default:
//			cout << "잘못된 입력입니다. 다시 입력해주세요: ";
//			cout << endl;
//			break;
//		}
//	}
//	if (player->getHp() <= 0) {
//		cout << "플레이어가 패배했습니다." << endl;
//		delete monster;
//		return false;
//	}
//	else if (monster->getHp() <= 0) {
//		cout << endl;
//		Util::slowPrint("몬스터를 처치했습니다.", 10);
//		cout << endl;
//		Util::wait(30);
//		cout << "★ 전투 승리!" << endl;
//		player->GainExp(monster);
//		cout << endl;
//
//		Util::wait(500);
//		cout << " -> " << monster->monsterLoot.name << " 획득!" << endl;
//		bool isFound = false;
//		for (int i = 0; i < inventory.inventory_list.size(); ++i) {
//			if (inventory.inventory_list[i].name == monster->monsterLoot.name) {
//				cout << " -> 인벤토리에 저장되었습니다." << endl;
//				inventory.inventory_list[i].count++;
//				isFound = true;
//			}
//		}
//		if (!isFound) {
//			if (inventory.inventory_list.size() < MAX_INVENTORY) {
//				cout << " -> 인벤토리에 저장되었습니다." << endl;
//				inventory.inventory_list.push_back(monster->monsterLoot);
//			}
//			else {
//				cout << "인벤토리가 가득 찼습니다. 아이템을 획득할 수 없습니다." << endl;
//			}
//		}
//
//		/*
//		if (inventory.inventory_list.size() < MAX_INVENTORY) {
//			cout << " -> 인벤토리에 저장되었습니다." << endl;
//			for (int i = 0; i < inventory.inventory_list.size(); ++i) {
//				if (inventory.inventory_list[i].name == monster->monsterLoot.name) {
//					inventory.inventory_list[i].count++;
//				}
//				else {
//					inventory.inventory_list.push_back(monster->monsterLoot);
//				}
//			}
//		}
//		else {
//			cout << "인벤토리가 가득 찼습니다. 아이템을 획득할 수 없습니다." << endl;
//		}*/
//		cout << endl;
//		delete monster;
//		return true;
//	}
//}