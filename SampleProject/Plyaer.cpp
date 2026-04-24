#include "Plyaer.h"
#include<string>
#include<iostream>
using namespace std;

Player::Player(const string& name, const string& characterClass, bool isHardcore)
: name(name), characterClass(characterClass), isHardcore(isHardcore), // 매개변수로 받는애들 초기화
    strength(50), dexterity(50), vitality(50), energy(50),
    level(1),
    fireResist(0), coldResist(0), lightningResist(0), poisonResist(0) //단순 값 세팅 하는애들 초기화
    //계산이 필요한건 중괄호 안에
    {
    maxHp = vitality * 3;
    hp = maxHp;
    maxMp = energy * 2;
    mp = maxMp;
		
    attackDamage = (float)strength * 0.2;
    attackSpeed = (float)dexterity * 0.1;
    movingSpeed = (float)dexterity / 30.0;
		
    for (int i =0; i<5; i++) inventory[i] = 0;
    }


void Player::TakeDamage(int damage)
{
	hp-=damage;
	if(hp<0) hp=0;
}

int Player::CriticalAttack() const
{return (int)attackDamage*2;}

void Player::LevelUp()
{
	level++;
}

void Player::PreviewCritical() const
{
	float preview = attackDamage * 2;
	cout << "크리티컬 예상 데미지 : " << preview << "\n";
}

void Player::PrintLevel() const
{
	cout << "현재 레벨 : " << level << "\n";
}
