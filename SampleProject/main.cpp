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
	cout << "] " << right << setw(3) << current << "/" << left << setw(3) << max << " |\n";
}

int main() {

	char userName[50];
	string charactorClass;
	int classChoiceInput;
	char isHardcoreInput;
	int strength = 50, dexterity = 50, vitality = 50, energy = 50;

	int level = 1;
	int maxHp = vitality * 2;
	int hp = maxHp;
	int mp = energy * 1.5;
	float attackDamage = strength * 0.2;
	float attackSpeed = dexterity / 10.0;
	double movingSpeed = dexterity / 30.0;

	bool isHardcore = true;

	// '&' 주소연산자 실습
	cout << "hp : " << hp << "\n";
	cout << "hp adress : " << &hp << "\n"; // 변수의 주소값 출력
	system("pause");	// 확인을 위해 잠시 퍼즈 

	//'*'연산자 실습
	int* ptr = &hp;
	cout << "ptr == &hp : " << ptr << "\n";
	cout << "*ptr : " << *ptr << "\n";

	*ptr = 200; // 포인터 역참조하여 쓰기 및 수정
	cout << "hp: " << hp << "\n";
	system("pause");
	
	//포인터 초기화 안햇을때 쓰레기값 실습
	//int* trashPtr;  <- 초기화가 되지않았음.
	//int* trashPtr = nullptr; <- 이런식으로 초기화시켜줘야함.
	//cout << trashPtr << "\n";
	
	//데이터형과 포인터 크기 확인하기
	cout << "sizeof(int) : " << sizeof(int) << "\n";
	cout << "sizeof(int*) : " << sizeof(int*) << "\n";
	cout << "sizeof(char) : " << sizeof(char) << "\n";
	cout << "sizeof(char*) : " << sizeof(char*) << "\n";
	cout << "sizeof(double) : " << sizeof(double) << "\n";
	cout << "sizeof(double) : " << sizeof(double*) << "\n";
	system("pause");


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

	// [SCENE 2: Status Window]
	clearScreen();
	cout << "################################################\n";
	cout << "#               CHARACTER STATUS               #\n";
	cout << "################################################\n";
	cout << "| NAME   : " << left << setw(36) << userName << "|\n";
	cout << "| CLASS  : " << left << setw(36) << charactorClass << "|\n";
	// 한글이 포함된 행은 수동으로 여백 조정 (한글은 영문 2칸 취급)
	if (isHardcore)
		cout << "| MODE   : HARDCORE (Permadeath)               |\n";
	else
		cout << "| MODE   : STANDARD                            |\n";
	cout << "|----------------------------------------------|\n";
	drawGauge("LIFE", hp, maxHp);
	cout << "|----------------------------------------------|\n";
	// 수치 행들 (setw 간격 재조정)
	cout << "| STR : " << left << setw(7) << strength << " | DEX : " << left << setw(7) << dexterity << " | VIT : " << left << setw(6) << vitality << " |\n";
	cout << "| ATK : " << left << setw(7) << attackDamage << " | SPD : " << left << setw(7) << attackSpeed << " | NRG : " << left << setw(6) << energy << " |\n";
	cout << "################################################\n";
	cout << "\n [Press Any Key to Start Adventure...]\n";
	system("pause > nul");

	// [SCENE 3: Battle]
	int maxGoblinHp = 30;
	int goblinHp = maxGoblinHp;
	int action = 0;
	bool isFirstTurn = true;


	while (goblinHp > 0 && hp > 0) {
		
		clearScreen();
		cout << "################################################\n";
		cout << "#                BATTLE FIELD                  #\n";
		cout << "################################################\n";
		cout << "|                                              |\n";
		cout << "|      (o_o)  < \"Gimme your gold!\"             |\n";
		cout << "|      /| |\\                                   |\n";
		cout << "|       | |            [A Goblin Approaches]   |\n";
		cout << "|----------------------------------------------|\n";
		drawGauge("PLAYER", hp, maxHp);
		drawGauge("GOBLIN", goblinHp, maxGoblinHp);
		cout << "|----------------------------------------------|\n";
		cout << "|  1. Attack                                   |\n";
		cout << "|                                              |\n";
		cout << "################################################\n";
		
		if (action == 1) {
			
			if (goblinHp < 0) goblinHp = 0;
			cout << "\n >> You dealt " << attackDamage << " damage to Goblin!\n";
			if (goblinHp > 0) {
				
				
				cout << " >> Goblin counter-attacks! You take 30 damage.\n";
			}
		}

		else if(isFirstTurn!=true){

			
			cout << "\n >> You hesitated! Goblin attacks you! (-30 HP)\n";
		}

		cout << " > Action: ";
		cin >> action;

		if (action == 1) {
			goblinHp -= (int)attackDamage;
			
			if (goblinHp > 0) {
				hp -= 30;
				if (hp < 0) hp = 0;
			}
		}
		else {
			hp -= 30;
			if (hp < 0) hp = 0;
		}

		isFirstTurn = false;
			
		
			

			

		}
		

		

	

	// [SCENE 4: Result]
	clearScreen();
	cout << "################################################\n";
	if (hp <= 0) {
		cout << "#                                              #\n";
		cout << "#                Y O U  D I E D                #\n";
		cout << "#                                              #\n";
		cout << "################################################\n";
	}
	else {
		cout << "#               V I C T O R Y !                #\n";
		cout << "################################################\n";
		srand((unsigned int)time(NULL));
		cout << "|                                              |\n";
		cout << "| [LOOT FOUND]                                 |\n";
		for (int i = 1; i <= 3; i++) {
			string items[] = { "Gold Coin", "Red Potion", "Small Sword", "Old Shield" };
			// 아이템 영문 표기로 통일하여 테두리 유지
			cout << "|  " << i << ". " << left << setw(41) << items[rand() % 4] << "|\n";
		}
		cout << "|                                              |\n";
		cout << "################################################\n";
	}

	return 0;
}