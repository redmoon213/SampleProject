#pragma once
#include"Player.h"
#include"Monster.h"

class Battle
{
private:
    Player& player;
    Monster& monster;
    std::string logMessage;
public:
    Battle(Player& player, Monster& monster);
    bool Run();
    void DisplayScreen();
    void DrawGauge(std::string label, int current, int max);
};
