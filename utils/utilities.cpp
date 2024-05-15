#include "utilities.h"
#include <iostream>

bool utilities::game_is_full_loaded()
{
	return GetModuleHandleA(xorstr("gameoverlayrenderer64.dll"))
		&& GetModuleHandleA(xorstr("client.dll"))
		&& GetModuleHandleA(xorstr("engine.dll"));
}

void utilities::attach_console()
{
	AllocConsole();
	freopen(xorstr("conin$"), "r", stdin);
	freopen(xorstr("conout$"), "w", stdout);
	freopen(xorstr("conout$"), "w", stderr);
	SetConsoleTitleA(xorstr("Nixware"));
}

void utilities::detach_console()
{
	fclose(stdin);
	fclose(stdout);
	fclose(stderr);
	FreeConsole();
}

bool utilities::screen_transform(const c_vector& in, c_vector& out)
{
	const D3DMATRIX& matrix = globals::world_to_projection;

	const float w = matrix.m[3][0] * in.x + matrix.m[3][1] * in.y + matrix.m[3][2] * in.z + matrix.m[3][3];
	if (w < 0.001f)
	{
		out.x *= 100000;
		out.y *= 100000;
		return false;
	}

	out.x = matrix.m[0][0] * in.x + matrix.m[0][1] * in.y + matrix.m[0][2] * in.z + matrix.m[0][3];
	out.y = matrix.m[1][0] * in.x + matrix.m[1][1] * in.y + matrix.m[1][2] * in.z + matrix.m[1][3];
	out.z = 0.0f;

	out.x /= w;
	out.y /= w;

	return true;
}

bool utilities::world_to_screen(const c_vector& in, c_vector& out)
{
	if (!screen_transform(in, out))
		return false;

	int w, h;
	interfaces::engine->get_screen_size(w, h);

	out.x = (w / 2.0f) + (out.x * w) / 2.0f;
	out.y = (h / 2.0f) - (out.y * h) / 2.0f;

	return true;
}


bool utilities::get_entity_box(c_base_entity* entity, box_t& box)
{
	c_vector pos = entity->get_abs_origin();
	c_vector mins = pos + entity->get_collidable()->mins();
	c_vector maxs = pos + entity->get_collidable()->maxs();

	c_vector points[] = { c_vector(mins.x, mins.y, mins.z),
						  c_vector(mins.x, maxs.y, mins.z),
						c_vector(maxs.x, maxs.y, mins.z),
						c_vector(maxs.x, mins.y, mins.z),
						c_vector(maxs.x, maxs.y, maxs.z),
						c_vector(mins.x, maxs.y, maxs.z),
						c_vector(mins.x, mins.y, maxs.z),
						c_vector(maxs.x, mins.y, maxs.z) };

	c_vector screen_points[8];

	for (int i = 0; i < 8; ++i)
	{
		if (!world_to_screen(points[i], screen_points[i]))
			return false;
	}

	float left = screen_points[0].x;
	float top = screen_points[0].y;
	float right = screen_points[0].x;
	float bottom = screen_points[0].y;

	for (int i = 1; i < 8; ++i)
	{
		left = min(left, screen_points[i].x);
		top = max(top, screen_points[i].y);
		right = max(right, screen_points[i].x);
		bottom = min(bottom, screen_points[i].y);
	}

	if (isnan(left) || isnan(top) || isnan(right) || isnan(bottom))
		return false;

	box.left = left;
	box.top = top;
	box.right = right;
	box.bottom = bottom;

	return true;
}
