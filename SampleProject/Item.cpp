#include "Item.h"
#include <iostream>
Item::Item()
{
    //std::cout<<"Item 생성자 호출" << std::endl;
}
///
Item::Item(std::string name, ItemType type):name(name), type(type)
{
   // std::cout<<"Item 생성자 호출" << std::endl;
}

Item::~Item()
{
    std::cout<<"<Item 소멸 | "<< name <<">" << std::endl;
}
