#include "common.h"


void Boss::attack(Player* player) {
	Util::slowPrint(std::string("* ") +name+ "이 공격을 시전합니다.", 10);
	int damage = this->atk - player->getDef();
	if (damage < 0) damage = 0;
	player->setHp(player->getHp() - damage);
	Util::slowPrint("* " + player->getName() + "에게 " + std::to_string(damage) + "의 피해를 입혔습니다.", 10);
}