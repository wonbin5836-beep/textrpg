#ifndef ORK_H_
#define ORK_H_
#include "common.h"
class Ork : public Monster
{
private:

public:
	Ork(string name, int hp, int mp, int atk, int def) : Monster(name, hp, mp, atk, def) {
		expReward = 100;
		monsterLoot = { "오크의 해골 토템 ", 30 ,1 };
		//cout << "* 오크" << endl;
	}
	void attack(Player* player) override;
};


#endif
