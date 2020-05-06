#include <windows.h>
#include "log.hpp"

BOOL initialized = FALSE;

//---------------------------------------------------------------------------
BOOL WINAPI DllMain(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
  (void) hinst, reason, lpReserved;

  if (!initialized) {
    FILE* log_file = NULL;
    errno_t err;

    if ((err = fopen_s(&log_file, "lis_dlc_fix_log.txt", "w")) != 0) {
      MessageBox(NULL, "Couldn't open log file!", "lis_dlc_fix", NULL);
      return FALSE;
    }

    log_set_fp(log_file);
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
  (void) hInstance, hPrevInstance, lpCmdLine, nCmdShow;

  return 0;
}