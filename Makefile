all: create_folders
	g++ -Wall -fexceptions -O2 -std=c++11  -c "main.cpp" -o obj/main.o
	g++ -Wall -fexceptions -O2 -std=c++11  -c "KnapsackSolver.cpp" -o obj/KnapsackSolver.o
	g++  -o bin/CombinatoryLinux obj/main.o obj/KnapsackSolver.o -s  -lgomp

create_folders:
	mkdir obj
	mkdir bin

clean:
	rm -rf obj/
	rm -rf bin/

