#pragma once
#include <memory>

#include "Character.h"
#include "Item.h"

class Monster : public Character
{
private:
    int expReward;
    std::string name;
	Item itemReward ;
public:
    Monster(const std::string& name,int str, int dex, int vit, int eng, int expReward, int lv=1);
    virtual ~Monster();
    
    int GetExpReward() const {return expReward;}
    std::string GetName() const{return name;}

    virtual std::string GetAttackMessage() const {return "";}
    virtual std::unique_ptr<Item> DropItem() const; // 몬스터 처치시 아이템이 드롭되게함
    
};
