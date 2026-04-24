#include "Player.h"
#include<string>
#include<iostream>
//using namespace std;

Player::Player(const std::string& name, const std::string& characterClass, bool isHardcore)
: Character(50, 50, 50, 50, 1), 
name(name),characterClass(characterClass), isHardcore(isHardcore),
exp(0), expToNextLevel(100)
    {
    for (int i =0; i<5; i++) inventory[i] = 0;
    }


int Player::CriticalAttack() const {return (int)attackDamage*2;}

void Player::LevelUp()
{
	level++;
	std::cout << "[레벨 업] Level : " << level << "\n";
}

void Player::PreviewCritical() const
{
	float preview = attackDamage * 2;
	std::cout << "크리티컬 예상 데미지 : " << preview << "\n";
}

void Player::PrintLevel() const
{
	std::cout << "현재 레벨 : " << level << "\n";
}

void Player::GainExp(int amount)
{
	exp += amount;
	if (exp>=expToNextLevel)
	{
		LevelUp();
		exp = exp - expToNextLevel;
		expToNextLevel = level * 100;
	}
}
