#include "Monster.h"
#include <iostream>
//생성자
Monster::Monster(int str, int dex, int vit, int eng, int expReward, int lv)
    :Character(str, dex, vit, eng, lv), expReward(expReward)
{
    std::cout << "<몬스터 생성>\nHP : " << hp << "/ Attack Damage : " << attackDamage << "\n";
}
//소멸자
Monster::~Monster()
{
    std::cout << "<몬스터 소멸>\n";
}
//TakeDamage
