#include "steamapps_override.hpp"

bool SteamAppsOverride::BIsDlcInstalled(AppId_t appID) {
    log_info("SteamApps: called 'BIsDlcInstalled' (custom wrapper)");
    bool returnValue = m_steamApps->BIsDlcInstalled(appID);

    log_info("SteamApps: 'BIsDlcInstalled' returned %s, overriding with true.", returnValue ? "true" : "false");
    return true;
}
