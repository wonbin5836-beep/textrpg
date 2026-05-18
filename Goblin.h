#ifndef GOBLIN_H_
#define GOBLIN_H_
#include "common.h"

class Goblin : public Monster
{
private:

public:
	Goblin(string name, int hp, int mp, int atk, int def) : Monster(name, hp, mp, atk, def) {
		expReward = 75;
		monsterLoot = { "°íºí¸°ÀÇ ³ì½¼ °Ë", 20 ,1 };
		//cout << "* °íºí¸°" << endl;
	}
	void attack(Player* player) override;
};


#endif
