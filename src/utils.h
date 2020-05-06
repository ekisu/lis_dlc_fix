#pragma once

#include <windows.h>
#include "log.hpp"

template<typename R, typename... Targs>
R api_call_helper(const char* name, Targs... args) {
    log_debug("api_call_helper: called '%s'", name);
    
    static HINSTANCE handle = NULL;
    if (handle == NULL) {
        handle = LoadLibrary("steam_api_old.dll");
    }

    #pragma warning(suppress: 4191)
    R (*f)(Targs...) = reinterpret_cast<R (*)(Targs...)>(GetProcAddress(handle, name));
    
    return f(args...);
}

#define API_CALL extern "C" __declspec( dllexport )
#define API_CALLTYPE __cdecl
