#include "interfaces.h"

void interfaces::initialize()
{
	engine = memory::capture_interface<c_engine_client>(xorstr("engine.dll"), xorstr("VEngineClient013"));
	if (!engine)
		throw;

	entity_list = memory::capture_interface<c_entity_list>(xorstr("client.dll"), xorstr("VClientEntityList003"));
	if (!entity_list)
		throw;

	engine_vgui = memory::capture_interface<c_engine_vgui>(xorstr("engine.dll"), xorstr("VEngineVGui002"));
	if (!engine_vgui)
		throw;

	render_view = memory::capture_interface<c_v_render_view>(xorstr("engine.dll"), xorstr("VEngineRenderView014"));
	if (!render_view)
		throw;

	engine_vgui = memory::capture_interface<c_engine_vgui>(xorstr("engine.dll"), xorstr("VEngineVGui002"));
	if (!engine_vgui)
		throw;

	view_render = memory::get_vmt_from_instruction<c_view_render>((uintptr_t)memory::pattern_scanner(xorstr("client.dll"), xorstr("48 8B 0D ? ? ? ? 48 8B 01 48 FF 60 30 CC CC 48 83 EC 28")));
	if (!view_render)
		throw;
	
	window = FindWindowW(xorstr(L"Valve001"), NULL);
	if (!window)
		throw;
}