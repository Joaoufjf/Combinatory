#
all: create_folders
	g++ -Wall -fexceptions -O2 -std=c++11  -c "main.cpp" -o obj/main.o
	g++  -o bin/Combinatory obj/main.o  -s  -lgomp

create_folders:
	mkdir obj
	mkdir bin

clean:
	rm -rf obj/
	rm -rf bin/

