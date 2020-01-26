#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifdef __linux__
  #define OS 1
#else
  #define OS 0
#endif

void print_screen(char msg[250]){
	system("clear");
	printf("\t\t\n");
	printf("\t-----------------------------------------\n");
	printf("\t                 %s                      \n", msg);
	printf("\t-----------------------------------------\n");
	printf("\t\t\n");
	return;
}

int nw_checkFile(char file_name[50]){
  if (access(file_name, F_OK) != -1){
    return 1;
  } else {
    return 0;
  }
}

void nw_runGui(char mode[15], char temp_nw_path[100], char temp_app_path[100]){
  /*char cmd[350];
  strcat(cmd, temp_nw_path);
  strcat(cmd, " ");
  strcat(cmd, temp_app_path);
  if (strcmp(mode, "normal") == 0){
    strcat(cmd, " 2>/dev/null");
  }
  system(cmd);*/

	char cmd[350];
	if (strcmp(mode, "normal") == 0){
		strcat(cmd, temp_nw_path);
		strcat(cmd, " ");
		strcat(cmd, temp_app_path);
		strcat(cmd, " 2>/dev/null");
	} else if (strcmp(mode, "debug") == 0){
		strcat(cmd, temp_nw_path);
		strcat(cmd, " ");
		strcat(cmd, temp_app_path);
	} else {
		strcpy(cmd, "error");
	}
	system(cmd);
	//print_screen(cmd);
  return;
}

int nw_checkOs(){
  if (OS == 1){
    return 1;
  } else if (OS == 0){
    return 0;
  }
}

void nw_sudoLogin(char password[25]){
  char cmd[75] = "echo ";
  strcat(cmd, password);
  strcat(cmd, " | sudo -S echo SUDO-LOGIN by CREATE-NW-APP");
  system(cmd);
  return;
}

void nw_errorMessage(char custom_msg[25]){
  printf("UPS! There is a error!\n");
  printf("custom error: %s\n", custom_msg);
  return;
}

void nw_checkNw(char temp_nwjsinstaller_path[100]){
  if (nw_checkFile("nw/") == 1){
    return;
  } else {
    char cmd[125] = "./";
    strcat(cmd, temp_nwjsinstaller_path);
    system(cmd);
  }
}
