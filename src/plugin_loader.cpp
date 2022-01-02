#include "include/plugin_loader.h"
#include "dlfcn.h"


void regist_plugin(PluginInfo *plugin_info){

    all_plugin_list.push_back(plugin_info);
    
}

void display_all_info(){
    for(PluginInfo* info:all_plugin_list){
        std::cout<<"[INFO] start load a plugin: "<<info->plugin_name<<std::endl;
        info->plugin_ptr->display();
    }
}

void load_a_plugin(std::string libname){
    void * handle = dlopen(libname.c_str(),RTLD_LAZY);
    if(handle!=NULL){
        std::cout<<"[INFO] load "<<libname<<std::endl;
        // my_all_handles.push_back(handle);

    }
    else{
        std::cout<<"[ERROR] load "<<libname<<" failed"<<std::endl;
    }
}

void load_plugins(const char*lib_dir)
{
    //todo
}

void close_plugins()
{
    for(auto handle: my_all_handles)
        dlclose(handle);
    std::cout<<"remove plugin"<<std::endl;
}