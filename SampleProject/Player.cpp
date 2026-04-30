#include "Player.h"

#include <algorithm>
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
	
	inventory.reserve(10);
	inventory.push_back(Item("HealingPotion", ItemType::Consumable));
}


Player::Player(const std::string& name, const std::string& characterClass, bool isHardcore)
: Character(50, 50, 50, 50, 1), 
name(name),characterClass(characterClass), isHardcore(isHardcore),
exp(0), expToNextLevel(100)
{
	
	inventory.reserve(10);
	inventory.push_back(Item("HealingPotion", ItemType::Consumable));
}

Player::~Player()
{}

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

void Player::Loot(Item item)
{
	inventory.emplace_back(std::move(item));
	std::cout << "| [LOOT FOUND]                                 |\n"; //나중에 Loot함수 호출전에 쓰는게 나을거같음
	std::cout << item.GetItemName() << std::endl;
	std::cout << "################################################\n";

	std::cout<<"<Loot()> 인벤토리 size : " << inventory.size()
		<< "인벤토리 Capacity : "  << inventory.capacity() << std::endl;
}

void Player::PrintInventory()
{
	std:: cout << "| [Inventory]                                 |\n";
	
	int outputIndex = 0;
	for (const auto& it : inventory)
	{
		std::string typeString;
		if (it.GetItemType() == ItemType::Weapon) typeString = "Weapon";
		if (it.GetItemType() == ItemType::Armor) typeString = "Armor";
		if (it.GetItemType() == ItemType::Consumable) typeString = "Consumable";
		
		std::cout<< "| Slot_" << ++outputIndex << ">>" << it.GetItemName() << std::endl;
	}
}

bool Player::UseItem(const std::string& itemName)
{
	auto it = std::find_if(inventory.begin(), inventory.end(),
			[&itemName](const Item& item){return item.GetItemName() == itemName;});
	if (it != inventory.end())
	{
		if (it->GetItemType() == ItemType::Consumable)
		{
			Heal(maxHp);
			inventory.erase(it);
			return true;
		}
	}	
	
	/*
	for (auto it = inventory.begin(); it!=inventory.end(); ++it)
	{
		if (it->GetItemName() == itemName)
		{
			if (it->GetItemType() == ItemType::Consumable)
			{
				Heal(maxHp);     
				
				it = inventory.erase(it);
				std::cout<<"<UseItem()> 아이템 사용 후 size : " << inventory.size() 
					<< "capacity : " << inventory.capacity() << std::endl;
				return true;
			}
		}
	}*/
		
	return false;
}

void Player::SortInventory()
{
	std::sort(
		inventory.begin(), inventory.end(),
		[](const Item& a, const Item& b)
		{return a.GetItemName() < b.GetItemName();});//a가 b보다 앞에 오면 true => 오름차순
			
	std::cout <<"<인벤토리 이름정렬 완료>\n";
}
