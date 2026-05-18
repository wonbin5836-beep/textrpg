#include "common.h"

using namespace std;

void printStatusUpgrade(Player* player) {
	cout << "================================================" << endl;
	cout << "< 캐릭터 강화 >    강화 포인트 : " << player->getStat()<< endl;
	cout << "1. HP UP    2. MP UP    3. 공격력 UP" << endl;
	cout << "4. 방어력 UP    5. 현재 능력치    0. 게임시작" << endl;
	cout << "================================================" << endl;
}

void printMainMenu(Dungen& dungen, Inventory<Item>& inventory, AlchemyWorkshop& workshop, Player* player) {
	while (true)
	{
		cout << endl;
		cout << "================" << endl;
		cout << " < 메인 메뉴 >" << endl;
		cout << " 1. 던전 입장" << endl;
		cout << " 2. 인벤토리 확인" << endl;
		cout << " 3. 포션 제작소" << endl;
		cout << " 4. 스테이터스" << endl;
		cout << " 0. 게임 종료" << endl;
		cout << "================" << endl;
		int choice;
		cout << "선택: ";
		cin >> choice;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "잘못된 입력입니다. 다시 입력해주세요: ";
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
				player->printPlayerStatus();
				break;
		case 0:
				cout << "게임을 종료합니다." << endl;
				exit(0);
		default:
			cout << "잘못된 선택입니다. 다시 입력해주세요." << endl;
			continue;
		}
	}
}


int main()
{
	const int inventory_size = 10;
	const int SIZE = 4;
	string name; 
	Inventory<Item> inventory(inventory_size);
	AlchemyWorkshop workshop;
	Dungen dungen;
	int studs[SIZE] = { 0 }; // HP, MP, atk, def 순서로 저장
	int HPPotion = 5;
	int MPPotion = 5;


	cout << "================================================" << endl;
	cout << "              [던전 탈출 텍스트 RPG]" << endl;
	cout << "================================================" << endl;
	cout << "주인공의 이름을 입력하세요:" << name;
	cin >> name;
	cout << endl;
	while (true)
	{
		cout << "현재 HP와 MP를 설정해주세요(max 100 50):";
		cin >> studs[0] >> studs[1];
		if(cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
			continue;
		}
		if (studs[0] > 100 || studs[1] > 50)
		{
			cout << "HP와 MP는 값이 최댓값 보다 큽니다. 작게 설정해주세요." << endl;
		}
		else break;
	} 
	//hp mp설정
	while (true)
	{
		cout << "현재 공격력과 방어력을 설정해주세요(max 10 10):";
		cin >> studs[2] >> studs[3];
		if(cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
			continue;
		}
		if (studs[2] > 10 || studs[3] > 10)
		{
			cout << "공격력과 방어력은 값이 최댓값 보다 큽니다. 작게 설정해주세요." << endl;
		}
		else break;
	} 
	//atk def 설정
	cout << endl;
	Player* player = nullptr;
	player = new Novice(name, studs[0], studs[1], studs[2], studs[3]);
	player->printPlayerStatus();
	cout << endl;
	cout << "* HP 포션 5개, MP 포션 5개가 기본 지급되었습니다." << endl;
	inventory.AddItem({ "HP포션", 6, HPPotion });
	inventory.AddItem({ "1포션", 1, HPPotion });
	inventory.AddItem({ "2포션", 2, HPPotion });
	inventory.AddItem({ "3포션", 3, HPPotion });
	inventory.AddItem({ "4포션", 4, HPPotion });
	inventory.AddItem({ "5포션", 5, HPPotion });
	inventory.AddItem({ "6포션", 6, HPPotion });
	inventory.AddItem({ "9포션", 30, HPPotion });
	inventory.AddItem({ "7포션", 34, HPPotion });

	inventory.AddItem({ "8포션", 10, HPPotion });

	cout << endl;
	workshop.setPotion(5, &HPPotion, &MPPotion);
	
	printStatusUpgrade(player);

	bool isGameStart = false;
	int choice;
	while (!isGameStart) {
		cout << "번호를 선택해주세요:";
		cin >> choice;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "잘못된 입력입니다. 다시 입력해주세요.";
			continue;
		}
		switch (choice)
		{
		case 1:
			if(player->getStat() <= 0) {
				cout << "강화 포인트가 부족합니다." << endl;
				break;
			}
			else {
				player->setStat(player->getStat() - 1);
				player->setMaxHp(player->getMaxHp() + 20);
				player->setHp(player->getHp() + 20);
				cout << "HP가 20 증가하였습니다. (강화 포인트 차감: -1, 남은 포인트: "<< player->getStat() <<")" << endl;
				break;
			}
		case 2:
			if (player->getStat() <= 0) {
				cout << "강화 포인트가 부족합니다." << endl;
				break;
			}
			else {
				player->setStat(player->getStat() - 1);
				player->setMaxMp(player->getMaxMp() + 20);
				player->setMp(player->getMp() + 20);
				cout << "MP가 20 증가하였습니다. (강화 포인트 차감: -1, 남은 포인트: " << player->getStat() << ")" << endl;
				break;
			}
		case 3:
			if (player->getStat() <= 0) {
				cout << "강화 포인트가 부족합니다." << endl;
				break;
			}
			else {
				player->setStat(player->getStat() - 1);
				player->setAtk(player->getAtk() + 5);
				cout << "공격력이 5 증가하였습니다. (강화 포인트 차감: -1, 남은 포인트: " << player->getStat() << ")" << endl;
				break;
			}
		case 4:
			if (player->getStat() <= 0) {
				cout << "강화 포인트가 부족합니다." << endl;
				break;
			}
			else {
				player->setStat(player->getStat() - 1);
				player->setDef(player->getDef() + 5);
				cout << "방어력이 5 증가하였습니다. (강화 포인트 차감: -1, 남은 포인트: " << player->getStat() << ")" << endl;
				break;
			}
		case 5:
			player->printPlayerStatus();
			break;
		case 0:
			cout << endl;
			cout << "게임을 시작합니다!" << endl;
			isGameStart = true;
		}
	}
	cout << endl;
	cout << endl;
	
	cout << "< 전직 시스템 >" << endl;
	cout << name << "님, 직업을 선택해주세요!" << endl;
	cout << "1. 전사  2. 마법사  3. 도적  4. 궁수" << endl;
	bool isJobSelect = false;
	string currentName = player->getName();
	int currentHp = player->getMaxHp();
	int currentMp = player->getMaxMp();
	int currentAtk = player->getAtk();
	int currentDef = player->getDef();
	delete player;
	
	while (!isJobSelect)
	{
		cout << "번호를 입력하세요: ";
		cin >> choice;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
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
			cout << "잘못된 입력입니다." << endl;
			break;
		}
	}
	
	player->printPlayerStatus();
	cout << endl;
	cout << endl;

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