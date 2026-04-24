#pragma once
#include<string>
using namespace std;
//
class Player
{
private:
	string name;
	string characterClass;
	bool isHardcore;
	
	//기본 능력치
	int strength, dexterity, vitality, energy;
	
	int level;
	int hp, maxHp;
	int mp, maxMp;
	float attackDamage;
	float attackSpeed;
	double movingSpeed;
	
	//저항능력치
	int fireResist, coldResist, lightningResist, poisonResist;
	
	//인벤토리
	int inventory[5];
	
public:
	Player(const string& name, const string& characterClass, bool isHardcore);
	
	
	//Getter
	string get_name() const{return name;}
	string get_character_class() const{return characterClass;}
	bool is_is_hardcore() const{return isHardcore;}
	int get_strength() const{return strength;}
	int get_dexterity() const{return dexterity;}
	int get_vitality() const{return vitality;}
	int get_energy() const{return energy;}
	int get_level() const{return level;}
	int get_hp() const{return hp;}
	int get_max_hp() const{return maxHp;}
	int get_mp() const{return mp;}
	int get_max_mp() const{return maxMp;}
	float get_attack_damage() const{return attackDamage;}
	float get_attack_speed() const{return attackSpeed;}
	double get_moving_speed() const{return movingSpeed;}
	int get_fire_resist() const{return fireResist;}
	int get_cold_resist() const	{return coldResist;}
	int get_lightning_resist() const{return lightningResist;}
	int get_poison_resist() const {return poisonResist;}
	int* GetInventory()	{return inventory;}
	
	//함수부분
	bool isAlive() const{return hp>0;}
	void TakeDamage(int damage);
	int Attack() const {return (int)attackDamage;}
	int CriticalAttack() const; 
	void LevelUp();
	void PreviewCritical() const;
	void PrintLevel() const;
	
};
