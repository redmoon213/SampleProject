#include "Monster.h"
#include <iostream>
//생성자
Monster::Monster(const std::string& name, int str, int dex, int vit, int eng, int expReward, int lv, std::vector<int> dropInput )
    :Character(str, dex, vit, eng, lv), name(name), expReward(expReward), dropPool(dropInput)
{}

Monster::Monster(const std::string& nameInput,const MonsterData& mData, int lv)
    :Character(mData.str, mData.dex, mData.vit, mData.eng, lv), 
    name(nameInput), expReward(mData.xpReward), dropPool(mData.dropPool)
{}

//소멸자
Monster::~Monster(){}

int Monster::DropItem() const
{
    srand(time(NULL));
    
    if (dropPool.empty() || rand() % 3 == 0) return -1;
    
    else return dropPool[rand()%dropPool.size()];
}
