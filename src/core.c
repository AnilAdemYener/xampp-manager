#include "include/header.h"

#define APP_TITLE "Xampp Manager"
#define APP_ID "xampp-manager"

/*

NOTE!
=====

core c code for xampp manager
=============================
what's behind the function names?
~~~
-- l_* stands for gnu+linux systems
-- w_* stands for windows systems
-- g_* stands for global systems
	(windows, gnu+linux, etc.)

*/

int main(int argc, char *argv[]){
	// linux
	if (strcmp(OS, "linux") == 0){
		if (argc > 1){
			if (strcmp(argv[1], "--sudo-login") == 0){
				char sudo_password[50];
				strcpy(sudo_password, argv[2]);
				l_sudo_login(sudo_password);
				if (strcmp(argv[3], "--xampp-exec") == 0){
					char xampp_cmd[50];
					strcpy(xampp_cmd, argv[4]);
					l_xampp_exec(xampp_cmd);	
				}
			}
			if (strcmp(argv[1], "--debug") == 0){
				l_start_nw("debug");
			}
			if (strcmp(argv[1], "--local") == 0){
				l_start_nw("local");
			}
			if (strcmp(argv[1], "--install") == 0){
				l_install();
			}
			if (strcmp(argv[1], "--uninstall") == 0){
				l_uninstall();
			}
			if (strcmp(argv[1], "--refresh") == 0){
				l_uninstall();
				l_install();
			}
			if (strcmp(argv[1], "--test") == 0){
				g_test();
			}
			if (strcmp(argv[1], "--help") == 0){
				g_help();
			}
		} else {
			//l_start_nw("normal");
			/*

			normal (installed) vers. just not
			working. i don't know why.
			it sucks tho

			*/
			l_start_nw("local");
		}
	}
	
	// windows
	if (strcmp(OS, "windows") == 0){
		g_error_message("windows is not supported yet");
	}

	// unknown
	if (strcmp(OS, "unknown") == 0){
		g_error_message("unknown os\nnot supported");
	}
	return 0;
}
