#
# xampp manager 2019-2020
#

# vars
ID = xampp-manager
APP_NAME = Xampp Manager

TOOLS_DIR = tools/
PYTHON = python3
PYTHON_DIR = /usr/bin/python3

# custom printer
PRINTER = $(TOOLS_DIR)printer.py

# compiles app and removes source codes
build: $(TOOLS_DIR)build.py $(PYTHON_DIR)
	@$(PYTHON) $(PRINTER) '$(APP_NAME)'
	@$(PYTHON) $(TOOLS_DIR)build.py
	@$(PYTHON) $(PRINTER) 'BUILT'

# just compiles app
build-dev: $(TOOLS_DIR)build-dev.py $(PYTHON_DIR)
	@$(PYTHON) $(PRINTER) '$(APP_NAME)'
	@$(PYTHON) $(TOOLS_DIR)build-dev.py
	@$(PYTHON) $(PRINTER) 'BUILT (DEV)'

# clears nw, exec. it's only recommended
# for git pushing
clear: $(TOOLS_DIR)clear.py $(PYTHON_DIR)
	@$(PYTHON) $(PRINTER) '$(APP_NAME)'
	@$(PYTHON) $(TOOLS_DIR)clear.py
	@$(PYTHON) $(PRINTER) 'CLEARED'
