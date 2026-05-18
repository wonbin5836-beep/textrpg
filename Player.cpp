#include "common.h"

void Player::printPlayerStatus()
{
	cout << "================================================" << endl;
	cout << "닉네임: " << name << " | 직업: " << job << " | lv."<< level<< " | Exp: " << exp << "/" << maxExp << endl;
	cout << "================================================" << endl;
	cout << "HP: " << hp <<"/"<< maxHp << " | MP: " << mp << "/" << maxMp;
	cout << " | 공격력: " << atk << " | 방어력: " << def << endl;
	cout << "================================================" << endl;
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
	cout << " -> 경험치 +" << monster->getExpReward() << " 획득!(현재 경험치 : " << exp << " / " << maxExp << ")" << endl;
	while (levelup > 0) {
			maxHp += 10;
			maxMp += 5;
			hp = maxHp;
			mp = maxMp;
			atk += 5;
			cout << " -> 레벨 업! Lv." << level << " -> Lv." << level + 1 << endl;
			level++;
			Util::wait(150);
			cout << " -> HP +10, MP +5, 공격력 +5 증가!" << endl;
			stat += 4;
			levelup--;
	}
	Util::wait(300);
}