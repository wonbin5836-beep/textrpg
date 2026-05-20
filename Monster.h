#pragma once
#include<string>
#include "Item.h"  

class Player;

class Monster
{
protected:
    std::string name;
    int maxHp; //최대 체력
    int maxMp; //최대 마나
    int hp;  // 현재 체력
    int mp;  // 현재 마나
    int atk;
    int def;
	int expReward;
    
public:
    Item monsterLoot;

    Monster(std::string n, int h, int m, int a, int d)
        : name(n), maxHp(h), maxMp(m), hp(h), mp(m), atk(a), def(d), 
        expReward(30), monsterLoot ({ "전리품", 0 ,1 }) {}
    std::string getName() const { return name; }
    void ResetHP() {
        this->hp = this->maxHp;
    }
    int getHp() const { return hp; }
    int getMp() const { return mp; }
    int getMaxHp() const { return maxHp; }
    int getMaxMp() const { return maxMp; }
    int getAtk() const { return atk; }
    int getDef() const { return def; }
	int getExpReward() const { return expReward; }

    void setHp(int h) { hp = h; }
    void setMp(int m) { mp = m; }
    void setMaxHp(int h) { maxHp = h; }
    void setMaxMp(int m) { maxMp = m; }
    void setAtk(int a) { atk = a; }
    void setDef(int d) { def = d; }
    void setExpReward(int exp) { expReward = exp; }

    virtual void attack(Player* player) = 0;
    virtual ~Monster() {}
};
