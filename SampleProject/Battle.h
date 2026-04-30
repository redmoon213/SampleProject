#pragma once
#include"Player.h"
#include"Monster.h"
#include<vector>

#include "RingBuffer.h"


class Battle
{
private:
    Player& player;
    Monster& monster;
    std::shared_ptr<Mercenary> mercenary;
    //std::string logMessage;
    RingBuffer<std::string> battleLog; //링버퍼를 통해 최근 5개 전투 메시지를 저장
    
public:
    Battle(Player& player, Monster& monster, std::shared_ptr<Mercenary> merc = nullptr);
    ~Battle();
    bool Run();
    void DisplayScreen();
    void DrawGauge(std::string label, int current, int max);
    void DisplayResult();
};
