#include<iostream>

using namespace std;

int main() {

	char userName[50];
	char charactorClass[50];

	int strength = 50;
	int dexterity = 50;
	int vitality = 50;
	int energy = 50;

	int level = 1;
	int hp = vitality * 2;
	int mp = energy * 1.5;
	float attackDamage = strength * 0.2;
	float attackSpeed = dexterity / 10.0;
	double movingSpeed = dexterity / 30.0;


	int fireResist = 0;
	int lightningResist = 0;
	int coldResist = 0;
	int poisonResist = 0 ;

	bool isHardcore = true;

	

	cout << "[ Character Creation ]\n";
	cout << "Input your name : ";
	cin >> userName;
	cout << "Input your Class : ";
	cin >> charactorClass;
	cout << "\n:::::::: Welcome to the Sanctuary ::::::::\n";
	cout << "User Name : [" << userName << "]\n";
	
	cout << "----------------Character Status----------------\n";
	cout << "Class : " << charactorClass << "\n";
	cout << "Level : " << level << "\n";
	cout << "Hp : " << hp << "\n";
	cout << "MP : " << mp << "\n";
	
	cout << "Attack Damage : " << attackDamage << "\n";
	cout << "Attack Speed : " << attackSpeed << "\n";
	cout << "Moving Speed : " << movingSpeed << "\n";

	cout << "Strength : " << strength << "\n";
	cout << "Dexterity : " << dexterity << "\n";
	cout << "Vitality : " << vitality << "\n";
	cout << "Energy : " << energy << "\n";

	cout << "Fire Resistance : " << fireResist << "\n";
	cout << "Lightning Resistance : " << lightningResist << "\n";
	cout << "Cold Resistance : " << coldResist << "\n";
	cout << "Poison Resistance : " << poisonResist << "\n";

	cout << "Hardcore Mode : " << isHardcore << " (1: true, 0: flase)\n";
	cout << "------------------------------------------------\n";

	cout << "[Memory Check] int type size : " << sizeof(hp) << "bytes\n";
	cout << "[Memory Check] bool type size : " << sizeof(isHardcore) << "bytes\n";


	return 0;
}