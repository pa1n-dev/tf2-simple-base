#pragma once
#include "../sdk/interfaces.h"

class c_render
{
public:
	void setup(IDirect3DDevice9* device);
	void shutdown();

	void start();
	void end();

	void setup_states(IDirect3DDevice9* device);
	void backup_states(IDirect3DDevice9* device);

	bool is_initialized();

public:	
	void begin_frame();
	void end_frame();

	void line(ImVec2 a, ImVec2 b, float color[4], float thickness);
	void text(ImVec2 from, const char* text, float color[4]);
	void circle(ImVec2 position, float radius, float color[4], int num_segments, float thickness);
	void rect(ImVec2 from, ImVec2 to, float color[4], float rounding, ImDrawFlags flags, float thickness);
	void filled_rect(ImVec2 from, ImVec2 to, float color[4], float rounding, ImDrawFlags flags = 0);
	void box(box_t box, float color[4], float thickness);

private:
	bool initialized = false;

	ImDrawList* draw_list;
	IDirect3DStateBlock9* pixel_state = nullptr;
};

inline c_render render;