#ifndef l_main
#define l_main

void l_error_msg(char msg[50]);
int l_file_check(char file_name[50]);
void l_sudo_login(char pass[50]);
void l_nw_installer();
int l_xampp_exec(char section[50]);
void l_install();
void l_uninstall();
void l_start_nw(char opt[50]);
void l_init(int argc, char *argv[]);

#endif // l_main
