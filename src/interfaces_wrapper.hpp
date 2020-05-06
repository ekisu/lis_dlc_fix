#pragma once

#include "utils.h"

#define INTERFACE_WRAPPER_SIGNATURE(interface) \
    API_CALL void* API_CALLTYPE interface()

#define INTERFACE_WRAPPER(interface) \
    void* interface () { \
        return api_call_helper<void*>(#interface); \
    }

INTERFACE_WRAPPER_SIGNATURE(SteamApps);
INTERFACE_WRAPPER_SIGNATURE(SteamFriends);
INTERFACE_WRAPPER_SIGNATURE(SteamGameServer);
INTERFACE_WRAPPER_SIGNATURE(SteamGameServerNetworking);
INTERFACE_WRAPPER_SIGNATURE(SteamGameServerStats);
INTERFACE_WRAPPER_SIGNATURE(SteamGameServerUtils);
INTERFACE_WRAPPER_SIGNATURE(SteamMatchmaking);
INTERFACE_WRAPPER_SIGNATURE(SteamMatchmakingServers);
INTERFACE_WRAPPER_SIGNATURE(SteamNetworking);
INTERFACE_WRAPPER_SIGNATURE(SteamRemoteStorage);
INTERFACE_WRAPPER_SIGNATURE(SteamUser);
INTERFACE_WRAPPER_SIGNATURE(SteamUserStats);
INTERFACE_WRAPPER_SIGNATURE(SteamUtils);
