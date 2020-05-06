#pragma once
#include "utils.h"
#include <steamtypes.h>
// #include <steam_api_common.h>

API_CALL bool API_CALLTYPE SteamAPI_Init();
API_CALL bool API_CALLTYPE SteamAPI_RestartAppIfNecessary(uint32 appId);
API_CALL void API_CALLTYPE SteamAPI_ReleaseCurrentThreadMemory();
API_CALL void API_CALLTYPE SteamAPI_RunCallbacks();
API_CALL void API_CALLTYPE SteamAPI_SetMiniDumpComment(const char* msg);
API_CALL void API_CALLTYPE SteamAPI_Shutdown();
API_CALL void API_CALLTYPE SteamAPI_WriteMiniDump( uint32 uStructuredExceptionCode, void* pvExceptionInfo, uint32 uBuildID );

// Internal functions used by the utility CCallback objects to receive callbacks
API_CALL void API_CALLTYPE SteamAPI_RegisterCallback( void *pCallback, int iCallback );
API_CALL void API_CALLTYPE SteamAPI_UnregisterCallback( void *pCallback );
// Internal functions used by the utility CCallResult objects to receive async call results
API_CALL void API_CALLTYPE SteamAPI_RegisterCallResult( void *pCallback, SteamAPICall_t hAPICall );
API_CALL void API_CALLTYPE SteamAPI_UnregisterCallResult( void *pCallback, SteamAPICall_t hAPICall );