#include "FireGoblin.h"

#include <iostream>

FireGoblin::FireGoblin(const std::string& name, int str, int dex, int vit, int eng, int expReward, int lv)
    :Monster(name, str, dex, vit, eng, expReward, lv)
{
    
}

int FireGoblin::Attack() const
{
    
    return (int)(attackDamage * 1.5);
}

std::unique_ptr<Item> FireGoblin::DropItem() const
{
    //srand(time(NULL));
    int itemRoll = rand()%2;
    
    if (itemRoll == 0)
    {
        return std::make_unique<Item>("화염반지",ItemType::ETC);
    }
    
    else if (itemRoll ==1)
    {
        return std::make_unique<Item>("화염의검",ItemType::Weapon);

    }
    
    return nullptr;
}
