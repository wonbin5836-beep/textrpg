#ifndef ARCHER_H_
#define ARCHER_H_
#include "common.h"

class Archer : public Player
{
private:

public:
	Archer(string name, int maxHp, int maxMp, int atk, int def) : Player(name, maxHp+25, maxMp, atk + 5, def) {
		this->job = "Archer";
		cout << "* 궁수로 전직하였습니다!(공격력 +5, HP +25)" << endl;	
	}
	void attack(Monster* monster) override;
};
#endif