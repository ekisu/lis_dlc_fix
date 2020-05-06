#pragma once

#include <steamtypes.h>
#include "utils.h"

typedef uint64 CSteamID;

class ISteamApps
{
public:
	virtual bool BIsSubscribed() = 0;
	virtual bool BIsLowViolence() = 0;
	virtual bool BIsCybercafe() = 0;
	virtual bool BIsVACBanned() = 0;
	virtual const char *GetCurrentGameLanguage() = 0;
	virtual const char *GetAvailableGameLanguages() = 0;

	// only use this member if you need to check ownership of another game related to yours, a demo for example
	virtual bool BIsSubscribedApp( AppId_t appID ) = 0;

	// Takes AppID of DLC and checks if the user owns the DLC & if the DLC is installed
	virtual bool BIsDlcInstalled( AppId_t appID ) = 0;

	// returns the Unix time of the purchase of the app
	virtual uint32 GetEarliestPurchaseUnixTime( AppId_t nAppID ) = 0;

	// Checks if the user is subscribed to the current app through a free weekend
	// This function will return false for users who have a retail or other type of license
	// Before using, please ask your Valve technical contact how to package and secure your free weekened
	virtual bool BIsSubscribedFromFreeWeekend() = 0;

	// Returns the number of DLC pieces for the running app
	virtual int GetDLCCount() = 0;

	// Returns metadata for DLC by index, of range [0, GetDLCCount()]
	virtual bool BGetDLCDataByIndex( int iDLC, AppId_t *pAppID, bool *pbAvailable, char *pchName, int cchNameBufferSize ) = 0;

	// Install/Uninstall control for optional DLC
	virtual void InstallDLC( AppId_t nAppID ) = 0;
	virtual void UninstallDLC( AppId_t nAppID ) = 0;
	
	// Request legacy cd-key for yourself or owned DLC. If you are interested in this
	// data then make sure you provide us with a list of valid keys to be distributed
	// to users when they purchase the game, before the game ships.
	// You'll receive an AppProofOfPurchaseKeyResponse_t callback when
	// the key is available (which may be immediately).
	virtual void RequestAppProofOfPurchaseKey( AppId_t nAppID ) = 0;

	virtual bool GetCurrentBetaName( char *pchName, int cchNameBufferSize ) = 0; // returns current beta branch name, 'public' is the default branch
	virtual bool MarkContentCorrupt( bool bMissingFilesOnly ) = 0; // signal Steam that game files seems corrupt or missing
	virtual uint32 GetInstalledDepots( AppId_t appID, DepotId_t *pvecDepots, uint32 cMaxDepots ) = 0; // return installed depots in mount order

	// returns current app install folder for AppID, returns folder name length
	virtual uint32 GetAppInstallDir( AppId_t appID, char *pchFolder, uint32 cchFolderBufferSize ) = 0;
	virtual bool BIsAppInstalled( AppId_t appID ) = 0; // returns true if that app is installed (not necessarily owned)
	
	// returns the SteamID of the original owner. If this CSteamID is different from ISteamUser::GetSteamID(),
	// the user has a temporary license borrowed via Family Sharing
	virtual CSteamID GetAppOwner() = 0; 

	// Returns the associated launch param if the game is run via steam://run/<appid>//?param1=value1&param2=value2&param3=value3 etc.
	// Parameter names starting with the character '@' are reserved for internal use and will always return and empty string.
	// Parameter names starting with an underscore '_' are reserved for steam features -- they can be queried by the game,
	// but it is advised that you not param names beginning with an underscore for your own features.
	// Check for new launch parameters on callback NewUrlLaunchParameters_t
	virtual const char *GetLaunchQueryParam( const char *pchKey ) = 0; 

	// get download progress for optional DLC
	virtual bool GetDlcDownloadProgress( AppId_t nAppID, uint64 *punBytesDownloaded, uint64 *punBytesTotal ) = 0; 

	// return the buildid of this app, may change at any time based on backend updates to the game
	virtual int GetAppBuildId() = 0;

	// Request all proof of purchase keys for the calling appid and asociated DLC.
	// A series of AppProofOfPurchaseKeyResponse_t callbacks will be sent with
	// appropriate appid values, ending with a final callback where the m_nAppId
	// member is k_uAppIdInvalid (zero).
	virtual void RequestAllProofOfPurchaseKeys() = 0;

	STEAM_CALL_RESULT( FileDetailsResult_t )
	virtual SteamAPICall_t GetFileDetails( const char* pszFileName ) = 0;

	// Get command line if game was launched via Steam URL, e.g. steam://run/<appid>//<command line>/.
	// This method of passing a connect string (used when joining via rich presence, accepting an
	// invite, etc) is preferable to passing the connect string on the operating system command
	// line, which is a security risk.  In order for rich presence joins to go through this
	// path and not be placed on the OS command line, you must set a value in your app's
	// configuration on Steam.  Ask Valve for help with this.
	//
	// If game was already running and launched again, the NewUrlLaunchParameters_t will be fired.
	virtual int GetLaunchCommandLine( char *pszCommandLine, int cubCommandLine ) = 0;

	// Check if user borrowed this game via Family Sharing, If true, call GetAppOwner() to get the lender SteamID
	virtual bool BIsSubscribedFromFamilySharing() = 0;
};

#define OVERRIDE_DEF_IMPL(ret_type, name, argument_list, argument_names) \
    ret_type name##argument_list { \
        log_debug("SteamApps: called '%s'", #name); \
        return m_steamApps->##name##argument_names; \
    }

class SteamAppsOverride : ISteamApps {
public:
    SteamAppsOverride() {
        m_steamApps = api_call_helper<ISteamApps*>("SteamApps");
    }

    OVERRIDE_DEF_IMPL(bool, BIsSubscribed, (), ());
    OVERRIDE_DEF_IMPL(bool, BIsLowViolence, (), ());
    OVERRIDE_DEF_IMPL(bool, BIsCybercafe, (), ());
    OVERRIDE_DEF_IMPL(bool, BIsVACBanned, (), ());
    OVERRIDE_DEF_IMPL(const char*, GetCurrentGameLanguage, (), ());
    OVERRIDE_DEF_IMPL(const char*, GetAvailableGameLanguages, (), ());

    OVERRIDE_DEF_IMPL(bool, BIsSubscribedApp, (AppId_t appID), (appID));
    // OVERRIDE_DEF_IMPL(bool, BIsDlcInstalled, (AppId_t appID), (appID));
    bool BIsDlcInstalled(AppId_t appID);
    
    OVERRIDE_DEF_IMPL(uint32, GetEarliestPurchaseUnixTime, (AppId_t appID), (appID));
    OVERRIDE_DEF_IMPL(bool, BIsSubscribedFromFreeWeekend, (), ());
    OVERRIDE_DEF_IMPL(int, GetDLCCount, (), ());

    OVERRIDE_DEF_IMPL(bool, BGetDLCDataByIndex, (int iDLC, AppId_t *pAppID, bool *pbAvailable, char *pchName, int cchNameBufferSize), (iDLC, pAppID, pbAvailable, pchName, cchNameBufferSize))
    OVERRIDE_DEF_IMPL(void, InstallDLC, (AppId_t appID), (appID));
    OVERRIDE_DEF_IMPL(void, UninstallDLC, (AppId_t appID), (appID));

    OVERRIDE_DEF_IMPL(void, RequestAppProofOfPurchaseKey, (AppId_t appID), (appID));
    OVERRIDE_DEF_IMPL(bool, GetCurrentBetaName, ( char *pchName, int cchNameBufferSize ), (pchName, cchNameBufferSize));
    OVERRIDE_DEF_IMPL(bool, MarkContentCorrupt, ( bool bMissingFilesOnly ), (bMissingFilesOnly));
    OVERRIDE_DEF_IMPL(uint32, GetInstalledDepots, ( AppId_t appID, DepotId_t *pvecDepots, uint32 cMaxDepots ), (appID, pvecDepots, cMaxDepots));

    OVERRIDE_DEF_IMPL(uint32, GetAppInstallDir, ( AppId_t appID, char *pchFolder, uint32 cchFolderBufferSize ), (appID, pchFolder, cchFolderBufferSize));
    OVERRIDE_DEF_IMPL(bool, BIsAppInstalled, (AppId_t appID), (appID));

    OVERRIDE_DEF_IMPL(CSteamID, GetAppOwner, (), ());

    OVERRIDE_DEF_IMPL(const char *, GetLaunchQueryParam, ( const char *pchKey ), (pchKey));
    OVERRIDE_DEF_IMPL(bool, GetDlcDownloadProgress, ( AppId_t nAppID, uint64 *punBytesDownloaded, uint64 *punBytesTotal ), (nAppID, punBytesDownloaded, punBytesTotal));

    OVERRIDE_DEF_IMPL(int, GetAppBuildId, (), ());
    OVERRIDE_DEF_IMPL(void, RequestAllProofOfPurchaseKeys, (), ());

    OVERRIDE_DEF_IMPL(SteamAPICall_t, GetFileDetails, ( const char* pszFileName ), (pszFileName));

    OVERRIDE_DEF_IMPL(int, GetLaunchCommandLine, ( char *pszCommandLine, int cubCommandLine ), (pszCommandLine, cubCommandLine));

    OVERRIDE_DEF_IMPL(bool, BIsSubscribedFromFamilySharing, (), ());
private:
    ISteamApps* m_steamApps;
};
