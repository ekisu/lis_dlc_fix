SOURCES := src/entrypoint.cpp
SOURCES += src/interfaces_wrapper.cpp
SOURCES += src/log.cpp
SOURCES += src/steamapi_wrapper.cpp
SOURCES += src/steamapps_override.cpp
SOURCES += src/steamgameserver_additional_wrapper.cpp

CC := cl.exe
CCFLAGS := user32.lib /Isteamworks_sdk\public\steam /W4 /WX

LDFLAGS := /WX

all: steam_api.dll

steam_api.dll: $(TMPDIR) $(SOURCES)
	$(CC) /LD $^ $(CCFLAGS) /link $(LDFLAGS) /out:$@

clean:
	cmd /C del *.obj *.exp *.lib steam_api.dll
