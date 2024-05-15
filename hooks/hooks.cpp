#include "hooks.h"

#include "../features/menu/menu.h"
#include "../features/visuals/visuals.h"

#include "handles/wndproc.h"
#include "handles/d3d9/present.h"
#include "handles/d3d9/reset.h"

enum paint_mode_t
{
    paint_uipanels = (1 << 0),
    paint_ingamepanels = (1 << 1),
    paint_cursor = (1 << 2)
};

inline void(__fastcall* o_paint) (c_engine_vgui*, int);
void __fastcall paint(c_engine_vgui* engine_vgui, int mode)
{
    o_paint(engine_vgui, mode);

    if (mode & paint_uipanels)
    {
        if (interfaces::engine->is_in_game())
        {
            D3DMATRIX world_to_view, view_to_projection, world_to_pixels;
            interfaces::render_view->get_matrices_for_view(*interfaces::view_render->get_view_setup(), &world_to_view, &view_to_projection, &globals::world_to_projection, &world_to_pixels);

            visuals.run();
        }
    }
}

void hooks::initialize()
{
    if (!min_hook.create_hook((LPVOID)memory::get_virtual((PVOID**)interfaces::engine_vgui, 14), &paint, (LPVOID*)&o_paint))
        throw;

    if (!min_hook.create_hook((LPVOID)memory::pattern_scanner(xorstr("gameoverlayrenderer64.dll"), xorstr("48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 48 89 7C 24 ? 41 54 41 56 41 57 48 81 EC ? ? ? ? 4C 8B A4 24 ? ? ? ?")), &handles::present, (LPVOID*)&handles::originals::present))
        throw;

    if (!min_hook.create_hook((LPVOID)memory::pattern_scanner(xorstr("gameoverlayrenderer64.dll"), xorstr("48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 50 48 8B F2 48 8B F9 48 8B D1")), &handles::reset, (LPVOID*)&handles::originals::reset))
        throw;

    if (!min_hook.enable_hook())
        throw;

    handles::originals::wndproc = (WNDPROC)SetWindowLongPtrW(interfaces::window, GWLP_WNDPROC, (LONG_PTR)handles::wndproc);
}

void hooks::shutdown()
{
    min_hook.remove_all_hooks();

    SetWindowLongPtrW(interfaces::window, GWLP_WNDPROC, (LONG_PTR)handles::originals::wndproc);
}