comp_all: main.cpp functions.cpp
	g++ main.cpp functions.cpp functions.h -o comp
run: comp_all
	./comp