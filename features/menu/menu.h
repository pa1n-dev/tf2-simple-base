#pragma once
#include "../../hooks/hooks.h"

class c_menu
{
public:
	void run();

public:
	bool opened = false;
};

inline c_menu menu;