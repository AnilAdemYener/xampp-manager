#!/usr/bin/env python3
import os, sys

commands = ["rm -rf xampp-manager", "sudo rm -rf nw/"]

class App:
    def clear(self):
        for command in commands:
            os.system(command)
        return

if sys.platform == "linux" or sys.platform == "linux2":
    app = App()
    app.clear()
