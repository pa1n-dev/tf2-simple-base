#pragma once

class c_v_render_view
{
public:
	void get_matrices_for_view(const c_view_setup& view, D3DMATRIX* world_to_view, D3DMATRIX* view_to_projection, D3DMATRIX* world_to_projection, D3DMATRIX* world_to_pixels)
	{
		return memory::call_v_function<void(__thiscall*)(void*, const c_view_setup&, D3DMATRIX*, D3DMATRIX*, D3DMATRIX*, D3DMATRIX*)>(this, 50)(this, view, world_to_view, view_to_projection, world_to_projection, world_to_pixels);
	}
};