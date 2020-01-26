#!/usr/bin/env python3
import sys

'''

it's not a part of
the program at all.
it only stands for
printing titles
"
'''

if len(sys.argv) > 1:
	text = sys.argv[1]
def main():
	print()
	print("|------------------------------------------------")
	print("|")
	print("|                " + text + "                    ")
	print("|")
	print("|------------------------------------------------")
	print()

	return

if len(sys.argv) > 1:
	main()
