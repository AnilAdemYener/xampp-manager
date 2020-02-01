#!/usr/bin/env python3
import os, sys

'''

this script is
written for
gnu+linux systems
if you're not
python3 dev.
maybe you
shouldn't
edit this

'''

def error_msg(msg):
	print("error")
	print("=====")
	print("==> " + msg)
	return

class App:
	def check_deps(self):
		are_deps_ok = 0
		deps = [
			'/usr/bin/gcc',
			'tools/nw-installer.py'
		]
		for dep in deps:
			if os.path.isfile(dep) == True:
				are_deps_ok = are_deps_ok + 1
		if are_deps_ok == len(deps):
			return 0
		else:
			return 1

	def check_nw(self):
		nw_path = "nw/nw"
		nw_inst_path = "tools/nw-installer.py"
		if os.path.isfile(nw_path) == False:
			if os.path.isfile(nw_inst_path) == True:
				os.system("python3 " + nw_inst_path)
			else:
				error_msg("couldn't find nw-installer.py")
		return

	def build(self):
		if self.check_deps() == 1:
			return 1
		else:
			self.check_nw()
			build_cmds = [
				'gcc src/core.c src/global/g_main.c src/linux/l_main.c -o xampp-manager'
			]
			for build_cmd in build_cmds:
				os.system(build_cmd)
			print("BUILT")
			return 0

if sys.platform == "linux" and __name__ == "__main__":
	app = App()
	app.build()
