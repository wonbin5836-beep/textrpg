#ifndef MAGICIAN_H_
#define MAGICIAN_H_
#include "common.h"
class Magician : public Player
{
private:

public:
	Magician(string name, int maxHp, int maxMp, int atk, int def) : Player(name, maxHp, maxMp + 50, atk, def) {
		this->job = "Magician";
		cout << "* 마법사로 전직하였습니다!(MP +50)" << endl;
	}
	void attack(Monster* monster) override ;
}; 

#endif