#include "Barbarian.h"

Barbarian::Barbarian(const std::string& name, bool isHardcore)
    :Player(name, "Barbarian", isHardcore, 100, 5, 100, 5)
{
    
}

int Barbarian::Attack() const
{
    return (int)(attackDamage*1.2f);
}
