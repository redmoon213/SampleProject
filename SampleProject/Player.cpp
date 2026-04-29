#include "Player.h"
#include<string>
#include<iomanip>
#include<iostream>

#include "Item.h"
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

Player::~Player()
{
	std::cout<<"<플레이어 소멸자 호출>\n";
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

void Player::Loot(std::unique_ptr<Item> item)
{
	srand((unsigned int)time(NULL));
	inventory.push_back(*item);
	std::cout << "| [LOOT FOUND]                                 |\n"; //나중에 Loot함수 호출전에 쓰는게 나을거같음
	std::cout << item->GetItemName() << std::endl;
	std::cout << "################################################\n";
}

void Player::PrintInventory()
{
	std:: cout << "| [Inventory]                                 |\n";
	
	
	for (int i =0; i<inventory.size(); i++)
	{
		std::string typeString;
		if (inventory[i].GetItemType() == ItemType::Weapon) typeString = "Weapon";
		else if (inventory[i].GetItemType() == ItemType::Armor) typeString ="Aromor";
		else typeString = "Consumable";
		
		std::cout << i+1 << "_" << inventory[i].GetItemName() << "\n";
	}
}