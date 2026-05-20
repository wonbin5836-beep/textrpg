#pragma once
#include "common.h"
#include "Monster.h"

class Player;

class Ork : public Monster
{
private:

public:
	Ork(std::string name, int hp, int mp, int atk, int def) : Monster(name, hp, mp, atk, def) {
		expReward = 100;
		monsterLoot = { "오크의 해골 토템 ", 30 ,1 };
		//std::cout << "* 오크" << endl;
	}
	void attack(Player* player) override;
};


