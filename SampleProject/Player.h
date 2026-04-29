#pragma once      //참조되는 과정에서 컴파일러가 중복해서 읽지 않도록 방지함
#include <memory>
#include<string>
#include<vector>
#include "Character.h"
#include "Item.h"

class Mercenary;  //전방선언
//Character 클래스를 상속받은 Player 클래스
class Player : public Character
{
private:
	//Player의 고유정보
	std::string name;
	std::string characterClass;
	bool isHardcore;
	
	int exp, expToNextLevel;
	//인벤토리
	std::vector<Item> inventory;
protected:
	// 자식 클래스의 스탯을 직접 지정할 때 사용되는 생성자.
	Player(const std::string& name, const std::string& characterClass, bool isHardcore, 
		int str, int dex, int vit, int eng);
public:
	Player(const std::string& name, const std::string& characterClass, bool isHardcore);
	~Player();
	
	//Getter
	std::string get_name() const{return name;}
	std::string get_character_class() const{return characterClass;}
	bool is_is_hardcore() const{return isHardcore;}
	int get_exp() const{return exp;}
	int get_expTotalLevel() const{return expToNextLevel;}
	std::vector<Item> GetInventory() const {return inventory;}
	
	//플레이어가 용병 참조
	std::shared_ptr<Mercenary> companion;
	//함수부분
	int CriticalAttack() const; 
	void LevelUp();
	void PreviewCritical() const;
	void PrintLevel() const;
	void GainExp(int amount);
	void Loot(Item item); 
	
	virtual std::string GetAttackMessage() const {return "";}
	
	void PrintInventory();
	
	bool UseItem(const std::string& itemName);
};
