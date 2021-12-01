CC       := g++
CXXFLAGS := --std=c++17 -Wall

DUMMY != mkdir -p build

.PHONY: all


all: build/01a.exe build/01b.exe

build/01a.exe: 01/solution_A.cpp common/readlines.hpp
	$(CC) $(CXXFLAGS) -ggdb $< -o $@
	build/01a.exe 01/depths.txt

build/01b.exe: 01/solution_B.cpp common/readlines.hpp
	$(CC) $(CXXFLAGS) -ggdb $< -o $@
	build/01b.exe 01/depths.txt
