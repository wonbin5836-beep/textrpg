#include "common.h"
#include "BOSS.h"
#include "Player.h"

void Boss::attack(Player* player) {
	Util::slowPrint("* " + name + "이 강력한 공격을 시전합니다.", 10);
	int damage = atk - player->getDef();
	if (damage <= 0) { damage = 0; }
	player->setHp(player->getHp() - damage);
	Util::slowPrint("* " + player->getName() + "에게 " + std::to_string(damage) + "의 피해를 입혔습니다.", 10);
}