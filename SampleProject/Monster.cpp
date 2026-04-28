#include "Monster.h"
#include <iostream>
//생성자
Monster::Monster(const std::string& name, int str, int dex, int vit, int eng, int expReward, int lv)
    :Character(str, dex, vit, eng, lv), name(name), expReward(expReward)
{
    //std::cout << "<몬스터 생성> [ " << name << " ]\n";
    
}
//소멸자
Monster::~Monster()
{
    //std::cout << "<몬스터 소멸> [" << name << "]\n";
}

std::unique_ptr<Item> Monster::DropItem() const
{
    srand(time(NULL));
    if (rand()%2 == 0) return nullptr;
    
    int itemRoll = rand() %3;
    if (itemRoll==0) return std::make_unique<Item>("Sort Sword", ItemType::Weapon);
    
    
    else if (itemRoll==1) return std::make_unique<Item>("Leather Armor",ItemType::Armor);
    
    
    else if (itemRoll ==2) return std::make_unique<Item>("Healing Potion", ItemType::Consumable);
    
   // return std::make_unique<Item>(itemReward);
}
