#include "common.h"
#include "AlchemyWorkshop.h"


const std::vector<PotionRecipe> AlchemyWorkshop::DEFAULT_RECIPE ={
{ "HP포션", "허브", "맑은물" },
{ "MP포션", "마나허브", "맑은물" },
{ "스태미나포션", "마나허브", "베리" },
{ "방어포션", "베리", "허브" },
{ "공격력포션", "버섯", "허브" },
{ "하프포션", "버섯", "베리" }
};

AlchemyWorkshop::AlchemyWorkshop() {
	for (const auto& recipe : potion_list) {
		potionStock_[recipe.name] = MAX_STOCK;
	}
}

void AlchemyWorkshop::printPotionShop(Inventory<Item>& inventory) {
	while (true)
	{
		std::cout << std::endl;
		std::cout << "==== 포션 제작소 ====" << std::endl;
		std::cout << " 1. 전체 레시피 보기" << std::endl;
		std::cout << " 2. 포션 이름으로 검색" << std::endl;
		std::cout << " 3. 재료로 검색" << std::endl;
		std::cout << " 4. 포션 구매" << std::endl;
		std::cout << " 5. 공병 반환" << std::endl;
		std::cout << " 0. 돌아가기" << std::endl;
		int choice;
		std::cout << "선택: ";
		std::cin >> choice;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "잘못된 입력입니다. 다시 입력해주세요" << std::endl;
			continue;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		switch (choice)
		{
		case 1:
			ShowAllRecipe();
			break;
		case 2:
			std::cout << "검색할 포션 이름: ";
			getline(std::cin, name);
			SearchByPotionName(name);
			break;
		case 3:
			std::cout << "검색할 재료: ";
			getline(std::cin, ingredient);
			SearchByIngredient(ingredient);
			break;
		case 4:
			std::cout << "구매 포션 이름: ";
			getline(std::cin, name);
			BuyPotion(name, inventory);
			break;
		case 5:
			std::cout << "반환 포션 공병 이름: ";
			getline(std::cin, name);
			ReturnPotion(name);
			break;
		case 0:
			return;
		default:
			std::cout << "잘못된 입력입니다." << std::endl;
			break;
		}
	}
}

bool AlchemyWorkshop::DispensePotion(std::string name) {
	if (potionStock_[name] <= 0) {
		std::cout << " -> " << name << " 지급 실패 : 재고 없음!" << std::endl;
		return false;
	}
	if (potionStock_.find(name) == potionStock_.end()) {
		std::cout << " -> " << name << "은(는) 취급하지 않는 포션입니다." << std::endl;
		return false;
	}
	potionStock_[name]--;
	return true;
}

void AlchemyWorkshop::ReturnPotion(std::string name) {
	if (potionStock_.find(name) == potionStock_.end()) return;

	if (potionStock_[name] >= MAX_STOCK) {
		std::cout << " -> 더 이상 반납할 수 없습니다. (최대 재고 도달)" << std::endl;
		return;
	}
	potionStock_[name]++;
	std::cout << " -> 공병 반환" << " (남은 재고: " << GetStock(name) << ")" << std::endl;
	
}

int AlchemyWorkshop::GetStock(std::string name) {
	if (potionStock_.find(name) == potionStock_.end()) {
		return 0;
	}
	return potionStock_[name];
}

void AlchemyWorkshop::BuyPotion(std::string name, Inventory<Item>& inventory){
	bool recipeExists = false;
	for (const auto& recipe : potion_list) {
		if (recipe.name == name) {
			recipeExists = true;
			break;
		}
	}
	if (!recipeExists) {
		std::cout << " -> 상점에 존재하지 않는 포션 이름입니다." << std::endl;
		return;
	}
	if (DispensePotion(name)) {
		std::cout << " -> " << name << " 지급 완료! (남은 재고: " << GetStock(name) << ")" << std::endl;
		AddPotion(inventory, name);
	}
}

void AlchemyWorkshop::AddPotion(Inventory<Item>& inventory, std::string name) {
	inventory.AddItem({ name, 10 ,1 });
}

void AlchemyWorkshop::SearchByPotionName(std::string name) {
    int count = 0;
	std::string searchName = name;
	transform(searchName.begin(), searchName.end(), searchName.begin(), ::tolower);
    for (const auto& recipe : potion_list) {
		std::string recipeName = recipe.name;
        transform(recipeName.begin(), recipeName.end(), recipeName.begin(), ::tolower);
        if (recipeName.find(searchName) != std::string::npos) {
            recipe.ShowRecipe();
            count++;
        }
    }
    if (count > 0) {
		std::cout << "총 " << count << "개의 레시피를 찾았습니다." << std::endl;
    }
    else {
		std::cout << "포션 레시피를 찾을 수 없습니다." << std::endl;
    }
}
void AlchemyWorkshop::SearchByIngredient(std::string ingredient) {
    int count = 0;
    for (const auto& recipe : potion_list) {
        if (recipe.ingredients1 == ingredient || recipe.ingredients2 == ingredient) {
            recipe.ShowRecipe();
            count++;
        }
    }
    if (count > 0) {
		std::cout << "총 " << count << "개의 레시피를 찾았습니다." << std::endl;
    }
    else {
		std::cout << "포션 레시피를 찾을 수 없습니다." << std::endl;
    }
}
void AlchemyWorkshop::ShowAllRecipe()
{
	std::cout << "모든 포션 레시피:" << std::endl;
    for (const auto& recipe : potion_list) {
        recipe.ShowRecipe();
    }
}
void AlchemyWorkshop::setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
    *p_HPPotion = count;
    *p_MPPotion = count;
}
//포인터를 쓰지 않고 매개변수만 넘겼을 때 값이 바뀌지 않는 이유를 설명하기
//함수에 변수를 인자로 받게되면 함수내 지역 변수로만 계산 되어 함수가 종료되자마자 사라져버림 
//변수의 주소값을 가지는 포인터 변수를 인자로 받고 주소값 위치를 직접 변경하여 함수가 끝나도 값이 사라지지않게 하기위해