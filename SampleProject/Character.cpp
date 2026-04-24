#include "Character.h"


Character::Character(int str, int dex, int vit, int engergy, int lv)
    : strength(str), dexterity(dex), vitality(vit), energy(energy), level(lv), //매개 변수 초기화
fireResist(0), coldResist(0), lightningResist(0), poisonResist(0)   // 고정값 초기화
{
    maxHp = vitality * 3;
    hp = maxHp;
    maxMp = energy * 2;
    mp = maxMp;
		
    attackDamage = (float)strength * 0.2;
    attackSpeed = (float)dexterity * 0.1;
    movingSpeed = (float)dexterity / 30.0;
}
Character::~Character()
{
    
}
void Character::TakeDamage(int damage)
{
    hp-=damage;
    if(hp<0) hp=0;
}

int Character::Attack() const{return (int)attackDamage;}

bool Character::isAlive() const{return hp>0;}
