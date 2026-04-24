#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include <windows.h>

#include "Battle.h"
#include"Monster.h"
#include"Player.h"


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


////call by adress 실습을 위한 함수 작성
//void LevelUp(int* level) {
//	(*level)++;				//역참조를 통해 level 원본 데이터의 값을 1올려줌
//	
//}

//class 실습. 몬스터 class 작성


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
	bool isFirstTurn = true;
	
	Monster goblin1(50,0, 15, 0, 150);
	Battle battle1(player, goblin1);
	battle1.Run();
	
	//생성자 호출. 
/*
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
		drawGauge("GOBLIN", goblin1.get_hp(), goblin1.get_max_hp());
		cout << "|----------------------------------------------|\n";
		cout << "|  1. Attack                                   |\n";
		cout << "|  2. Critical Attack!                         |\n";
		cout << "################################################\n";
	}
	*/
	
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
		cout << "################################################\n";
		
		player.GainExp(goblin1.GetExpReward());

	
		system("pause");
	}
	
	
	
	return 0;
}