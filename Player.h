#pragma once
#include "common.h"

class Monster; 

class Player 
{
protected:
	std::string name, job;
	int maxHp, hp, maxMp, mp, atk, def, exp, maxExp, level, stat;

public:
	Player(std::string name, int maxHp, int maxMp, int atk, int def) : name(name), maxHp(maxHp), hp(maxHp), maxMp(maxMp), mp(maxMp), atk(atk), def(def), exp(0), maxExp(100), level(1), job("a"), stat(5){}
	void printPlayerStatus();
	void setMaxHp(int maxHp) { this->maxHp = maxHp; }
	void setMaxMp(int maxMp) { this->maxMp = maxMp; }
	void setHp(int hp) { this->hp = hp; }
	void setMp(int mp) { this->mp = mp; }
	void setAtk(int atk) { this->atk = atk; }
	void setDef(int def) { this->def = def; }
	void setLevel(int level) { this->level = level; }
	void setExp(int exp) { this->exp = exp; }
	void setMaxExp(int maxExp) { this->maxExp = maxExp; }
	void setStat(int stat) { this->stat = stat; }

	std::string getName() { return name; }
	int getMaxHp() { return maxHp; }
	int getMaxMp() { return maxMp; }
	int getHp() { return hp; }
	int getMp() { return mp; }
	int getAtk() { return atk; }
	int getDef() { return def; }
	int getLevel() { return level; }	
	int getExp() { return exp; }
	int getMaxExp() { return maxExp; }
	int getStat() { return stat; }

	void GainExp(Monster* monster);

	virtual void attack(Monster* monster) = 0; 
	virtual ~Player() {}
};
