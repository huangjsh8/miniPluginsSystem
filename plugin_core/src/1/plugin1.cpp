#include "plugin1.h"

void plugin_1::display()
{
    std::cout<<"1: firrst plugin name is  "<<name<<std::endl;
}

REGISTER_PLUGIN(plugin_1)   