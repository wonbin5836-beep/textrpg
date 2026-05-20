#include "common.h"
#include "Archer.h"
#include "Monster.h"

void Archer::attack(Monster* monster) {
	Util::slowPrint("* [궁수] 차징 샷을(를) 시전합니다.", 10);
	int atkcount = 3;
	int damage = (atk - monster->getDef()) / atkcount;
	if (damage <= 0) { damage = 1; }
	Util::slowPrint("* " + monster->getName() + "에게 " + std::to_string(damage) + "(x" + std::to_string(atkcount) + ")의 피해를 입혔습니다.", 10);
	for (int i = 0; i < atkcount; i++) {
		monster->setHp(monster->getHp() - damage);
	}
}

