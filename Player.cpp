#include "common.h"
#include "Player.h"
#include "Monster.h"

void Player::printPlayerStatus()
{
	std::cout << "================================================" << std::endl;
	std::cout << "닉네임: " << name << " | 직업: " << job << " | lv."<< level<< " | Exp: " << exp << "/" << maxExp << std::endl;
	std::cout << "================================================" << std::endl;
	std::cout << "HP: " << hp <<"/"<< maxHp << " | MP: " << mp << "/" << maxMp;
	std::cout << " | 공격력: " << atk << " | 방어력: " << def << std::endl;
	std::cout << "================================================" << std::endl;
}
void Player::GainExp(Monster* monster) {
	exp += monster->getExpReward();
	int levelup= 0;
	if (exp >= maxExp) {
		Util::slowPrint(". . . 레벨업 조건 충족", 50);
		while (exp >= maxExp) {
			exp -= maxExp;
			maxExp = static_cast<int>(maxExp * 1.2);
			levelup++;
		}
	}
	std::cout << " -> 경험치 +" << monster->getExpReward() << " 획득!(현재 경험치 : " << exp << " / " << maxExp << ")" << std::endl;
	while (levelup > 0) {
			maxHp += 10;
			maxMp += 5;
			hp = maxHp;
			mp = maxMp;
			atk += 5;
			std::cout << " -> 레벨 업! Lv." << level << " -> Lv." << level + 1 << std::endl;
			level++;
			Util::wait(150);
			std::cout << " -> HP +10, MP +5, 공격력 +5 증가! 강화포인트 +4 획득했습니다!" << std::endl;
			stat += 4;
			levelup--;
	}
	Util::wait(300);
}