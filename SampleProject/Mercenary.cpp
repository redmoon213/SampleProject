#include "Mercenary.h"

Mercenary::Mercenary(std::string nameInput, int atkDamageInput, std::shared_ptr<Player> ownerInput)
    :name(nameInput), attackDamage(atkDamageInput), owner(ownerInput)
{
    std::cout << "<용병 고용> " << name << "가 합류하였습니다\n";
}

Mercenary::~Mercenary()
{
    std::cout << "<용병 소멸> \n";
}
