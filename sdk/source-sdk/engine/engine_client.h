#pragma once

class c_engine_client
{
public:
	void get_screen_size(int& width, int& height)
	{
		return memory::call_v_function<void(__thiscall*)(void*, int&, int&)>(this, 5)(this, width, height);
	}

	int get_local_player()
	{
		return memory::call_v_function<int(__thiscall*)(void*)>(this, 12)(this);
	}

	bool is_in_game()
	{
		return memory::call_v_function<bool(__thiscall*)(void*)>(this, 26)(this);
	}
};