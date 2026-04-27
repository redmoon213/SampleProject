#pragma once
#include "Character.h"

class Monster : public Character
{
private:
    int expReward;
    std::string name;
	
public:
    Monster(const std::string& name,int str, int dex, int vit, int eng, int expReward, int lv=1);
    virtual ~Monster();
    
    int GetExpReward() const {return expReward;}
    std::string GetName() const{return name;}

    virtual std::string GetAttackMessage() const {return "";}
};
