#!/usr/bin/env python3
import os, sys

def main():
    if os.path.isdir("nw/") and os.path.isdir("src/") and os.path.exists("/usr/bin/g++"):
        print("#### BUILDING !!")
        os.system("g++ src/main.cpp src/create-nw-app/create-nw-app.c -o xampp-manager 2>/dev/null")
        os.system("./xampp-manager")
        print("after it built you can run it from xampp-manager")
    else:
        if os.path.isdir("nw/") == False:
            os.system("src/create-nw-app/nw-installer.py")
            os.system("./xampp-manager")
        else:
            print("try downloading again")

if __name__ == "__main__" and sys.platform == "linux":
    if len(sys.argv) > 1:
        if sys.argv[1] == "clear":
            os.system("rm -rf xampp-manager xampp-linux-x64-7.3.12-0-installer.run nw/")
    else:
        main()
else:
    print("only works for linux devices")
