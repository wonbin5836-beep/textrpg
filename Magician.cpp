#include "common.h"
#include "Magician.h"
#include "Monster.h"

void Magician::attack(Monster* monster) {
	Util::slowPrint("* [마법사] 파이어볼을(를) 시전합니다.", 10);
	int atkcount = 1;
	int damage = (atk - monster->getDef()) / atkcount;
	if (damage < 0) { damage = 0; }
	Util::slowPrint("* " + monster->getName() + "에게 " + std::to_string(damage) + "의 피해를 입혔습니다.", 10);
	for (int i = 0; i < atkcount; i++) {
		monster->setHp(monster->getHp() - damage);
	}
}

