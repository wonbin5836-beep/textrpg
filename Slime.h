#pragma once
#include "common.h"
#include "Monster.h"

class Player;

class Slime : public Monster
{
private:

public:
	Slime(std::string name, int hp, int mp, int atk, int def) : Monster(name, hp, mp, atk, def) {
		expReward = 40;
		monsterLoot = { "슬라임의 끈적한 젤리", 10 ,1 };
		//std::cout << "* 슬라임" << endl;
	}
	void attack(Player* player) override;
};