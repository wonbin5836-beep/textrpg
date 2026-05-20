#include "common.h"
#include "Thief.h"
#include "Monster.h"

void Thief::attack(Monster* monster) {
	Util::slowPrint("* [도적] 단검 찌르기을(를) 시전합니다.", 10);
	int atkcount = 5;
	int damage = (atk - monster->getDef()) / atkcount;
	if (damage <= 0) { damage = 1; }
	Util::slowPrint("* " + monster->getName() + "에게 " + std::to_string(damage) + "(x" + std::to_string(atkcount) + ")의 피해를 입혔습니다.", 10);
	for (int i = 0; i < atkcount; i++) {
		monster->setHp(monster->getHp() - damage);
	}
}