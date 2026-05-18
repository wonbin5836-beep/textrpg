#pragma once
#include<iostream>
#include<string>
#include <map>
#include <memory>

using namespace std;

//enum class ItemType { CONSUMABLE, EQUIPMENT, LOOT};
//
//class Item {
//public:
//	int id;
//	string name;
//	ItemType type;
//	int price;
//	int count;
//	int maxStack;
//	Item(int id, std::string name, ItemType type, int count = 1, int maxStack = 5)
//		: id(id), name(name), type(type), count(count), maxStack(maxStack) {}
//	virtual ~Item() = default;
//	
//	void PrintInfo() const {
//		cout << name << "(" << price << "G)" << "x" << count << endl;
//	}
//	static bool compareByPrice(const Item& a, const Item& b) {
//		return a.price < b.price;
//	}
//};
//class Equipment : public Item {
//public:
//	int upgradeLevel;   // 강화 수치 (+1, +2...)
//	int durability;     // 내구도
//
//	Equipment(int id, std::string name, int durability)
//		: Item(id, name, ItemType::EQUIPMENT, 1, 1), upgradeLevel(0), durability(durability) {
//	}
//};


struct Item {
	string name;
	int price;
	int count;

	void PrintInfo() const {
		cout << name << "(" << price << "G)" << "x" << count << endl;
	}
	static bool compareByPrice(const Item& a, const Item& b) {
		return a.price < b.price;
	}
};