#!/usr/bin/env python3
import os, sys
import keyboard

class App:
    def run(self, option):
        if option == "debug":
            cmd = "gcc __test.c create-nw-app.c -o __test && ./__test"
        elif option == "normal":
            cmd = "gcc __test.c create-nw-app.c -o __test 2>/dev/null && ./__test"
        
        i = 0
        while i < 25:
            if keyboard.is_pressed("ctrl+q"):
                break
            else:
                print("[CTRL + Q for exit!]")
                print("--------------------\n")
                os.system(cmd)

app = App()
if len(sys.argv) > 1:
    if sys.argv[1] == "--debug":
        app.run("debug")
else:
    app.run("normal")
