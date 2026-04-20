#include<iostream>

using namespace std;

int main() {

	char userName[50];
	char charactorClass[50];

	int level = 1;
	int hp = 100;
	int mp = 100;
	float attackSpeed = 5.5f;

	int strength = 50;
	int dexterity = 50;
	int vitality = 50;
	int energy = 50;

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
	cout << "Attack Speed : " << attackSpeed << "\n";
	cout << "Strength : " << strength << "\n";
	cout << "Dexterity : " << dexterity << "\n";
	cout << "Vitality : " << vitality << "\n";
	cout << "Energy : " << energy << "\n";
	cout << "Hardcore Mode : " << isHardcore << " (1: true, 0: flase)\n";
	cout << "------------------------------------------------\n";

	cout << "[Memory Check] int type size : " << sizeof(hp) << "bytes\n";
	cout << "[Memory Check] bool type size : " << sizeof(isHardcore) << "bytes\n";



	return 0;
}