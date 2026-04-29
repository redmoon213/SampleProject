#pragma once
#include <memory>
#include <string>
#include<iostream>
#include "Player.h"

class Mercenary
{
private:
    std::string name;
    int attackDamage;
public:
    std::weak_ptr<Player> owner;
    
    Mercenary(std::string nameInput, int atkDamageInput, std::shared_ptr<Player> ownerInput);
    ~Mercenary();
    
    std::string GetName() const {return name;}
    int Attack() const {return attackDamage;}
    bool IsOwnerAlive() const {return !owner.expired();}
    
    
};
