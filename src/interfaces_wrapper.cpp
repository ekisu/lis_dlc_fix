#include "interfaces_wrapper.hpp"
#include "steamapps_override.hpp"
#include "utils.h"

// INTERFACE_WRAPPER(SteamApps);
void* SteamApps() {
    static SteamAppsOverride* ourApps = nullptr;

    if (ourApps == nullptr) {
        ourApps = new SteamAppsOverride();
    }

    return ourApps;
}

INTERFACE_WRAPPER(SteamFriends);
INTERFACE_WRAPPER(SteamGameServer);
INTERFACE_WRAPPER(SteamGameServerNetworking);
INTERFACE_WRAPPER(SteamGameServerStats);
INTERFACE_WRAPPER(SteamGameServerUtils);
INTERFACE_WRAPPER(SteamMatchmaking);
INTERFACE_WRAPPER(SteamMatchmakingServers);
INTERFACE_WRAPPER(SteamNetworking);
INTERFACE_WRAPPER(SteamRemoteStorage);
INTERFACE_WRAPPER(SteamUser);
INTERFACE_WRAPPER(SteamUserStats);
INTERFACE_WRAPPER(SteamUtils);