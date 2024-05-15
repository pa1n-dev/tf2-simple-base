#pragma once
#include <iostream>
#include <mutex>

#include <d3d9.h>
#include <d3dx9.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")

#include "../dependencies/xorstr/xorstr.h"
#include "../dependencies/memory/memory.h"
#include "../dependencies/minhook/min_hook.h"
#include "../dependencies/imgui/imgui.h"
#include "../dependencies/imgui/imgui_internal.h"
#include "../dependencies/imgui/impl/imgui_impl_dx9.h"
#include "../dependencies/imgui/impl/imgui_impl_win32.h"
#include "../dependencies/imgui/freetype/imgui_freetype.h"

#include "source-sdk/math/vector.h"

#include "source-sdk/enums.h"
#include "source-sdk/definitions.h"

#include "source-sdk/client_class.h"
#include "source-sdk/client/view_setup.h"
#include "source-sdk/client/view_render.h"

#include "source-sdk/client/client_networkable.h"
#include "source-sdk/client/collideable.h"
#include "source-sdk/client/base_entity.h"
#include "source-sdk/client/entity_list.h"

#include "source-sdk/engine/engine_client.h"
#include "source-sdk/engine/engine_vgui.h"
#include "source-sdk/engine/render_view.h"

#include "../utils/utilities.h"
#include "../utils/render.h"
#include "../settings.h"

namespace interfaces
{
	void initialize();

	inline c_engine_client* engine;
	inline c_entity_list* entity_list;
	inline c_engine_vgui* engine_vgui;
	inline c_v_render_view* render_view;
	inline c_view_render* view_render;
	inline HWND window;
}