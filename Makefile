APP_NAME = Xampp Manager
APP_ID = xampp-manager

PY3 = /usr/bin/python3
CC = /usr/bin/gcc
C_CORE = src/core.c
C_GLOBAL = src/global/g_main.c
C_LINUX = src/linux/l_main.c
C_WINDOWS = src/windows/w_main.c

NW_INSTALLER = tools/nw-installer.py

#C_TOOL_BUILD_LINUX = src/tools/build_linux.c

DEPS = $(PY3) $(CC) $(C_CORE) $(C_GLOBAL) $(C_LINUX) $(C_WINDOWS) $(NW_INSTALLER)

build: $(DEPS)
	@$(PY3) $(NW_INSTALLER) 
	@$(CC) $(C_CORE) $(C_GLOBAL) $(C_LINUX) $(C_WINDOWS) -o $(APP_ID)

clear:
	@sudo rm -rf nw/ $(APP_ID)
