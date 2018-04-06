all: create_folders
	g++ -O2 -std=c++11  -c "main.cpp" -o obj/main.o
	g++ -O2 -std=c++11  -c "KnapsackSolver.cpp" -o obj/KnapsackSolver.o
	g++  -o bin/CombinatoryLinux obj/main.o obj/KnapsackSolver.o

create_folders:
	mkdir obj
	mkdir bin

clean:
	rm -rf obj/
	rm -rf bin/

