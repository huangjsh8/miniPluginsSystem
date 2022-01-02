#include "include/plugin_loader.h"
#include "dlfcn.h"


void regist_plugin(PluginInfo plugin_info){

    all_plugin_list.push_back(plugin_info);
}

void display_all_info(){
    for(auto &&info:all_plugin_list){
        std::cout<<"plugin name :"<<info.plugin_name<<std::endl;
        info.plugin_ptr->display();
    }
}

void load_a_plugin(const char* libname){
    void * handle = dlopen(libname,RTLD_LAZY);
    if(handle!=NULL){
        std::cout<<"[INFO] load "<<libname<<std::endl;
    }
    else{
        std::cout<<"[ERROR] load "<<libname<<" failed"<<std::endl;
    }
}

void load_plugins(const char*lib_dir)
{
    //todo
}