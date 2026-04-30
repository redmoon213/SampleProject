/*#pragma once
#include <string>
#include <unordered_map>
#include <vector>

// Monster 클래스는 게임 로직(Attack, TakeDamage, ...) + 상속 구조를 담당하고 있기 때문에
// MonsterData는 DB용 데이터를 담당하기 위하여 정의함.
struct MonsterData
{
    int str, dex, vit, eng;
    int xpReward;
    std::vector<int> dropPool;
    
};

std::unordered_map<std::string, MonsterData> createMonsterDB(); //몬스터 DB 생성 함수*/


