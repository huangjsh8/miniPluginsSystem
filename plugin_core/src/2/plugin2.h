#include "include/plugin.h"

class plugin_2:public Plugin
{
    public:
    plugin_2(){
        name = "plugin_2";
    };
    virtual void display() override;

};