#pragma once
#include "common.h"
#include "Player.h"

class Monster;

class Thief : public Player
{
private:

public:
	Thief(std::string name, int maxHp, int maxMp, int atk, int def) : Player(name, maxHp, maxMp, atk+15, def-10) {
		this->job = "Thief";
		std::cout << "* 도적으로 전직하였습니다!(공격력 +15, 방어력 -10)" << std::endl;
	}
	void attack(Monster* monster) override;
	
};
