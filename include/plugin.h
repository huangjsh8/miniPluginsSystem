
#ifndef _PLUGIN_
#define _PLUGIN_
#include<iostream>
class Plugin
{
    public:
        Plugin(){};
        std::string name="base";
        void display_base();
        virtual void display()=0;
};

struct PluginInfo
{
    Plugin * plugin_ptr;
    std::string plugin_name;
    PluginInfo(Plugin* ptr,std::string name){
        plugin_ptr = ptr;
        plugin_name = name;
    }
};


void regist_plugin(PluginInfo *plugin_info);

class PluginLoaderHelper{
public:
    PluginLoaderHelper(PluginInfo *info){
        regist_plugin(info);
    }

};

//生成一个对象，生成一个info，对象指针给info，info再放进PluginLoaderHelper

#define REGISTER_PLUGIN(class_name) \
    Plugin * get_##class_name##_instance(){   \
        static class_name  object;      \
        return &object;                           \
    };                                        \
    PluginInfo class_name##_info(get_##class_name##_instance(),#class_name);  \
    static PluginLoaderHelper class_name##_plugin_loader_helper(&class_name##_info);

#endif

    