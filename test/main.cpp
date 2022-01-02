#include "include/plugin_loader.h"

int main()
{
    char * lib_name = "libMyPlugin.so";
    load_a_plugin(lib_name);
    display_all_info();
    return 0;
}