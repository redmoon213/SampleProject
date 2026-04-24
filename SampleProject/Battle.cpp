#include "Battle.h"
#include <iostream>
#include<iomanip>
Battle::Battle(Player& player, Monster& monster):
player(player), monster(monster), logMessage("Battle Start")
{}

bool Battle::Run()
{
    int action = 0;
    bool isFirstTurn = true;
    
    while (monster.isAlive() && player.isAlive()) {
    
        DisplayScreen();
        if (action == 1) {
			
            std::cout << "\n >> You dealt " << player.get_attack_damage() << " damage to Goblin!\n";
            if (monster.isAlive()) {
				
				
                std::cout << " >> Goblin counter-attacks! You take " << monster.Attack()<< " damage.\n";
            }
        }
        //고쳐야겠다 이거 
        //입력으로 2를 받았을 때 크리티컬 데미지를 적용
        else if (action == 2) {

            std::cout << "\n >>Critical Hit!!!>> You dealt " << player.CriticalAttack()<< " damage to Goblin!\n";
			
            if (monster.isAlive()) {
                std::cout << " >> Goblin counter-attacks! You take " << monster.Attack()<< " damage.\n";
            }
        }
		
        else if(isFirstTurn!=true){
            std::cout << "\n >> You hesitated! Goblin attacks you! (-" << monster.Attack()<<" HP)\n";
        }

        std::cout << " > Action: ";
        std::cin >> action;

        if (action == 1) {
            monster.TakeDamage(player.get_attack_damage());
            if (monster.isAlive()) {
                player.TakeDamage(monster.Attack());
            }
        }

        else if (action == 2) {
            monster.TakeDamage(player.CriticalAttack());
            if (monster.isAlive()) {
                player.TakeDamage(monster.Attack());
            }
        }
        else
        {
            player.TakeDamage(monster.Attack());
        }
        isFirstTurn = false;
    }
	return player.isAlive();
}


void Battle::DisplayScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    
    std::cout << "################################################\n";
    std::cout << "#                BATTLE FIELD                  #\n";
    std::cout << "################################################\n";
    std::cout << "|                                              |\n";
    std::cout << "|      (o_o)  < \"Gimme your gold!\"             |\n";
    std::cout << "|      /| |\\                                   |\n";
    std::cout << "|       | |            [A Goblin Approaches]   |\n";
    std::cout << "|----------------------------------------------|\n";
    DrawGauge("PLAYER", player.get_hp(), player.get_max_hp());
    DrawGauge("GOBLIN", monster.get_hp(), monster.get_max_hp());
    std::cout << "|----------------------------------------------|\n";
    std::cout << "|  1. Attack                                   |\n";
    std::cout << "|  2. Critical Attack!                         |\n";
    std::cout << "################################################\n";
}


void Battle::DrawGauge(std::string label, int current, int max)
{
    int width = 20;
    float ratio = (float)current / max;
    if (ratio < 0) ratio = 0;
    int filled = (int)(width * ratio);

    // 라벨 영문 10칸 고정
    std::cout << "| " << std::left << std::setw(10) << label << " [";
    for (int i = 0; i < width; i++) {
        if (i < filled) std::cout << "#";
        else std::cout << " ";
    }
    // 수치 부분 7칸 + 테두리 마무리
    std::cout << "] " << std::right << std::setw(5) << current << "/" << std::left << std::setw(4) << max << " |\n";
}
