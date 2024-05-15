#include "menu.h"

using namespace ImGui;

void c_menu::run()
{
    if (!opened)
        return;

    Begin(xorstr("TF2"), NULL, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar);
    
    Checkbox(xorstr("Enable"), &settings::visuals::enable);
    Checkbox(xorstr("Box"), &settings::visuals::box);
    Checkbox(xorstr("Name"), &settings::visuals::name);

    if (Button(xorstr("Unload")))
        globals::unload = true;

    End();
}