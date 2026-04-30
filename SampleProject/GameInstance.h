#pragma once
#include <iostream>
#include <unordered_map>
#include "ItemData.h"
#include "MonsterData.h"

class GameInstance
{
private:
    GameInstance()
    {
        std::cout<<"\n[Game Instance]\n *****생성자 호출***** \n (this = "<<this<<std::endl;
        itemDB= CreateItemDB();
        monsterDB= createMonsterDB();
        
    }
    
    ~GameInstance()
    {
        std::cout<<"[Game Instance] 소멸자 호출 \n";
    }
    
    GameInstance(const GameInstance&) = delete;
    GameInstance& operator=(const GameInstance&) = delete;
public:
    static GameInstance& GetGameInstance()
    {
        static GameInstance instance;
        return instance;
    }
    
    std::unordered_map<int, ItemData> itemDB;
    std::unordered_map<std::string, MonsterData> monsterDB;
};
