#pragma once
#include "common.h"
#include "Player.h"
class Monster;

class Novice : public Player
{
private:

public:
	Novice(std::string name, int maxHp, int maxMp, int atk, int def) : Player(name, maxHp, maxMp, atk, def) {
		this->job = "Novice";
	}

	void attack(Monster* monster) override {
		std::cout << "직업이 없습니다." << std::endl;

	}
};
