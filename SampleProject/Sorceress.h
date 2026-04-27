#pragma once
#include "Player.h"

class Sorceress : public Player
{
public:
    Sorceress(const std::string& name, bool isHardcore);
    int Attack() const override;
    std::string GetAttackMessage() const override{return "[Frozen Orb!]";}
};
