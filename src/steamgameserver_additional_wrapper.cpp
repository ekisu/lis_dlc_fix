#include "steamgameserver_additional_wrapper.hpp"

uint64 SteamGameServer_GetSteamID() {
    return api_call_helper<uint64>("SteamGameServer_GetSteamID");
}

bool SteamGameServer_Init( uint32 unIP, uint16 usSteamPort, uint16 usGamePort, uint16 usQueryPort, EServerMode eServerMode, const char *pchVersionString ) {
    return api_call_helper<uint64>("SteamGameServer_Init", unIP, usSteamPort, usGamePort);
}

void API_CALLTYPE SteamGameServer_RunCallbacks() {
    return api_call_helper<void>("SteamGameServer_RunCallbacks");
}

void SteamGameServer_Shutdown() {
    return api_call_helper<void>("SteamGameServer_Shutdown");
}
