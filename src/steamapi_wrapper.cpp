#include <windows.h>
#include <steamtypes.h>
#include "steamapi_wrapper.hpp"
#include "utils.h"
#include "log.hpp"

bool SteamAPI_Init() {
    return api_call_helper<bool>("SteamAPI_Init");
}

bool SteamAPI_RestartAppIfNecessary(uint32 appId) {
    return api_call_helper<bool>("SteamAPI_RestartAppIfNecessary", appId);
}

void SteamAPI_ReleaseCurrentThreadMemory() {
    return api_call_helper<void>("SteamAPI_ReleaseCurrentThreadMemory");
}

void SteamAPI_RunCallbacks() {
    return api_call_helper<void>("SteamAPI_RunCallbacks");
}

void SteamAPI_SetMiniDumpComment(const char* msg) {
    return api_call_helper<void>("SteamAPI_SetMiniDumpComment", msg);
}

void SteamAPI_Shutdown() {
    return api_call_helper<void>("SteamAPI_Shutdown");
}

void SteamAPI_WriteMiniDump( uint32 uStructuredExceptionCode, void* pvExceptionInfo, uint32 uBuildID ) {
    return api_call_helper<void>("SteamAPI_WriteMiniDump", uStructuredExceptionCode, pvExceptionInfo, uBuildID);
}

API_CALL void API_CALLTYPE SteamAPI_RegisterCallback( void *pCallback, int iCallback ) {
    return api_call_helper<void>("SteamAPI_RegisterCallback", pCallback, iCallback);
}

API_CALL void API_CALLTYPE SteamAPI_UnregisterCallback( void *pCallback ) {
    return api_call_helper<void>("SteamAPI_UnregisterCallback", pCallback);
}

API_CALL void API_CALLTYPE SteamAPI_RegisterCallResult( void *pCallback, SteamAPICall_t hAPICall ) {
    return api_call_helper<void>("SteamAPI_RegisterCallResult", pCallback, hAPICall);
}

API_CALL void API_CALLTYPE SteamAPI_UnregisterCallResult( void *pCallback, SteamAPICall_t hAPICall ) {
    return api_call_helper<void>("SteamAPI_UnregisterCallResult", pCallback, hAPICall);
}
