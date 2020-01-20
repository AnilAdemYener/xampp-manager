#!/usr/bin/env python3
import os, sys


class Installer:
    def install(self):
        if os.path.isdir("/usr/local/bin/xampp-manager/") == False:
            if os.path.isfile("nw/nw") == True:
                os.system("sudo mkdir /usr/local/bin/xampp-manager/")
                os.system("sudo cp -r * /usr/local/bin/xampp-manager/")
                os.system("sudo cp -r xampp-manager.py /usr/local/bin/xampp-manager-devel")
            else:
                print("do you have nw/ in your dir?")
        else:
            print("it's installed on your system already?")
        return


if sys.platform == "linux" or sys.platform == "linux2" and __name__ == "__main__":
    if os.path.isfile("funs/xampp-manager") == True:
        installer = Installer()
        installer.install()
    else:
        print("first you need to build")
