#include "render.h"

using namespace ImGui;

void c_render::setup(IDirect3DDevice9* device)
{
	if (!initialized)
	{
		CreateContext();
		ImGui_ImplWin32_Init(interfaces::window);
		ImGui_ImplWin32_GetDpiScaleForHwnd(interfaces::window);
		ImGui_ImplDX9_Init(device);

		draw_list = new ImDrawList(GetDrawListSharedData());

		StyleColorsLight();

		ImGuiIO& io = GetIO();

		ImFontConfig cfg = {};

		cfg.PixelSnapH = true;
		cfg.OversampleH = cfg.OversampleV = 1;
		cfg.FontBuilderFlags = ImGuiFreeTypeBuilderFlags_ForceAutoHint;

		io.Fonts->AddFontFromFileTTF("C:/windows/fonts/verdana.ttf", 13.f, &cfg, io.Fonts->GetGlyphRangesCyrillic());

		initialized = true;
	}
}

void c_render::shutdown()
{
	ImGui_ImplDX9_Shutdown();
	ImGui_ImplWin32_Shutdown();
	DestroyContext();
}

void c_render::start()
{
	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	NewFrame();
}

void c_render::end()
{
	EndFrame();
	Render();
	
	ImDrawData* draw_data = GetDrawData();

	if (interfaces::engine->is_in_game())
		draw_data->AddDrawList(draw_list);

	ImGui_ImplDX9_RenderDrawData(draw_data);
}

void c_render::setup_states(IDirect3DDevice9* device)
{
	device->CreateStateBlock(D3DSBT_ALL, &pixel_state);

	pixel_state->Capture();

	device->SetRenderState(D3DRS_LIGHTING, FALSE);
	device->SetRenderState(D3DRS_FOGENABLE, FALSE);
	device->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	device->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);

	device->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
	device->SetRenderState(D3DRS_SCISSORTESTENABLE, TRUE);
	device->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);
	device->SetRenderState(D3DRS_STENCILENABLE, FALSE);

	device->SetRenderState(D3DRS_MULTISAMPLEANTIALIAS, TRUE);
	device->SetRenderState(D3DRS_ANTIALIASEDLINEENABLE, TRUE);

	device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	device->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
	device->SetRenderState(D3DRS_SEPARATEALPHABLENDENABLE, TRUE);
	device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	device->SetRenderState(D3DRS_SRCBLENDALPHA, D3DBLEND_INVDESTALPHA);
	device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	device->SetRenderState(D3DRS_DESTBLENDALPHA, D3DBLEND_ONE);

	device->SetRenderState(D3DRS_SRGBWRITEENABLE, FALSE);
	device->SetRenderState(D3DRS_COLORWRITEENABLE, D3DCOLORWRITEENABLE_RED | D3DCOLORWRITEENABLE_GREEN | D3DCOLORWRITEENABLE_BLUE | D3DCOLORWRITEENABLE_ALPHA);
}

void c_render::backup_states(IDirect3DDevice9* device)
{
	if (!pixel_state)
		return;

	pixel_state->Apply();
	pixel_state->Release();
}

bool c_render::is_initialized()
{
	return initialized;
}

void c_render::begin_frame()
{
	ImGuiIO& io = GetIO();

	render.draw_list->_ResetForNewFrame();
	render.draw_list->PushTextureID(io.Fonts->TexID);
	render.draw_list->PushClipRectFullScreen();
}

void c_render::end_frame()
{
	render.draw_list->PopClipRect();
}

void c_render::line(ImVec2 a, ImVec2 b, float color[4], float thickness)
{
	draw_list->AddLine(a, b, GetColorU32(ImVec4(color[0], color[1], color[2], color[3])), thickness);
}

void c_render::text(ImVec2 from, const char* text, float color[4])
{
	draw_list->AddText(from, GetColorU32(ImVec4(color[0], color[1], color[2], color[3])), text);
}

void c_render::circle(ImVec2 position, float radius, float color[4], int num_segments, float thickness)
{
	draw_list->AddCircle(position, radius, GetColorU32(ImVec4(color[0], color[1], color[2], color[3])), num_segments, thickness);
}

void c_render::rect(ImVec2 from, ImVec2 to, float color[4], float rounding, ImDrawFlags flags, float thickness)
{
	draw_list->AddRect(from, to, GetColorU32(ImVec4(color[0], color[1], color[2], color[3])), rounding, flags, thickness);
}

void c_render::filled_rect(ImVec2 from, ImVec2 to, float color[4], float rounding, ImDrawFlags flags)
{
	draw_list->AddRectFilled(from, to, GetColorU32(ImVec4(color[0], color[1], color[2], color[3])), rounding, flags);
}

void c_render::box(box_t box, float color[4], float thickness)
{
	draw_list->AddLine(ImVec2(box.left, box.bottom), ImVec2(box.left, box.top), GetColorU32(ImVec4(color[0], color[1], color[2], color[3])), thickness);
	draw_list->AddLine(ImVec2(box.left, box.top), ImVec2(box.right, box.top), GetColorU32(ImVec4(color[0], color[1], color[2], color[3])), thickness);
	draw_list->AddLine(ImVec2(box.right, box.top), ImVec2(box.right, box.bottom), GetColorU32(ImVec4(color[0], color[1], color[2], color[3])), thickness);
	draw_list->AddLine(ImVec2(box.right, box.bottom), ImVec2(box.left, box.bottom), GetColorU32(ImVec4(color[0], color[1], color[2], color[3])), thickness);
}