#include "common.h"
#include "Slime.h"
#include "Player.h"

void Slime::attack(Player* player) {
	Util::slowPrint("* 슬라임이 공격을 산성 공격을 시전합니다.", 10);
	int damage = atk - player->getDef();
	if (damage <= 0) { damage = 0; }
	player->setHp(player->getHp() - damage);
	Util::slowPrint("* " + player->getName() + "에게 " + std::to_string(damage) + "의 피해를 입혔습니다.", 10);
}








