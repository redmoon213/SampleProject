#include "Player.h"
#include<string>
#include<iomanip>
#include<iostream>
//using namespace std;
Player::Player(const std::string& name, const std::string& characterClass, bool isHardcore, 
	int str, int dex, int vit, int eng) : Character(str, dex, vit, eng, 1),
name(name), characterClass(characterClass), isHardcore(isHardcore),
exp(0), expToNextLevel(100)
{
	maxHp = vitality * 3;
	hp = maxHp;
	maxMp = energy * 2;
	mp = maxMp;
		
	attackDamage = (float)strength * 0.2;
	attackSpeed = (float)dexterity * 0.1;
	movingSpeed = (float)dexterity / 30.0;
}


Player::Player(const std::string& name, const std::string& characterClass, bool isHardcore)
: Character(50, 50, 50, 50, 1), 
name(name),characterClass(characterClass), isHardcore(isHardcore),
exp(0), expToNextLevel(100)
{
	
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

void Player::Loot(int count)
{
	srand((unsigned int)time(NULL));
	std::cout << "| [LOOT FOUND]                                 |\n";
	for (int i =0; i< count; i++)
	{
		inventory.push_back(rand()%4 +1);
	}
		
	for (int i = 0; i<inventory.size(); i++)
	{
		std::string itemName;
		if (inventory[i] == 1) itemName = "Gold";
		else if (inventory[i]== 2) itemName = "Healing Potion";
		else if (inventory[i] == 3) itemName = "Weapon";
		else if (inventory[i] == 4) itemName = "Armor";
		else itemName = "Empty";
		
		std::cout << "|>Slot " << i << "|" << std::setw(38) << itemName << "| \n";
	}
	
	std::cout << "################################################\n";
	
}
