#include "Monster.h"
#include <iostream>
//생성자
Monster::Monster(int initHp, int initAtk): hp(initHp), maxhp(initHp), attackDamage(initAtk)
{
    cout << "<몬스터 생성>\nHP : " << hp << "/ Attack Damage : " << attackDamage << "\n";
}
//소멸자
Monster::~Monster()
{
    cout << "<몬스터 소멸>\n";
}
//TakeDamage
void Monster::TakeDamage(int damage)
{
    hp -= damage;
    if (hp<0) hp = 0; // hp 음수 방지
}
