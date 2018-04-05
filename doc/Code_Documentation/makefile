# My First Makefile
 
all: Input_mode.o main_computation.o Canvas.o Output.o main.o 
	g++ -o Binary Input_mode.o main_computation.o Canvas.o Output.o main.o
 
Input_mode.o: Input_mode.cpp
	g++ -c Input_mode.cpp -I ./
 
main_computation.o: main_computation.cpp
	g++ -c main_computation.cpp -I ./
 
Canvas.o: main_computation.o Canvas.cpp
	g++ -c Canvas.cpp -I ./

Output.o: Output.cpp
	g++ -c Output.cpp -I ./

main.o: Input_mode.o Canvas.o Output.o main.cpp
	g++ -c main.cpp -I ./
