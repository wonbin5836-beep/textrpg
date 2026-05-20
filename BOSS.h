#pragma once
#include "common.h"
#include "Monster.h"

class Player;

class Boss : public Monster
{
private:

public:
	Boss(std::string name, int hp, int mp, int atk, int def) : Monster(name, hp, mp, atk, def) {
		expReward = 400;
		monsterLoot = { "보스의 정수", 1000 ,1 };
		//std::cout << "* 보스" << endl;
	}
	void attack(Player* player) override;
};


