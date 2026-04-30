#include "MonsterData.h"

//Monster 밸런스 조정, 추가 시에 이 파일만 수정할 수 잇게 

std::unordered_map<std::string, MonsterData> createMonsterDB()
{
    std::unordered_map<std::string, MonsterData> db;
    
    db["Goblin"] =      {50, 40, 30, 20, 10, {303, 404, 101}};
    db["FireGoblin"] =  {40,10,20,0,20,{101, 102, 201, 202, 301}};
    db["Ghost"] =       {10,0,10,50,20,{401, 403}};
    db["LastBoss"] =    {70,70,70,70,100,{101, 102, 103, 201, 202, 203, 301, 302, 303, 401, 402, 403}};
    return db;
}