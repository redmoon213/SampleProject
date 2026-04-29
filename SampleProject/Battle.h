#pragma once
#include"Player.h"
#include"Monster.h"
#include<vector>


class Battle
{
private:
    Player& player;
    Monster& monster;
    std::shared_ptr<Mercenary> mercenary;
    std::string logMessage;
public:
    Battle(Player& player, Monster& monster, std::shared_ptr<Mercenary> merc = nullptr);
    ~Battle();
    bool Run();
    void DisplayScreen();
    void DrawGauge(std::string label, int current, int max);
    void DisplayResult();
};
