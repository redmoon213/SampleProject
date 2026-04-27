#include "Sorceress.h"

Sorceress::Sorceress(const std::string& name, bool isHardcore)
    :Player(name, "Barbarian", isHardcore, 5, 5, 5, 100)
{
    
}

int Sorceress::Attack() const
{
    
    return (int)(energy * 0.8f);
}
