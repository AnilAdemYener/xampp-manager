#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "create-nw-app.h"

int main(){
  struct nw_app app;
  strcpy(app.nw_path, "/usr/local/bin/nw/nw");  
  strcpy(app.app_path, ".");
  strcpy(app.installer_path, "nwjs-installer.py");
  //nw_runGui("normal", app.nw_path, app.app_path);
  return 0;
}
