#!/usr/bin/env python3
import os
import keyboard

i = 0
while i < 25:
    if keyboard.is_pressed("ctrl+q"):
        break
    else:
        print("[CTRL + Q for exit!]")
        print("--------------------")
        os.system("gcc main.c create-nw-app.c 2>/dev/null && ./a.out")
