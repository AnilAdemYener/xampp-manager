#include <iostream>
#include <string.h>
#include <cstring>
#include <unistd.h>

// C LIBRARIES
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#ifdef __linux__
	#define OS 0
#else
	#define OS 1
#endif

int FileCheck(char FileName[25]){
	if (access(FileName, F_OK) != -1){
		return 0;
	} else {
		return 1;
	}
}

class xampp {
	public:
		void StartGui(){
			if (FileCheck("nw/") == 1){
				system("src/nwjs-installer.py");
				system("nw/nw gui/. 2>/dev/null");
			} else {
				system("nw/nw gui/. 2>/dev/null");
			}
			return;
		}

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

int main(int argc, char *argv[]){
	if (OS == 0){
		xampp app;
		if (argc > 1){
			for (int i=0; i<argc; i++){
				if (strcmp(argv[i], "--sudo-login") == 0){
					app.SudoLogin(argv[i+1]);	
			
					if (strcmp(argv[i+2], "--start-all-services") == 0){
						app.StartAllServices();	
					}

					if (strcmp(argv[i+2], "--stop-all-services") == 0){
						app.StopAllServices();
					}

					if (strcmp(argv[i+2], "--open-directory") == 0){
						app.OpenDirectory();
					}

					if (strcmp(argv[i+2], "--install-xampp") == 0){
						app.InstallXampp();
					}

					if (strcmp(argv[i+2], "--remove-xampp") == 0){
						app.RemoveXampp();
					}
				}
			}
		} else {
			app.StartGui();
		}
	} else {
		cout << "only for linux!" << endl;
	}
	return 0;
}
