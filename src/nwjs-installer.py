#!/usr/bin/env python3
import os, sys, platform

app_name = "nwjs-installer"

def printinfo(nw_version, arch):
		print("\n               { "+app_name+" }")
		print(" ==> downloading: "+nw_version+"")
		print("  -> your architecture is: "+arch+" byte\n")

def install(location):
	if os.path.isdir("nw"):
		print("there is nw already")
	else:
		nw_version = ""
		arch = 0
		if platform.architecture()[0] == "32bit":
			nw_version = "nwjs-v0.40.1-linux-ia32"
			arch = 32
		elif platform.architecture()[0] == "64bit":
			nw_version = "nwjs-v0.40.1-linux-x64"
			arch = 64
		printinfo(nw_version, str(arch))
		os.system("wget https://dl.nwjs.io/v0.40.1/"+nw_version+".tar.gz")
		os.system("tar -xvf "+nw_version+".tar.gz")
		os.system("rm -rf "+nw_version+".tar.gz")
		os.system("mv "+nw_version+" nw")
		if location != "null":
			os.system("mv nw "+location)

if sys.platform == "linux": # main
	if len(sys.argv) > 1:
		if sys.argv[1] == "--location":
			install(sys.argv[2])
		elif sys.argv[1] == "--install":
			os.system("sudo cp -r nwjs-installer.py /usr/local/bin/"+app_name+".py")
		elif sys.argv[1] == "--uninstall":
			os.system("sudo rm -rf /usr/local/bin/"+app_name+".py")
	else:
		install("null")
