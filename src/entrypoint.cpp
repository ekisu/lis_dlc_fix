#include <windows.h>
#include "log.hpp"

BOOL initialized = FALSE;

//---------------------------------------------------------------------------
BOOL WINAPI DllMain(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
  if (!initialized) {
    log_set_fp(fopen("lis_dlc_fix_log.txt", "w"));
    #ifndef DEBUG
    log_set_level(LOG_INFO);
    #endif
    log_info("steam_api.dll (lis_dlc_fix) loaded.");

    initialized = TRUE;
  }

  return TRUE;
}
//---------------------------------------------------------------------------
int WINAPI WinMain(      
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow)
{  
  return 0;
}