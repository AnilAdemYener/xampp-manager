#!/usr/bin/env python3

'''

// xampp manager - for linux systems

this build script is only for developers
of this project. if you know what you're
doing or want to keep source files after
compiling, you can use this script

- anilademyener@github.com
- anilademyener@gmail.com


differences between build.py
============================
this script won't remove source
files such as main.cpp or create-
nw-app.c/.h

'''

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
