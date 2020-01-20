#!/usr/bin/env python3
import os, sys


class Uninstaller:
    def uninstall(self):
        os.system("sudo rm -rf /usr/local/bin/xampp-manager/")
        os.system("sudo rm -rf /usr/local/bin/xampp-manager-devel")
        return


if sys.platform == "linux" or sys.platform == "linux2" and __name__ == "__main__":
    if os.path.isdir("/usr/local/bin/xampp-manager/") == True:
        uninstaller = Uninstaller()
        uninstaller.uninstall()
    else:
        print("couldn't find xampp-manager in your system")
