#pragma once

class i_client_networkable
{
public:
	c_client_class* get_client_class()
	{
		return memory::call_v_function<c_client_class*(__thiscall*)(void*)>(this, 2)(this);
	}

	bool is_dormant()
	{
		return memory::call_v_function<bool(__thiscall*)(void*)>(this, 8)(this);
	}
};