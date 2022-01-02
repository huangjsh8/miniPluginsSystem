#include<vector>
#include<iostream>
#include<dirent.h>
#include<map>
#include "include/plugin.h"




static std::vector<PluginInfo*> all_plugin_list; //note that var has to be static to avoid double free
static std::vector<void*> my_all_handles;        //note that var has to be static to avoid double free

void regist_plugin(PluginInfo* plugin_info);
void display_all_info();
void load_plugins(const char* lib_dir);
void load_a_plugin(std::string lib_name);
void close_plugins();