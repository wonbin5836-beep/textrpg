#include "common.h"
#include "Goblin.h"
#include "Player.h"

void Goblin::attack(Player* player) {
	Util::slowPrint("* 고블린이 공격을 마구 베기를 시전합니다.", 10);
	int atkcount = 3;
	int damage = (atk - player->getDef()) / atkcount;
	if (damage <= 0) { damage = 0; }
	Util::slowPrint("* " + player->getName() + "에게 " + std::to_string(damage) + "(x" + std::to_string(atkcount) + ")의 피해를 입혔습니다.", 10);
	for (int i = 0; i < atkcount; i++) {
		player->setHp(player->getHp() - damage);
	}
}