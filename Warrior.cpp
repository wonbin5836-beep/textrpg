#include "common.h"
#include "Warrior.h"
#include "Monster.h"

void Warrior::attack(Monster* monster) {
	Util::slowPrint("* [전사] 베기를 시전합니다.", 10);
	int atkcount = 1;
	int damage = (atk - monster->getDef()) / atkcount;
	if (damage < 0) { damage = 0; }
	Util::slowPrint("* " + monster->getName() + "에게 " + std::to_string(damage) + "의 피해를 입혔습니다.", 10);
	for (int i = 0; i < atkcount; i++) {
		monster->setHp(monster->getHp() - damage);
	}
}