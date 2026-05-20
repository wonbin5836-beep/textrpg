#pragma once
#include "common.h"
#include "Inventory.h"

struct PotionRecipe
{
    std::string name;
    std::string ingredients1;
    std::string ingredients2;

    void ShowRecipe() const {
        std::cout << "-> " << name << " (" << ingredients1 << " x1, " << ingredients2 << " x1)" << std::endl;
    }
};

class AlchemyWorkshop {
private:
    static const std::vector<PotionRecipe> DEFAULT_RECIPE;
    static const int MAX_STOCK = 3;
public:
    std::map<std::string, int> potionStock_;
    AlchemyWorkshop();
    std::string name;
    std::string ingredient;
    std::vector<PotionRecipe> potion_list = DEFAULT_RECIPE;

    void printPotionShop(Inventory<Item>& inventory);
    void ShowAllRecipe();
    void BuyPotion(std::string name, Inventory<Item>& inventory);
    void AddPotion(Inventory<Item>& inventory, std::string name);
    bool DispensePotion(std::string name);
    void ReturnPotion(std::string name);
    int GetStock(std::string name);
    void SearchByPotionName(std::string name);
    void SearchByIngredient(std::string ingredient);
    void setPotion(int count, int* p_HPPotion, int* p_MPPotion);
};
