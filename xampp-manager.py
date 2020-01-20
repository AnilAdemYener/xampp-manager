#!/usr/bin/env python3
import os, sys


def main():
    if os.path.isfile("/usr/local/bin/xampp-manager/nw/nw") == True and os.path.isdir("/usr/local/bin/xampp-manager/gui/") == True:
        os.system("/usr/local/bin/xampp-manager/nw/nw /usr/local/bin/xampp-manager/gui/. 2>/dev/null")
    else:
        print("did you install it?")
    return


if sys.platform == "linux" or sys.platform == "linux2" and __name__ == "__main__":
    main()
