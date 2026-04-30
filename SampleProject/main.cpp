#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include <unordered_map>
#include <windows.h>
#include <vector>

#include "Barbarian.h"
#include "Battle.h"
#include "FireGoblin.h"
#include "ItemData.h"
#include "Mercenary.h"
#include "Monster.h"
#include "Player.h"
#include "Sorceress.h"

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


int main() {

	string userName;
	string charactorClass;
	int classChoiceInput;
	char isHardcoreInput;
	bool isHardcore = true;

	
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
	shared_ptr<Player> playerPtr;
	if (classChoiceInput == 3)
	{
		playerPtr = make_shared<Barbarian>(userName, isHardcore);//new Barbarian(userName, isHardcore);
	}
	else if (classChoiceInput == 7)
	{
		playerPtr = make_shared<Sorceress>(userName, isHardcore);// new Sorceress(userName, isHardcore);
	}
	else
	{
		playerPtr = make_shared<Player>(userName, charactorClass, isHardcore);//new Player(userName, charactorClass, isHardcore);
	}
	
	Player& player = *playerPtr;
	
	shared_ptr<Mercenary>mercPtr = make_shared<Mercenary>("Rogue", 10, playerPtr);
	player.companion = mercPtr; // Player와 Mercenary 연결 (순환참조 발생)
	
	
	
	
	
	system("pause");
	
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
	
	//아이템 DB생성
	vector<unique_ptr<Monster>>monsters;
	monsters.push_back(make_unique<Monster>("Goblin",50,0, 15, 0, 100,1, vector<int>{101, 102, 201, 203}));
	monsters.push_back(make_unique<Monster>("Goblin",50,0, 15, 0, 100,1, vector<int>{201, 102, 201, 303}));
	monsters.push_back(make_unique<Monster>("Goblin",50,0, 15, 0, 100,1, vector<int>{103, 102, 401, 101}));
	monsters.push_back(make_unique<Monster>("Goblin",50,0, 15, 0, 100,1, vector<int>{403, 402, 401, 403}));
	monsters.push_back(make_unique<FireGoblin>("FireGoblin",100,0, 15, 0, 100, 1, vector<int>{203, 303, 401,}));
	
	
	for (auto& monster : monsters)
	{
		Battle battle2(player, *monster, mercPtr);
		battle2.Run();
		if (!player.isAlive())break;
	}
	
	system("pause");
	
	return 0;
}