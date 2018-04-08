#!/bin/bash
make clean
make

for file in input/*;
do
	echo Solving $file
	./bin/CombinatoryLinux $file
done
