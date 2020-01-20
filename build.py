#!/usr/bin/env python3
import os, sys


class Builder:
    def build(self):
        os.system("python3 src/create-nw-app/nw-installer.py")
        os.system("g++ src/main.cpp src/create-nw-app/create-nw-app.c -o funs/xampp-manager")
        return


if sys.platform == "linux" or sys.platform == "linux2" and __name__ == "__main__":
    if os.path.isfile("src/create-nw-app/nw-installer.py") == True and os.path.isfile("/usr/bin/g++"):
        builder = Builder()
        builder.build()
    else:
        print("couldn't find nw-installer.py or g++")
