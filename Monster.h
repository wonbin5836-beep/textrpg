#ifndef MONSTER_H_
#define MONSTER_H_
#include<string>
#include"Item.h"
using namespace std;  

class Player;  

class Monster
{
protected:
    string name;
    int maxHp;
    int maxMp;
    int hp;
    int mp;
    int atk;
    int def;
	int expReward;
    
public:
    Item monsterLoot;

    Monster(string n, int h, int m, int a, int d)
        : name(n), maxHp(h), maxMp(m), hp(h), mp(m), atk(a), def(d), 
        expReward(30), monsterLoot ({ "Àü¸®Ç°", 0 ,1 }) {}
    string getName() const { return name; }
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




#endif

