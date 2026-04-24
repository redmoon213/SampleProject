#pragma once      //참조되는 과정에서 컴파일러가 중복해서 읽지 않도록 방지함
#include<string>
#include "Character.h"
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
	int inventory[5];
public:
	Player(const std::string& name, const std::string& characterClass, bool isHardcore);
	//Getter
	std::string get_name() const{return name;}
	std::string get_character_class() const{return characterClass;}
	bool is_is_hardcore() const{return isHardcore;}
	int get_exp() const{return exp;}
	int get_expTotalLevel() const{return expToNextLevel;}
	int* GetInventory()	{return inventory;}
	//함수부분
	int CriticalAttack() const; 
	void LevelUp();
	void PreviewCritical() const;
	void PrintLevel() const;
	void GainExp(int amount);
	
};
