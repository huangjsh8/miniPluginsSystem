#include "include/plugin.h"

class plugin_1:public Plugin
{
    public:
    plugin_1(){
        name = "plugin_1";
    };
    ~plugin_1();
    virtual void display() override;

};

REGISTER_PLUGIN(plugin_1)   