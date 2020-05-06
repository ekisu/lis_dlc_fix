# lis_dlc_fix

A small steam_api.dll wrapper, intended for use with family-shared copies of Life is Strange. It fixes the bug where you have the DLCs installed, but they still won't show as enabled in game.

# Installation

Inside `(SteamLibrary)\steamapps\common\Life Is Strange\Binaries\Win32`:
- Rename the original `steam_api.dll` to `steam_api_old.dll`.
- Place the wrapper, `steam_api.dll`, in the folder.

Now simply launch the game via the Steam client.

# How it works

We simply intercept the call made to `SteamApps()->BIsDlcInstalled(appID)`, returning `true`. Other `steam_api.dll` calls are transparently forwarded to the original `steam_api_old.dll`.

# Building

~please dont~uhh install msvc and make use vcvars32.bat place steamworks sdk into steamworks_sdk run make done

you can add /DDEBUG to the makefile flags for extra ~excruciating pain and horrifying details~fun in the log files!
