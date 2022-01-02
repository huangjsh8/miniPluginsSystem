#include "plugin2.h"

void plugin_2::display()
{
    std::cout<<"2: second plugin name is  "<<name<<std::endl;
}
REGISTER_PLUGIN(plugin_2);