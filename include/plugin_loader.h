#include<vector>
#include<iostream>
#include<dirent.h>
#include<map>
#include "include/plugin.h"




std::vector<PluginInfo> all_plugin_list;
std::map<std::string,void*> my_all_handles;

void regist_plugin(PluginInfo plugin_info);
void display_all_info();
void load_plugins(const char* lib_dir);
void load_a_plugin(std::string lib_name);