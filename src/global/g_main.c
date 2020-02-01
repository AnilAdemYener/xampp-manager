#include "../include/header.h"

void g_error_message(char msg[50]){
	printf("error\n=====\n==> %s\n", msg);
	return;
}

void g_help(){
	g_error_message("help texts are not ready yet");
	return;
}

void g_test(){
	printf("OS: %s\n", OS);
	return;
}
