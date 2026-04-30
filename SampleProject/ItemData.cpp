#include "ItemData.h"

//아이템 추가시 이 파일만 수정하면 됨

std::unordered_map<int, ItemData> CreateItemDB()
{
    //100번대는 Consumable / 200번대는 Weapon / 300번대는 Armor / 400번대는 ETC
    std::unordered_map<int, ItemData> db;
    db[101] = {"Healing Potion", ItemType::Consumable};
    db[102] = {"Mana Potion", ItemType::Consumable};
    db[103] = {"StoneSkin Potion", ItemType::Consumable};
    db[104] = {"Healing Potion", ItemType::Consumable};
    
    db[201] = {"Wood Swrod", ItemType::Weapon};
    db[202] = {"Iron Spear", ItemType::Weapon};
    db[203] = {"Copper dagger", ItemType::Weapon};
    db[204] = {"BearHammer", ItemType::Weapon};
    
    db[301] = {"Cloth Armor", ItemType::Armor};
    db[302] = {"Leather Boots", ItemType::Armor};
    db[303] = {"Iron Helmet", ItemType::Armor};
    db[304] = {"Copper Gloves", ItemType::Armor};

    
    db[401] = {"Iron Ore", ItemType::ETC};
    db[402] = {"Wood Stick", ItemType::ETC};
    db[403] = {"Rusty Coin", ItemType::ETC};
    
    return db;
}
