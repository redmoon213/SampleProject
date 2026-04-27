#pragma once
#include "Monster.h"

class FireGoblin : public Monster
{
public:
    FireGoblin(const std::string& name, int str, int dex, int vit, int eng, int expReward, int lv=1);
    
    int Attack() const override;
    std::string GetAttackMessage() const override {return "화염속성 공격!";}
    
    
};
