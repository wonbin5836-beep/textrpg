#ifndef WARRIOR_H_
#define WARRIOR_H_
#include "common.h"

class Warrior : public Player
{
private:

public:
	Warrior(string name, int maxHp, int maxMp, int atk, int def) : Player(name, maxHp+50, maxMp, atk, def+10) {
		this->job = "Warrior";
		cout << "* 전사로 전직하였습니다!(방어력 +10, HP +50)" << endl;
	}
	void attack(Monster* monster) override;
};


#endif