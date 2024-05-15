#pragma once
#include "../sdk/interfaces.h"

namespace utilities
{
	bool game_is_full_loaded();
	void attach_console();
	void detach_console();

	bool screen_transform(const c_vector& in, c_vector& out);
	bool world_to_screen(const c_vector& in, c_vector& out);

	bool get_entity_box(c_base_entity* entity, box_t& box);
}