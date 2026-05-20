#pragma once
#include "common.h"
#include "Player.h"

class Monster;

class Magician : public Player
{
private:

public:
	Magician(std::string name, int maxHp, int maxMp, int atk, int def) : Player(name, maxHp, maxMp + 50, atk, def) {
		this->job = "Magician";
		std::cout << "* 마법사로 전직하였습니다!(MP +50)" << std::endl;
	}
	void attack(Monster* monster) override ;
}; 
