#ifndef NOVICE_H_
#define NOVICE_H_
#include "Player.h"
#include <string>
#include <iostream>
#include "Monster.h"
class Novice : public Player
{
private:

public:
	Novice(string name, int maxHp, int maxMp, int atk, int def) : Player(name, maxHp, maxMp, atk, def) {
		this->job = "Novice";
	}

	void attack(Monster* monster) override {
		cout << "직업이 없습니다." << endl;

	}
};
#endif
