#include "visuals.h"

using namespace ImGui;

void c_visuals::run()
{
	if (!render.is_initialized())
		return;

	c_base_entity* local_player = interfaces::entity_list->get_entity(interfaces::engine->get_local_player());
	if (!local_player)
		return;

	render.begin_frame();

	for (int i = 0; i <= interfaces::entity_list->get_highest_entity_index(); i++)
	{
		c_base_entity* entity = interfaces::entity_list->get_entity(i);
		if (!entity)
			continue;

		if (entity->is_player())
		{
			if (!settings::visuals::enable)
				continue;

			if (!entity->is_alive())
				continue;

			if (entity->get_networkable()->is_dormant())
				continue;

			if (entity == local_player)
				continue;

			if (entity->get_team_number() == local_player->get_team_number())
				continue;

			box_t box;
			if (!utilities::get_entity_box(entity, box))
				continue;

			if (settings::visuals::box)
				render.box(box, settings::visuals::colors::box, 1.f);
		}
		else
		{

		}
	}

	render.end_frame();
}