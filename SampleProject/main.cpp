#include<iostream>
#include<string>

using namespace std;

int main() {

	char userName[50];
	//char charactorClass[50];
	string charactorClass;
	int classChoiceInput;

	char isHardcoreInput;
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
	//cout << "Input your Class : ";
	//cin >> charactorClass;
	cout << "Select your Class\n";
	cout << "1. Amazon\n2. Assasin\n3. Barbarian\n4. Druid\n5. Necromancer\n6. Paladin\n7. Sorceress\n8. Warlock\n";
	cout << "input Class Number : ";
	cin >> classChoiceInput;

	switch (classChoiceInput) {
	case 1: charactorClass = "Amazon"; break;
	case 2: charactorClass = "Assassin"; break;
	case 3: charactorClass = "Barbarian"; break;
	case 4: charactorClass = "Druid"; break;
	case 5: charactorClass = "Necromancer"; break;
	case 6: charactorClass = "Paladin"; break;
	case 7: charactorClass = "Sorceress"; break;
	case 8: charactorClass = "Warlock"; break;
	default:
		charactorClass = "Unknown";
		cout << "[System] Invalid choice. Defaulting to Unknown.\n";
		break;
	}



	cout << "Enable Hardcore Mode? (1) Yes / (2) No\n";
	cin >> isHardcoreInput;

	if (isHardcoreInput == '1') {
		isHardcore = true;
		cout << "[System] Hardcore mode enabled, Death is permanent.\n";
	}
	else if (isHardcoreInput == '2') {
		isHardcore = false;
		cout << "[System] Standard mode enabled.\n";
	}
	else{
		isHardcore = false;
		cout << "[System] Invalid input. Defaulting to Standard mode.\n";
	}


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

	cout << "Hardcore Mode : " << isHardcore << " (1: true, 0: false)\n";
	cout << "------------------------------------------------\n";

	cout << "[Memory Check] int type size : " << sizeof(hp) << "bytes\n";
	cout << "[Memory Check] bool type size : " << sizeof(isHardcore) << "bytes\n";


	return 0;
}