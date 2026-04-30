#pragma once
#include <memory>
#include <vector>

#include "Character.h"
#include "Item.h"

class Monster : public Character
{
private:
    int expReward;
    std::string name;
	Item itemReward ;

    std::vector<int>dropPool; // 몬스터가 드롭 가능한 아이템 ID 목록
    
public:
    Monster(const std::string& name,int str, int dex, int vit, int eng, 
        int expReward, int lv=1, std::vector<int> dropPool = {});
    virtual ~Monster();
    
    int GetExpReward() const {return expReward;}
    std::string GetName() const{return name;}

    virtual std::string GetAttackMessage() const {return "";}
    virtual int DropItem() const; // 몬스터 처치시 아이템이 드롭되게함
    
};
