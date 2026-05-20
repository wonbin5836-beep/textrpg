#include "common.h"
#include "Player.h"
#include "Dungen.h"
#include "Monster.h"
#include "AlchemyWorkshop.h"
#include "P_Player.h"

void printStatusUpgrade(Player* player) {
	std::cout << "================================================" << std::endl;
	std::cout << "< 캐릭터 강화 >    강화 포인트 : " << player->getStat() << std::endl;
	std::cout << "1. HP UP    2. MP UP    3. 공격력 UP" << std::endl;
	std::cout << "4. 방어력 UP    5. 현재 능력치    0. 돌아가기" << std::endl;
	std::cout << "================================================" << std::endl;

	bool isGameStart = false;
	int choice_up;
	while (!isGameStart) {
		std::cout << "번호를 선택해주세요:";
		std::cin >> choice_up;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "잘못된 입력입니다. 다시 입력해주세요.";
			continue;
		}
		switch (choice_up)
		{
		case 1:
			if (player->getStat() <= 0) {
				std::cout << "강화 포인트가 부족합니다." << std::endl;
				break;
			}
			else {
				player->setStat(player->getStat() - 1);
				player->setMaxHp(player->getMaxHp() + 20);
				player->setHp(player->getHp() + 20);
				std::cout << "HP가 20 증가하였습니다. (강화 포인트 차감: -1, 남은 포인트: " << player->getStat() << ")" << std::endl;
				break;
			}
		case 2:
			if (player->getStat() <= 0) {
				std::cout << "강화 포인트가 부족합니다." << std::endl;
				break;
			}
			else {
				player->setStat(player->getStat() - 1);
				player->setMaxMp(player->getMaxMp() + 20);
				player->setMp(player->getMp() + 20);
				std::cout << "MP가 20 증가하였습니다. (강화 포인트 차감: -1, 남은 포인트: " << player->getStat() << ")" << std::endl;
				break;
			}
		case 3:
			if (player->getStat() <= 0) {
				std::cout << "강화 포인트가 부족합니다." << std::endl;
				break;
			}
			else {
				player->setStat(player->getStat() - 1);
				player->setAtk(player->getAtk() + 5);
				std::cout << "공격력이 5 증가하였습니다. (강화 포인트 차감: -1, 남은 포인트: " << player->getStat() << ")" << std::endl;
				break;
			}
		case 4:
			if (player->getStat() <= 0) {
				std::cout << "강화 포인트가 부족합니다." << std::endl;
				break;
			}
			else {
				player->setStat(player->getStat() - 1);
				player->setDef(player->getDef() + 5);
				std::cout << "방어력이 5 증가하였습니다. (강화 포인트 차감: -1, 남은 포인트: " << player->getStat() << ")" << std::endl;
				break;
			}
		case 5:
			player->printPlayerStatus();
			break;
		case 0:
			std::cout << std::endl;
			std::cout << "돌아가기" << std::endl;
			isGameStart = true;
		}
	}
}

void printMainMenu(Dungen& dungen, Inventory<Item>& inventory, AlchemyWorkshop& workshop, Player* player) {
	while (true)
	{
		std::cout << std::endl;
		std::cout << "================" << std::endl;
		std::cout << " < 메인 메뉴 >" << std::endl;
		std::cout << " 1. 던전 입장" << std::endl;
		std::cout << " 2. 인벤토리 확인" <<std:: endl;
		std::cout << " 3. 포션 제작소" << std::endl;
		std::cout << " 4. 능력치 강화" << std::endl;
		std::cout << " 0. 게임 종료" << std::endl;
		std::cout << "================" << std::endl;
		int choice;
		std::cout << "선택: ";
		std::cin >> choice;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "잘못된 입력입니다. 다시 입력해주세요: ";
			continue;
		}
		switch (choice) {
		case 1:
				dungen.enterDungeon(player, inventory);
				break;
		case 2:
				inventory.printInventory();
				break;
		case 3:
				workshop.printPotionShop(inventory);
				break;
		case 4:
				printStatusUpgrade(player);
				break;
		case 0:
				std::cout << "게임을 종료합니다." << std::endl;
				exit(0);
		default:
			std::cout << "잘못된 선택입니다. 다시 입력해주세요." << std::endl;
			continue;
		}
	}
}


int main()
{
	const int inventory_size = 10;
	const int SIZE = 4;
	std::string name;
	Inventory<Item> inventory(inventory_size);
	AlchemyWorkshop workshop;
	Dungen dungen;
	int studs[SIZE] = { 0 }; // HP, MP, atk, def 순서로 저장
	int HPPotion = 0;
	int MPPotion = 0;
	std::cout << "";

	std::cout << "================================================" << std::endl;
	std::cout << "              [던전 탈출 텍스트 RPG]" << std::endl;
	std::cout << "================================================" << std::endl;
	std::cout << "주인공의 이름을 입력하세요:" << name;
	std::cin >> name;
	std::cout << std::endl;
	while (true)
	{
		std::cout << "현재 HP와 MP를 설정해주세요(max 100 50):";
		std::cin >> studs[0] >> studs[1];
		if(std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "잘못된 입력입니다. 다시 입력해주세요." << std::endl;
			continue;
		}
		if (studs[0] > 100 || studs[1] > 50)
		{
			std::cout << "HP와 MP는 값이 최댓값 보다 큽니다. 작게 설정해주세요." << std::endl;
		}
		else break;
	} 
	//hp mp설정
	while (true)
	{
		std::cout << "현재 공격력과 방어력을 설정해주세요(max 10 10):";
		std::cin >> studs[2] >> studs[3];
		if(std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "잘못된 입력입니다. 다시 입력해주세요." << std::endl;
			continue;
		}
		if (studs[2] > 10 || studs[3] > 10)
		{
			std::cout << "공격력과 방어력은 값이 최댓값 보다 큽니다. 작게 설정해주세요." << std::endl;
		}
		else break;
	} 
	//atk def 설정
	std::cout << std::endl;
	Player* player = nullptr;
	player = new Novice(name, studs[0], studs[1], studs[2], studs[3]);
	player->printPlayerStatus();
	std::cout << std::endl;
	std::cout << "* HP 포션 5개, MP 포션 5개가 기본 지급되었습니다." << std::endl;
	workshop.setPotion(5, &HPPotion, &MPPotion);
	inventory.AddItem({ "HP포션", 6, HPPotion });
	inventory.AddItem({ "MP포션", 7, MPPotion });
	std::cout << std::endl;
	
	
	printStatusUpgrade(player);

	std::cout << std::endl;
	std::cout << std::endl;
	
	std::cout << "< 전직 시스템 >" << std::endl;
	std::cout << name << "님, 직업을 선택해주세요!" << std::endl;
	std::cout << "1. 전사  2. 마법사  3. 도적  4. 궁수" << std::endl;
	bool isJobSelect = false;
	std::string currentName = player->getName();
	int currentHp = player->getMaxHp();
	int currentMp = player->getMaxMp();
	int currentAtk = player->getAtk();
	int currentDef = player->getDef();
	delete player;
	int choice;
	while (!isJobSelect)
	{
		std::cout << "번호를 입력하세요: ";
		std::cin >> choice;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "잘못된 입력입니다. 다시 입력해주세요." << std::endl;
			continue;
		}
		switch (choice)
		{
		case 1:
			player = new Warrior(currentName, currentHp, currentMp, currentAtk, currentDef);
			isJobSelect = true;
			break;
		case 2:
			player = new Magician(currentName, currentHp, currentMp, currentAtk, currentDef);
			isJobSelect = true;
			break;
		case 3:
			player = new Thief(currentName, currentHp, currentMp, currentAtk, currentDef);
			isJobSelect = true;
			break;
		case 4:
			player = new Archer(currentName, currentHp, currentMp, currentAtk, currentDef);
			isJobSelect = true;
			break;
		default:
			std::cout << "잘못된 입력입니다." << std::endl;
			break;
		}
	}
	
	player->printPlayerStatus();
	std::cout << std::endl;
	std::cout << std::endl;

	printMainMenu(dungen, inventory, workshop, player);
	

	/*cout << endl; 
	cout << endl;
	cout << "던전 입장!" << endl;
	cout << "." << endl;
	cout << "." << endl;
	cout << "탐색중" << endl;
	cout << "." << endl;
	cout << "." << endl;
	cout << "!" << endl;
	cout << endl;
	cout << "몬스터가 나타났다!" << endl;
	Monster* monster = new Slim("슬라임", 30, 20, 10, 5);

	cout << "[ 전투 시작! ] " <<player->getName() << " vs " << monster->getName() << endl;
	cout << "--- 플레이어 턴---" << endl;
	cout << "1. 공격한다  2. 아이템 사용  3. 도망간다" << endl;
	cout << "선택: "; 
	
	while (player->getHp() > 0 && monster->getHp() > 0)
	{
		choice = 0;
		cin >> choice;		

		if (cin.fail()) {
			cin.clear();			
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "잘못된 입력입니다. 다시 입력해주세요: ";
			cin >> choice;
			continue;
		}
		switch (choice)
		{
			case 1:
				player->attack(monster);
				if (monster->getHp() <= 0) {
					break;
				}
				monster->attack(player);
				break;
			case 2:
				break;
			case 3:
				break;
			default:
				cout << "잘못된 입력입니다. 다시 입력해주세요: ";
				break;
		}		
	}
	
	if(player->getHp() <= 0) {
		cout << "플레이어가 패배했습니다." << endl;
		cout << endl;
		cout << "다시 도전 하시겠습니까?" << endl;
		cout << "1. 예  2. 아니오" << endl;
		bool isRetrySelect = false;
		while (!isRetrySelect)
		{
			cout << "선택: ";
			cin >> choice;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "잘못된 입력입니다. 다시 입력해주세요: ";
				cin >> choice;
				continue;
			}
			switch (choice)
			{
			case 1:
				main();
				isRetrySelect = true;
				break;
			case 2:
				cout << "게임을 종료합니다." << endl;
				isRetrySelect = true;
				return 0;
				break;
			default:
				cout << "잘못된 입력입니다." << endl;
				break;
			}
		}
	}
	else if(monster->getHp() <= 0) {
		cout << "몬스터를 처치했습니다." << endl;
		cout << endl;
		cout << endl;
		cout << "★ 전투 승리!" << endl;
		cout << "-> 슬라임의 끈적한 젤리 획득!" << endl;
		cout << "-> 인벤토리에 저장되었습니다." << endl;
		Item slimeJelly = { "슬라임의 끈적한 젤리", 10 };
		inventory.inventory_list.push_back(slimeJelly);
		cout << endl;
		printMainMenu(dungen, inventory, workshop);
		
	}*/

	

	delete player;
}          