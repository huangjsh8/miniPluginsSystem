#include "include/plugin_loader.h"

int main()
{
    std::string lib_name = "./plugin_core/libMyPlugin.so";
    load_a_plugin(lib_name);
    display_all_info();
    close_plugins();
    return 0;
}