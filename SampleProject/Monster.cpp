#include "Monster.h"
#include <iostream>
//생성자
Monster::Monster(const std::string& name, int str, int dex, int vit, int eng, int expReward, int lv)
    :Character(str, dex, vit, eng, lv), name(name), expReward(expReward)
{
    std::cout << "<몬스터 생성> [ " << name << " ]\n";
}
//소멸자
Monster::~Monster()
{
    std::cout << "<몬스터 소멸> [" << name << "]\n";
}
//TakeDamage
