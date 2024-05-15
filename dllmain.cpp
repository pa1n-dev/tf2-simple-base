﻿#include "hooks/hooks.h"

DWORD WINAPI initialize(HMODULE base)
{
    while (!utilities::game_is_full_loaded())
        Sleep(1000);

#ifdef _DEBUG
    utilities::attach_console();
#endif

    interfaces::initialize();
    hooks::initialize();

    while (!globals::unload)
        Sleep(1000);

    FreeLibraryAndExitThread(base, EXIT_SUCCESS);

    return TRUE;
}

BOOL WINAPI shutdown()
{
#ifdef _DEBUG
    utilities::detach_console();
#endif

    hooks::shutdown();
    render.shutdown();

    return TRUE;
}

BOOL WINAPI DllMain(HMODULE base, DWORD ul_reason_for_call, LPVOID reserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
        DisableThreadLibraryCalls(base);
        CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)initialize, base, 0, nullptr);
        
        return TRUE;
    }

    case DLL_PROCESS_DETACH:
    {
        if (reserved == nullptr)
            return shutdown();

        return TRUE;
    }

    default:
        return TRUE;
    }
}