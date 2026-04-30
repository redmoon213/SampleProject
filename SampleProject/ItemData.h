#pragma once
#include <string>
#include <unordered_map>
#include "Item.h"

//Item 클래스는 추후 상속/기능 등이 추가 될 수 있기때문에
//ItemData 구조체로 데이터를 분리

struct ItemData
{
    std::string itemName;
    ItemType type;
};

std::unordered_map<int, ItemData> CreateItemDB();