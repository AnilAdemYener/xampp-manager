#ifndef create-nw-app
#define create-nw-app


struct nw_app {
  char nw_path[100];  
  char app_path[100];  
};

int nw_check(char file_name[50]);
void nw_runGui(char mode[15], char temp_nw_path[100], char temp_app_path[100]);
int nw_checkOs();
void nw_sudoLogin(char password[25]);
void nw_errorMessage(char custom_msg[25]);

#endif
// create nw app
