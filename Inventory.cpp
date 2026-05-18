//#include "common.h"
//
//
//void Inventory::printInventory() const {
//	cout << "[인벤토리 (" << inventory_list.size() << " / 10)]" << endl;
//	int i = 1;
//	for (const auto& item : inventory_list) {
//		cout << i++ << ". ";
//		item.PrintInfo();
//	}
//}
//void Inventory::useItem(Player* player) {
//	if (inventory_list.empty()) {
//		cout << "인벤토리가 텅 비어 있습니다." << endl;
//		return;
//	}// [보안 추가] 인벤토리가 비어있을 때의 예외 처리
//	int choice;
//	while (true)
//	{
//		cout << "사용할 아이템 번호 (취소 0번): ";
//		cin >> choice;
//		if (cin.fail()) {
//			cin.clear();
//			cin.ignore(numeric_limits<streamsize>::max(), '\n');
//			cout << "잘못된 입력입니다. 다시 입력해주세요: ";
//			continue;
//		}
//		if (choice == 0) {
//			cout << "아이템 사용을 취소했습니다." << endl;
//			return;
//		}
//		if (choice < 1 || choice > inventory_list.size()) {
//			cout << "잘못된 번호입니다. (0부터 " << inventory_list.size() << "까지 입력 가능)" << endl;
//			continue;
//		}
//		break;
//	}
//	Item& selectedItem = inventory_list[choice - 1];
//
//	int OldHp = player->getHp();
//	int OldMp = player->getMp();
//	if (selectedItem.name == "HP 포션") {
//		player->setHp(min(player->getHp() + 50, player->getMaxHp()));
//		cout << "* HP 포션 사용! HP 50 회복 (" << OldHp << "-> " << player->getHp() << ")" << endl;
//	}
//	else if (selectedItem.name == "MP 포션") {
//		player->setMp(min(player->getMp() + 50, player->getMaxMp()));
//		cout << "* MP 포션 사용! MP 50 회복 (" << OldMp << "-> " << player->getMp() << ")" << endl;
//	}
//	else {
//		cout << "알 수 없는 아이템입니다." << endl;
//		return;
//	}	
//	if (selectedItem.count <= 1) {
//		inventory_list.erase(inventory_list.begin() + choice - 1);
//	}
//	else {
//		selectedItem.count--;
//	}
//	
//
//}