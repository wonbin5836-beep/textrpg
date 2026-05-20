#pragma once
#include "common.h"
#include "Player.h"

class Monster;

class Archer : public Player
{
private:

public:
	Archer(std::string name, int maxHp, int maxMp, int atk, int def) : Player(name, maxHp+25, maxMp, atk + 5, def) {
		this->job = "Archer";
		std::cout << "* 궁수로 전직하였습니다!(공격력 +5, HP +25)" << std::endl;
	}
	void attack(Monster* monster) override;
};