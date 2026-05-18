#ifndef SLIM_H_
#define SLIM_H_
#include "common.h"
class Slim : public Monster
{
private:

public:
	Slim(string name, int hp, int mp, int atk, int def) : Monster(name, hp, mp, atk, def) {
		expReward = 40;
		monsterLoot = { "슬라임의 끈적한 젤리", 10 ,1 };
		//cout << "* 슬라임" << endl;
	}
	void attack(Player* player) override;
};


#endif
