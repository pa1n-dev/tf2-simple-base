#pragma once

class c_entity_list
{
public:
	c_base_entity* get_entity(int index)
	{
		return memory::call_v_function<c_base_entity*(__thiscall*)(void*, int)>(this, 3)(this, index);
	}

	int get_highest_entity_index()
	{
		return memory::call_v_function<int(__thiscall*)(void*)>(this, 6)(this);
	}
};