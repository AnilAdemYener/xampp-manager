#!/usr/bin/env python3
import os
import sys

app_name = "xampp-manager"
compiler = "g++"
compiler_path = "/usr/bin/" + compiler
build_command = compiler + \
    " src/main.cpp src/create-nw-app/create-nw-app.c -o " + app_name


class App:
    def error(self, msg):
        print("\t " + app_name + " \t\t")
        print("------------------------")
        print("ERROR: ")
        print("==> " + msg)
        return

    def build(self):
        os.system(build_command)
        os.system("clear")
        print("you can execute this app with ./xampp-manager command")
        return


if sys.platform == "linux" or sys.platform == "linux2":
    app = App()
    if os.path.isfile(compiler_path) == True:
        if os.path.isdir("nw/") == True:
            app.build()
        else:
            if os.path.isfile("src/create-nw-app/nw-installer.py") == True:
                os.system("src/create-nw-app/nw-installer.py")
                app.build()
            else:
                app.error("couldn't find nw-installer.py\ninstall again")
    else:
        app.error("g++ compiler isn't installed")
