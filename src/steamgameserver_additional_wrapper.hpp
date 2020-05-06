#pragma once

#include "utils.h"
#include <steamtypes.h>

enum EServerMode
{
	eServerModeInvalid = 0, // DO NOT USE		
	eServerModeNoAuthentication = 1, // Don't authenticate user logins and don't list on the server list
	eServerModeAuthentication = 2, // Authenticate users, list on the server list, don't run VAC on clients that connect
	eServerModeAuthenticationAndSecure = 3, // Authenticate users, list on the server list and VAC protect clients
};

API_CALL uint64 SteamGameServer_GetSteamID();
API_CALL bool SteamGameServer_Init( uint32 unIP, uint16 usSteamPort, uint16 usGamePort, uint16 usQueryPort, EServerMode eServerMode, const char *pchVersionString );
API_CALL void API_CALLTYPE SteamGameServer_RunCallbacks();
API_CALL void SteamGameServer_Shutdown();
