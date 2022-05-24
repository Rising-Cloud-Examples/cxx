# Makefile for Project Stark
# Developed by Aptus Engineering, Inc.
# See LICENSE.md file in project root directory

# Compiler
CXX:= g++

# Executables
LARGE_NUMBERS := largeNumbers

# Libraries

# Library directories
LIB_DIR := -L/usr/lib/x86_64-linux-gnu -L/usr/lib -L/usr/local/lib

# Other libraries
LIB_OTH := -lstdc++fs


LIBS := $(LIB_DIR) $(LIB_OTH)

# Compiler flags
FLAGS := -Ofast -std=c++17 -fPIC -Wno-narrowing

# Make rules
all: $(LARGE_NUMBERS)

$(LARGE_NUMBERS): largeNumbers.cxx
	$(CXX) $^ -o $@ $(LIBS) $(FLAGS)

%.obj: %.cxx
	$(CXX) $(LIBS) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
