#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include <windows.h>
using namespace std;

// 화면을 지우는 함수
void clearScreen() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

// 체력 게이지 출력 함수 (ASCII 버전)
// 한글 폭 문제를 피하기 위해 라벨과 게이지를 정교하게 계산
void drawGauge(string label, int current, int max) {
	int width = 20;
	float ratio = (float)current / max;
	if (ratio < 0) ratio = 0;
	int filled = (int)(width * ratio);

	// 라벨 영문 10칸 고정
	cout << "| " << left << setw(10) << label << " [";
	for (int i = 0; i < width; i++) {
		if (i < filled) cout << "#";
		else cout << " ";
	}
	// 수치 부분 7칸 + 테두리 마무리
	cout << "] " << right << setw(5) << current << "/" << left << setw(4) << max << " |\n";
}


//Call by value 실습을 위한 함수
void PreviewCritical(float attackDamage) {
	attackDamage *= 2; // 파라미터로 받아온 값을 변경하더라도 원본은 바뀌지 않을것이다.
	cout << "<Call by Value> attack damage : " << attackDamage << "\n";
}

//Call by Reference를 활용한 크리티컬 데미지를 실제 적용시키는 함수
void ApplyCriticalDamage(int& goblinHp, float attackDamage){
	int critDamage = attackDamage * 2;
	goblinHp -= critDamage;
}

////call by adress 실습을 위한 함수 작성
//void LevelUp(int* level) {
//	(*level)++;				//역참조를 통해 level 원본 데이터의 값을 1올려줌
//	
//}

//call by reference 실습을 위한 함수 작성
void LevelUpRef(int& level) {
	level++;
}

//const 참조자 실습을 위한 함수 작성
void PrintLevel(const int& level) {
	cout << "<PrintLevel> Level : " << level << "\n";
	//level++; //파라미터를 수정하려고 해도 불가능함 
}

//class 실습. 몬스터 class 작성
class Monster
{
private:
	int hp, maxhp;
	int attackDamage;
	
public:
	Monster(int initHp, int initAtk): hp(initHp), maxhp(initHp), attackDamage(initAtk)
	{
		cout << "<몬스터 생성>\nHP : " << hp << "/ Attack Damage : " << attackDamage << "\n";
	}
	~Monster()
	{
		cout << "<몬스터 소멸>\n";
	}
	int GetHp() const {return hp;}
	int GetMaxHp() const {return maxhp;}
	bool isAlive() const {return hp > 0;}
	void TakeDamage(int damage)	// 몬스터가 피해를 받음
	{
		hp -= damage;
		if (hp<0) hp = 0; // hp 음수 방지
	}
	int Attack() const {return attackDamage;} // 몬스터가 플레이어를 공격
};

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
	Player(const string& name, const string& characterClass, bool isHardcore)
	: name(name), characterClass(characterClass), isHardcore(isHardcore), // 매개변수로 받는애들 초기화
	strength(50), dexterity(50), vitality(50), energy(50),
	level(1),
	fireResist(0), coldResist(0), lightningResist(0), poisonResist(0) //단순 값 세팅 하는애들 초기화
	//계산이 필요한건 중괄호 안에
	{
		maxHp = vitality * 3;
		hp = maxHp;
		maxMp = energy * 2;
		mp = maxMp;
		
		attackDamage = (float)strength * 0.2;
		attackSpeed = (float)dexterity * 0.1;
		movingSpeed = (float)dexterity / 30.0;
		
		for (int i =0; i<5; i++) inventory[i] = 0;
	}
	
	//Getter
	string get_name() const{return name;}

	string get_character_class() const
	{
		return characterClass;
	}

	bool is_is_hardcore() const
	{
		return isHardcore;
	}

	int get_strength() const
	{
		return strength;
	}

	int get_dexterity() const
	{
		return dexterity;
	}

	int get_vitality() const
	{
		return vitality;
	}

	int get_energy() const
	{
		return energy;
	}

	int get_level() const
	{
		return level;
	}

	int get_hp() const
	{
		return hp;
	}

	int get_max_hp() const
	{
		return maxHp;
	}

	int get_mp() const
	{
		return mp;
	}

	int get_max_mp() const
	{
		return maxMp;
	}

	float get_attack_damage() const
	{
		return attackDamage;
	}

	float get_attack_speed() const
	{
		return attackSpeed;
	}

	double get_moving_speed() const
	{
		return movingSpeed;
	}

	int get_fire_resist() const
	{
		return fireResist;
	}

	int get_cold_resist() const
	{
		return coldResist;
	}

	int get_lightning_resist() const
	{
		return lightningResist;
	}

	int get_poison_resist() const
	{
		return poisonResist;
	}
	
	int* GetInventory()	{return inventory;}
	
	//함수부분
	bool isAlive() const{return hp>0;}
	void TakeDamage(int damage)
	{
		hp-=damage;
		if(hp<0) hp=0;
	}
	int Attack() const {return (int)attackDamage;}
	int CriticalAttack() const {return (int)attackDamage*2;}
	void LevelUp() {level++;}
	
	void PreviewCritical()
	{
		float preview = attackDamage * 2;
		cout << "크리티컬 예상 데미지 : " << preview << "\n";
	}
	
	void PrintLevel()
	{
		cout << "현재 레벨 : " << level << "\n";
	}
};

int main() {

	string userName;
	string charactorClass;
	int classChoiceInput;
	char isHardcoreInput;
	bool isHardcore = true;
/*
	int strength = 50, dexterity = 50, vitality = 50, energy = 50;
	int level = 1;
	int maxHp = vitality * 2;
	int hp = maxHp;
	int mp = energy * 1.5;
	float attackDamage = strength * 0.2;
	float attackSpeed = dexterity / 10.0;
	double movingSpeed = dexterity / 30.0;
*/
	//bool isHardcore = true;

	//인벤토리(0 = 빈칸, 1 = Gold, 2 = Healing Potion, 3 = Weapon, 4 = Armor 실습
	
	//int gameInventory[5] = { 0, 0, 0, 0, 0 };

	// [SCENE 1: Character Creation]
	clearScreen();
	cout << "################################################\n";
	cout << "#                                              #\n";
	cout << "#         DIABLO-STYLE RPG PROJECT v1.0        #\n";
	cout << "#                                              #\n";
	cout << "################################################\n\n";
	cout << " [1] CHARACTER CREATION\n";
	cout << " ----------------------------------------------\n";
	cout << "  > Input your name : ";
	cin >> userName;

	cout << "\n [2] SELECT YOUR CLASS\n";
	cout << "  1. Amazon     2. Assassin    3. Barbarian \n";
	cout << "  4. Druid      5. Necro       6. Paladin   \n";
	cout << "  7. Sorceress  8. Warlock\n";
	cout << "  > Choice : ";
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
	default: charactorClass = "Unknown"; break;
	}

	cout << "\n [3] GAME MODE\n";
	cout << "  Enable Hardcore? (1) Yes / (2) No : ";
	cin >> isHardcoreInput;
	isHardcore = (isHardcoreInput == '1');
	
	//정보 입력 후 플레이어 객체 생성 세부 스탯은 내부에서 자동 계산
	Player player(userName, charactorClass, isHardcore);
	
	
	// [SCENE 2: Status Window]
	clearScreen();
	cout << "################################################\n";
	cout << "#               CHARACTER STATUS               #\n";
	cout << "################################################\n";
	cout << "| NAME   : " << left << setw(36) << player.get_name() << "|\n";
	cout << "| CLASS  : " << left << setw(36) << player.get_character_class() << "|\n";
	// 한글이 포함된 행은 수동으로 여백 조정 (한글은 영문 2칸 취급)
	if (isHardcore)
		cout << "| MODE   : HARDCORE (Permadeath)               |\n";
	else
		cout << "| MODE   : STANDARD                            |\n";
	cout << "|----------------------------------------------|\n";
	drawGauge("LIFE", player.get_hp(), player.get_max_hp());
	cout << "|----------------------------------------------|\n";
	// 수치 행들 (setw 간격 재조정)
	cout << "| STR : " << left << setw(7) << player.get_strength() << " | DEX : " << left << setw(7) << player.get_dexterity() << " | VIT : " << left << setw(6) << player.get_vitality() << " |\n";
	cout << "| ATK : " << left << setw(7) << player.get_attack_damage() << " | SPD : " << left << setw(7) << player.get_attack_speed() << " | NRG : " << left << setw(6) << player.get_energy() << " |\n";
	cout << "################################################\n";
	cout << "\n [Press Any Key to Start Adventure...]\n";
	system("pause > nul");

	// [SCENE 3: Battle]
	int maxGoblinHp = 30;
	int goblinHp = maxGoblinHp;
	int action = 0;
	bool isFirstTurn = true;
	
	//생성자 호출. 
	Monster goblin1(50,10);

	while (goblin1.isAlive() && player.isAlive()) {
		clearScreen();
		cout << "################################################\n";
		cout << "#                BATTLE FIELD                  #\n";
		cout << "################################################\n";
		cout << "|                                              |\n";
		cout << "|      (o_o)  < \"Gimme your gold!\"             |\n";
		cout << "|      /| |\\                                   |\n";
		cout << "|       | |            [A Goblin Approaches]   |\n";
		cout << "|----------------------------------------------|\n";
		drawGauge("PLAYER", player.get_hp(), player.get_max_hp());
		drawGauge("GOBLIN", goblin1.GetHp(), goblin1.GetMaxHp());
		cout << "|----------------------------------------------|\n";
		cout << "|  1. Attack                                   |\n";
		cout << "|  2. Critical Attack!                         |\n";
		cout << "################################################\n";
		
		if (action == 1) {
			
			//if (goblinHp < 0) goblinHp = 0;
			cout << "\n >> You dealt " << player.get_attack_damage() << " damage to Goblin!\n";
			if (goblin1.isAlive()) {
				
				
				cout << " >> Goblin counter-attacks! You take " << goblin1.Attack()<< "damage.\n";
			}
		}
		//고쳐야겠다 이거 
		//입력으로 2를 받았을 때 크리티컬 데미지를 적용
		else if (action == 2) {

			//if (goblinHp < 0) goblinHp = 0;
			
			cout << "\n >>Critical Hit!!!>> You dealt " << player.CriticalAttack()<< " damage to Goblin!\n";
			
			if (goblin1.isAlive()) {
				cout << " >> Goblin counter-attacks! You take " << goblin1.Attack()<< "damage.\n";
			}
		}
		
		//system("pause");
		else if(isFirstTurn!=true){
			cout << "\n >> You hesitated! Goblin attacks you! (-" << goblin1.Attack()<<" HP)\n";
		}

		cout << " > Action: ";
		cin >> action;

		if (action == 1) {
			//goblinHp -= (int)attackDamage;
			goblin1.TakeDamage(player.get_attack_damage());
			if (goblin1.isAlive()) {
				player.TakeDamage(goblin1.Attack());
			}
		}

		else if (action == 2) {
			goblin1.TakeDamage(player.CriticalAttack());
			if (goblin1.isAlive()) {
				player.TakeDamage(goblin1.Attack());
			}
		}
		else
		{
			player.TakeDamage(goblin1.Attack());
		}
		isFirstTurn = false;
	}
	

	// [SCENE 4: Result]
	clearScreen();
	cout << "################################################\n";
	if (!player.isAlive()) {
		cout << "#                                              #\n";
		cout << "#                Y O U  D I E D                #\n";
		cout << "#                                              #\n";
		cout << "################################################\n";
	}
	else {
		cout << "#               V I C T O R Y !                #\n";
		cout << "################################################\n";
		srand((unsigned int)time(NULL));
		cout << "| [LOOT FOUND]                                 |\n";

		int* inventoryPtr = player.GetInventory(); // inventoryPtr이 gameInventory 배열의 시작주소를 가리킴.

		// 반복문을 이용해서 인벤토리포인터를 이용해 인벤토리에 랜덤 숫자 3개 저장
		for (int i = 1; i <= 3; i++) {
			*inventoryPtr = rand() % 4 + 1; // 역참조로 현재 칸에 아이템 코드를 저장함.
			inventoryPtr++;
		}

		//인벤토리 포인터로 인벤토리 출력(5칸)
		inventoryPtr = player.GetInventory(); // inventoryPtr을 초기화
		int slot = 0;

		while (inventoryPtr < player.GetInventory() + 5) {
			string itemName;
			if (*inventoryPtr == 1) itemName = "Gold";
			else if (*inventoryPtr == 2) itemName = "Healing Potion";
			else if (*inventoryPtr == 3) itemName = "Weapon";
			else if (*inventoryPtr == 4) itemName = "Armor";
			else itemName = "Empty";
			cout << "|>Slot " << slot << "|" << setw(38) << itemName << "| \n";

			inventoryPtr++;
			slot++;
		}
		player.LevelUp();
		player.PrintLevel();

		cout << "################################################\n";
		system("pause");
	}
	
	
	
	return 0;
}