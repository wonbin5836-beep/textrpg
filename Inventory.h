//#pragma once 
//#include"common.h"
//using namespace std;
//
//class Player;
//
//template<typename T>
//class Inventory {
//private:
//	map<int, shared_ptr<T>> slots;
//	T* pItems_;
//	int capacity_;
//	int size_;
//public:
//	Inventory(int capacity) :capacity_(capacity), size_(0) {
//		pItems_ = new T[capacity_];
//	}
//	~Inventory() {
//		delete[] pItems_;
//	}
//	Inventory(const Inventory& other) {
//		capacity_ = other.capacity_;
//		size_ = other.size_;
//		pItems_ = new T[capacity_];
//		for (int i = 0; i < size_; i++) {
//			pItems_[i] = other.pItems_[i];
//		}
//	}
//
//	Inventory& operator=(const Inventory& other) {
//		if (this == &other) { return *this; }
//		delete[] pItems_;
//		capacity_ = other.capacity_;
//		size_ = other.size_;
//		pItems_ = new T[capacity_];
//		for (int i = 0; i < size_; i++) {
//			pItems_[i] = other.pItems_[i];
//		}
//		return *this;
//	}
//	void AddItem(const T& item) {
//		for (int i = 0; i < size_; ++i) {
//			if (pItems_[i].name == item.name) {
//				pItems_[i].count += item.count;
//				cout << " -> 인벤토리에 저장되었습니다." << endl;
//				return;
//			}
//		}
//		if (size_ >= capacity_) {
//			cout << "인벤토리가 가득 차서 아이템을 추가할 수 없습니다." << endl;
//			cout << "확장 하시겠습니까?(y/n):";
//			char choice_inventory;
//			cin >> choice_inventory;
//			if (choice_inventory == 'y') {
//				cout << "인벤토리가 " << capacity_ << "에서" << capacity_ * 2 << "이 되었습니다." << endl;
//				Resize(capacity_ * 2);
//				AddItem(item);
//				SortItems();
//			}
//			else { cout << "아이템을 버렸습니다." << endl; }
//			return;
//		}
//		pItems_[size_] = item;
//		size_++;
//		cout << " -> 인벤토리에 새롭게 저장되었습니다." << endl;
//	}
//	void RemoveItem(const T& item) {
//		for (int i = 0; i < size_; i++) {
//			if (pItems_[i].name == item.name) {
//				for (int j = i; j < size_ - 1; j++)
//				{
//					pItems_[j] = pItems_[j + 1];
//				}
//				size_--;
//				return;
//			}
//		}
//	}
//
//	void printInventory() const {
//		cout << "[인벤토리 (" << size_ << " / 10)]" << endl;
//		for (int i = 0; i < size_; i++) {
//			cout << i + 1 << ". ";
//			pItems_[i].PrintInfo();
//		}
//	}
//
//	void useItem(Player* player) {
//		if (size_ == 0) {
//			cout << "인벤토리가 텅 비어 있습니다." << endl;
//			return;
//		}// [보안 추가] 인벤토리가 비어있을 때의 예외 처리
//		int choice;
//		while (true) {
//			cout << "사용할 아이템 번호 (취소 0번): ";
//			cin >> choice;
//			if (cin.fail()) {
//				cin.clear();
//				cin.ignore(numeric_limits<streamsize>::max(), '\n');
//				cout << "잘못된 입력입니다. 다시 입력해주세요: ";
//				continue;
//			}
//			if (choice == 0) {
//				cout << "아이템 사용을 취소했습니다." << endl;
//				return;
//			}
//			if (choice < 1 || choice > size_) {
//				cout << "잘못된 번호입니다. (0부터 " << size_ << "까지 입력 가능)" << endl;
//				continue;
//			}
//			break;
//		}
//		T& selectedItem = pItems_[choice - 1];
//		int OldHp = player->getHp();
//		int OldMp = player->getMp();
//		if (selectedItem.name == "HP 포션") {
//			player->setHp(min(player->getHp() + 50, player->getMaxHp()));
//			cout << "* HP 포션 사용! HP 50 회복 (" << OldHp << "-> " << player->getHp() << ")" << endl;
//		}
//		else if (selectedItem.name == "MP 포션") {
//			player->setMp(min(player->getMp() + 50, player->getMaxMp()));
//			cout << "* MP 포션 사용! MP 50 회복 (" << OldMp << "-> " << player->getMp() << ")" << endl;
//		}
//		else {
//			cout << "사용 할 수 없는 아이템입니다." << endl;
//			return;
//		}
//		if (selectedItem.count <= 1) {
//			RemoveItem(selectedItem);
//		}
//		else {
//			selectedItem.count--;
//		}
//	}
//	void Resize(int newCapacity) {
//		T* pItems2 = new T[newCapacity];
//		int copySize = (size_ < newCapacity) ? size_ : newCapacity;
//		for (int i = 0; i < copySize; i++) {
//			pItems2[i] = pItems_[i];
//		}
//		delete[] pItems_;
//		pItems_ = pItems2;
//		capacity_ = newCapacity;
//		size_ = copySize;
//	}
//
//	void SortItems() {
//		sort(pItems_, pItems_ + size_, T::compareByPrice);
//	}
//
//	int getSize() const { return size_; }
//	int getCapacity() const { return capacity_; }
//};
//class Inventory {
//public:
//	std::vector<Item> inventory_list;
//	void printInventory() const;
//	void useItem(Player* player);
//};

#pragma once 
#include"common.h"
#include "Item.h"
#include "Player.h"

template<typename T>
class Inventory {
private:

	T* pItems_;
	int capacity_;
	int size_;
public:
	Inventory(int capacity) :capacity_(capacity), size_(0) {
		pItems_ = new T[capacity_];
	}
	~Inventory() {
		delete[] pItems_;
	}
	Inventory(const Inventory& other) {
		capacity_ = other.capacity_;
		size_ = other.size_;
		pItems_ = new T[capacity_];
		for (int i = 0; i < size_; i++) {
			pItems_[i] = other.pItems_[i];
		}
	}
	
	Inventory& operator=(const Inventory& other) {
		if (this == &other) { return *this; }
		delete[] pItems_;
		capacity_ = other.capacity_;
		size_ = other.size_;
		pItems_ = new T[capacity_];
		for (int i = 0; i < size_; i++) {
			pItems_[i] = other.pItems_[i];
		}
		return *this;
	}
	void AddItem(const T& item) {
		for (int i = 0; i < size_; ++i) {
			if (pItems_[i].name == item.name) {
				pItems_[i].count += item.count;
				std::cout << " -> 인벤토리에 저장되었습니다." << std::endl;
				SortItems();
				return;
			}
		}
		if (size_ >= capacity_) {
			std::cout << "인벤토리가 가득 차서 아이템을 추가할 수 없습니다." << std::endl;
			std::cout << "확장 하시겠습니까?(y/n):";
			char choice_inventory;
			std::cin >> choice_inventory;
			if (choice_inventory == 'y') {
				std::cout << "인벤토리가 " << capacity_ <<"에서"<< capacity_ *2 << "이 되었습니다." << std::endl;
				Resize(capacity_ * 2);
				AddItem(item);
			}
			else { std::cout << "아이템을 버렸습니다." << std::endl; }
			return;
		}
		pItems_[size_] = item;
		size_++;
		std::cout << " -> 인벤토리에 새롭게 저장되었습니다." << std::endl;
		SortItems();
	}
	void RemoveItem(const T& item){
		for (int i = 0; i < size_; i++) {
			if (pItems_[i].name == item.name) {
				for (int j = i; j < size_ - 1; j++)
				{
					pItems_[j] = pItems_[j + 1];
				}
				size_--;
				return;
			}
		}
	}

	void printInventory() const {
		std::cout << "[인벤토리 (" << size_ << " / "<< capacity_ << ")]" << std::endl;
		for (int i = 0; i < size_; i++) {
			std::cout << i + 1 << ". ";
			pItems_[i].PrintInfo();
		}
	}

	void useItem(Player* player) {
		if (size_ == 0) {
			std::cout << "인벤토리가 텅 비어 있습니다." << std::endl;
			return;
		}
		int choice;
		while (true) {
			std::cout << "사용할 아이템 번호 (취소 0번): ";
			std::cin >> choice;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "잘못된 입력입니다. 다시 입력해주세요: ";
				continue;
			}
			if (choice == 0) {
				std::cout << "아이템 사용을 취소했습니다." << std::endl;
				return;
			}
			if (choice < 1 || choice > size_) {
				std::cout << "잘못된 번호입니다. (0부터 " << size_ << "까지 입력 가능)" << std::endl;
				continue;
			}
			break;
		}
		T& selectedItem = pItems_[choice - 1];
		int OldHp = player->getHp();
		int OldMp = player->getMp();
		if (selectedItem.name == "HP포션") {
			player->setHp(std::min(player->getHp() + 50, player->getMaxHp()));
			std::cout << "* HP 포션 사용! HP 50 회복 (" << OldHp << "-> " << player->getHp() << ")" << std::endl;
		}
		else if (selectedItem.name == "MP포션") {
			player->setMp(std::min(player->getMp() + 50, player->getMaxMp()));
			std::cout << "* MP 포션 사용! MP 50 회복 (" << OldMp << "-> " << player->getMp() << ")" << std::endl;
		}
		else {
			std::cout << "사용 할 수 없는 아이템입니다." << std::endl;
			return;
		}
		if (selectedItem.count <= 1) {
			RemoveItem(selectedItem);
		}
		else {
			selectedItem.count--;
		}
	}
	void Resize(int newCapacity) {
		T* pItems2 = new T[newCapacity];
		int copySize = (size_ < newCapacity) ? size_ : newCapacity;
		for (int i = 0; i < copySize; i++) {
			pItems2[i] = pItems_[i];
		}
		delete[] pItems_;
		pItems_ = pItems2;
		capacity_ = newCapacity;
		size_ = copySize;
	}

	void SortItems() {
		std::sort(pItems_, pItems_ + size_, T::compareByPrice);
	}

	int getSize() const { return size_; }
	int getCapacity() const { return capacity_; }
};
//class Inventory {
//public:
//	std::vector<Item> inventory_list;
//	void printInventory() const;
//	void useItem(Player* player);
//};