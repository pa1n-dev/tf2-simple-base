#pragma once

class c_base_entity
{
public:
	i_collideable* get_collidable()
	{
		return memory::call_v_function<i_collideable*(__thiscall*)(void*)>(this, 3)(this);
	}

	i_client_networkable* get_networkable()
	{
		return memory::call_v_function<i_client_networkable*(__thiscall*)(void*)>(this, 4)(this);
	}

	const c_vector& get_abs_origin()
	{
		return memory::call_v_function<c_vector & (__thiscall*)(void*)>(this, 9)(this);
	}

	unsigned char get_life_state()
	{
		return *(unsigned char*)((uintptr_t)this + 225);
	}

	int get_team_number()
	{
		return *(int*)((uintptr_t)this + 236);
	}

	tf_class_id get_class_id()
	{
		c_client_class* client_class = get_networkable()->get_client_class();
		return client_class ? tf_class_id(client_class->class_id) : tf_class_id(0);
	}

	bool is_player()
	{
		return (get_class_id() == tf_class_id::c_tf_player);
	}

	bool is_alive()
	{
		return (get_life_state() == LIFE_ALIVE);
	}
};