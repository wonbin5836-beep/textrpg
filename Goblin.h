#pragma once
#include "common.h"
#include "Monster.h"

class Player;

class Goblin : public Monster
{
private:

public:
	Goblin(std::string name, int hp, int mp, int atk, int def) : Monster(name, hp, mp, atk, def) {
		expReward = 75;
		monsterLoot = { "°íºí¸°ÀÇ ³ì½¼ °Ë", 20 ,1 };
		//std::cout << "* °íºí¸°" << endl;
	}
	void attack(Player* player) override;
};
