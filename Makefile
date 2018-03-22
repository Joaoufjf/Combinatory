#
all: create_folders
	g++ -Wall -fexceptions -O2 -std=c++11  -c "CombinatoryLinux.cpp" -o obj/CombinatoryLinux.o
	g++  -o bin/CombinatoryLinux obj/CombinatoryLinux.o  -s  -lgomp

create_folders:
	mkdir obj
	mkdir bin

clean:
	rm -rf obj/
	rm -rf bin/

