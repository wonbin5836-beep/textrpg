#ifndef THIEF_H_	
#define THIEF_H_
#include "common.h"
class Thief : public Player
{
private:

public:
	Thief(string name, int maxHp, int maxMp, int atk, int def) : Player(name, maxHp, maxMp, atk+15, def-10) {
		this->job = "Thief";
		cout << "* 도적으로 전직하였습니다!(공격력 +15, 방어력 -10)" << endl;
	}
	void attack(Monster* monster) override;
	
};

#endif