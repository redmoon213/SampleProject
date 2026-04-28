#pragma once
#include <string>

enum class ItemType{ Weapon, Armor, Consumable, ETC};


class Item
{
private:
    std::string name;
    ItemType type;
public:
    Item();
    Item(std::string, ItemType);
    ~Item();
    
    std::string GetItemName() const{return name;}
    ItemType GetItemType() const{return type;}
};
