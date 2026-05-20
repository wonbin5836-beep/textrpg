#pragma once
#include "common.h"
#include "Player.h"

class Monster;

class Warrior : public Player
{
private:

public:
	Warrior(std::string name, int maxHp, int maxMp, int atk, int def) : Player(name, maxHp+50, maxMp, atk, def+10) {
		this->job = "Warrior";
		std::cout << "* 전사로 전직하였습니다!(방어력 +10, HP +50)" << std::endl;
	}
	void attack(Monster* monster) override;
};
