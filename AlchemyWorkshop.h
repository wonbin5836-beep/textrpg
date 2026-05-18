#pragma once
#include "common.h"
using namespace std;

struct PotionRecipe
{
    string name;
    string ingredients1;
    string ingredients2;

    void ShowRecipe() const {
        cout << "-> " << name << " (" << ingredients1 << " x1, " << ingredients2 << " x1)" << endl;
    }
};

class AlchemyWorkshop {
private:
    static const vector<PotionRecipe> DEFAULT_RECIPE;
    static const int MAX_STOCK = 3;
public:
    map<string, int> potionStock_;
    AlchemyWorkshop();
    string name;
    string ingredient;
    vector<PotionRecipe> potion_list = DEFAULT_RECIPE;

    void printPotionShop(Inventory<Item>& inventory);
    void ShowAllRecipe();
    void BuyPotion(string name, Inventory<Item>& inventory);
    void AddPotion(Inventory<Item>& inventory, string name);
    bool DispensePotion(string name);
    void ReturnPotion(string name);
    int GetStock(string name);
    void SearchByPotionName(string name);
    void SearchByIngredient(string ingredient);
    void setPotion(int count, int* p_HPPotion, int* p_MPPotion);
};
