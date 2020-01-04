#include <iostream>
#include <string.h>
#include <cstring>
#include <unistd.h>

// C LIBRARIES
#include <stdio.h>
#include <stdlib.h>

#include "create-nw-app/create-nw-app.h"

using namespace std;

int FileCheck(char FileName[25]){
	if (access(FileName, F_OK) != -1){
		return 0;
	} else {
		return 1;
	}
}

class xampp {
	public:
		void SudoLogin(char password[25]){
			char cmd[75] = "echo ";
			strcat(cmd, password);
			strcat(cmd, " | sudo -S echo SUDO");
			system(cmd);
			return;
		}
		
		void StartAllServices(){
			system("sudo /opt/lampp/xampp start");			
			return;
		}

		void StopAllServices(){
			system("sudo /opt/lampp/xampp stop");			
			return;
		}

		void OpenDirectory(){
			system("sudo xdg-open /opt/lampp/");
			return;
		}

		// HATA!!! dosya taşıma olmicak faln işte hatırlarsın sonra
		void InstallXampp(){
			if (FileCheck("xampp-linux-x64-7.3.12-0-installer.run") == 1){
				system("wget https://www.apachefriends.org/xampp-files/7.3.12/xampp-linux-x64-7.3.12-0-installer.run");
			}
			system("sudo chmod 777 xampp-linux-x64-7.3.12-0-installer.run");
			system("sudo ./xampp-linux-x64-7.3.12-0-installer.run");
			return;
		}

		void RemoveXampp(){
			if (FileCheck("/opt/lampp/uninstall") == 0){
				system("/opt/lampp/uninstall");
			} else {
				printf("couldn't find uninstall script on your system");
			}
			return;
		}

		void Soon(){
			cout << "soon" << endl;
			return;
		}
};

/*

app stands for create-nw-app
xampp_app stands for xampp class and functions!

*/

int main(int argc, char *argv[]){
  struct nw_app app;
  strcpy(app.nw_path, "nw/nw");
  strcpy(app.app_path, "gui/."); 
	strcpy(app.installer_path, "src/create-nw-app/nw-installer.py");

  xampp xampp_app;

  if (nw_checkOs() == 1){
    if (argc > 1){
      if (strcmp(argv[1], "--debug") == 0){
        nw_runGui("debug", app.nw_path, app.app_path);
      }

      // sudo login and xampp funcs
      if (strcmp(argv[1], "--sudo-login") == 0){
        nw_sudoLogin(argv[2]);
        if (argc > 2){
          if (strcmp(argv[3], "--start-all-services") == 0){
            xampp_app.StartAllServices();
          }

          if (strcmp(argv[3], "--stop-all-services") == 0){
            xampp_app.StopAllServices();
          }

          if (strcmp(argv[3], "--open-directory") == 0){
            xampp_app.OpenDirectory();
          }

          if (strcmp(argv[3], "--install-xampp") == 0){
            xampp_app.InstallXampp();
          }

          if (strcmp(argv[3], "--remove-xampp") == 0){
            xampp_app.RemoveXampp();
          }
        }
      }

    } else {
			nw_checkNw(app.installer_path);
			nw_runGui("normal", app.nw_path, app.app_path);
    }
  } else {
    nw_errorMessage("it's not linux!");
  }
  return 0;
}
