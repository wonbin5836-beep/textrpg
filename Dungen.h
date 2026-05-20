#pragma once
#include "common.h"

class Player;
struct Item;
class Monster;
template<typename T>
class Inventory;

class Dungen {
public:
	std::vector<Monster*> a_route;
	std::vector<Monster*> b_route;
	Dungen();
	~Dungen();
	void enterDungeon(Player* player, Inventory<Item>& inventory);
	bool fightMonster(Player* player, Monster* monster, Inventory<Item>& inventory);
};


//if (dungen.fightMonster(player, monster, inventory)) {
//	Util::wait(1000);
//	cout << "던전 탐험을 계속합니다..." << endl;
//	Util::waitForKey();
//}
//else {
//	cout << "게임 오버!" << endl;
//	break;
//}