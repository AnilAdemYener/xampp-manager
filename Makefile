TOOLS_DIR = tools/
PYTHON_DIR = /usr/bin/python3

# compiles app and removes source codes
build: $(TOOLS_DIR)build.py $(PYTHON_DIR)
	./$(TOOLS_DIR)build.py

# just compiles app
build-dev: $(TOOLS_DIR)build-dev.py $(PYTHON_DIR)
	./$(TOOLS_DIR)build-dev.py

# clears nw, exec. it's only recommended
# for git pushing
clear: $(TOOLS_DIR)clear.py $(PYTHON_DIR)
	./$(TOOLS_DIR)clear.py
