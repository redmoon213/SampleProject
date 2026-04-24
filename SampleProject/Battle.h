#pragma once
#include"Player.h"
#include"Monster.h"
#include<vector>


class Battle
{
private:
    Player& player;
    Monster& monster;
    std::string logMessage;
public:
    Battle(Player& player, Monster& monster);
    ~Battle();
    bool Run();
    void DisplayScreen();
    void DrawGauge(std::string label, int current, int max);
    void DisplayResult();
};
