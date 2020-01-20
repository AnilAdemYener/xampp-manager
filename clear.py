#!/usr/bin/env python3
import os, sys


class Clr:
    def clear(self):
        os.system("sudo rm -rf nw/")
        os.system("sudo rm -rf funs/xampp-manager")
        return


if sys.platform == "linux" or sys.platform == "linux2" and __name__ == "__main__":
    clr = Clr()
    clr.clear()
