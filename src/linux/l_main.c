#include "../include/header.h"

void l_error_msg(char msg[50]){
	printf("error\n=====\n==> %s\n", msg);
	return;
}

int l_file_check(char file_name[50]){
	if (access(file_name, F_OK) != -1){
		return 0;
	} else {
		return 1;
	}
}

void l_sudo_login(char pass[50]){
	char cmd[100] = "echo ";
	strcat(cmd, pass);
	strcat(cmd, " | sudo -S echo ''");
	system(cmd);
	return;
}

void l_nw_installer(){
	char nw_inst_path[25] = "tools/nw-installer.py";
	if (l_file_check(nw_inst_path) == 0){
		char cmd[50] = "python3 ";
		strcat(cmd, nw_inst_path);
		system(cmd);
	} else {
		l_error_msg("couldn't find nw-installer.py");
	}
	return;
}

int l_xampp_exec(char section[50]){
	if (l_file_check("/opt/lampp/xampp") == 0){
		char cmd[150] = "sudo /opt/lampp/xampp ";
		strcat(cmd, section);
		system(cmd);
		return 0;
	} else {
		return 1;
	}
}

void l_install(){
	// !!
	char cmd1[100] = "sudo mkdir /usr/local/bin/xampp-manager_files/";
	char cmd2[100] = "sudo cp -r * /usr/local/bin/xampp-manager_files/";
	char cmd3[100] = "sudo cp -r xampp-manager /usr/local/bin/xampp-manager";
	char cmd4[100] = "sudo cp -r gui/xampp-manager.desktop ~/.local/share/applications/";
	system(cmd1);
	system(cmd2);
	system(cmd3);
	system(cmd4);
	printf("installed\n");
	return;
}

void l_uninstall(){
	// !!
	char cmd1[100] = "sudo rm -rf /usr/local/bin/xampp-manager*";
	char cmd2[100] = "sudo rm -rf ~/.local/share/applications/xampp-manager.desktop";
	system(cmd1);
	system(cmd2);
	printf("uninstalled\n");
	return;
}

void l_start_nw(char opt[50]){
/*
opt stands for option
such as 'normal', 'debug' 'local'
*/
	if (strcmp(opt, "local") == 0){
		if (l_file_check("nw/nw") == 0){
			system("nw/nw gui/. 2>/dev/null");	
		} else {
			// nw installer	
		}
	}
	else {
		if (l_file_check("/usr/local/bin/xampp-manager_files/") == 0){
			if (strcmp(opt, "normal") == 0){
				system("/usr/local/bin/xampp-manager_files/nw/nw /usr/local/bin/xampp-manager_files/gui/. 2>/dev/null");
			}
			if (strcmp(opt, "debug") == 0){
				system("/usr/local/bin/xampp-manager_files/nw/nw /usr/local/bin/xampp-manager_files/gui/.");
			}
		} else {
			l_error_msg("couldn't find files. did you install it first?");
		}
	}
	return;
}

void l_init(int argc, char *argv[]){
	for (int i=0; i<argc; i++){
		printf("-> %s\n", argv[i]);
	}
	return;
}
