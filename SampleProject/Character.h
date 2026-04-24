#pragma once
#include <string>

class Character
{
protected:
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

	
public:
    Character(int str, int dex, int vit, int engergy, int lv = 1);
	virtual ~Character(); //가상 소멸자. 자식의 소멸자까지 안전하게 호출
	
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
	
	bool isAlive() const;
	virtual int Attack() const;
	void TakeDamage(int damage);
};
