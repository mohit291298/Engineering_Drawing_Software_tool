# My First Makefile
 
all: Input_mode.o main_computation.o Canvas_2D.o Canvas_3D.o Output.o main.o 
	g++ -o Binary Input_mode.o main_computation.o Canvas_2D.o Canvas_3D.o Output.o main.o
 
Input_mode.o: Input_mode.cpp
	g++ -c Input_mode.cpp -I ./
 
main_computation.o: main_computation.cpp
	g++ -c main_computation.cpp -I ./
 
Canvas_2D.o: Input_mode.o main_computation.o Canvas_2D.cpp
	g++ -c Canvas_2D.cpp -I ./

Canvas_3D.o: Input_mode.o main_computation.o Canvas_3D.cpp
	g++ -c Canvas_3D.cpp -I ./

Output.o: Input_mode.o main_computation.o Canvas_2D.o Canvas_3D.o Output.cpp
	g++ -c Output.cpp -I ./

main.o: Input_mode.o main_computation.o Canvas_2D.o Canvas_3D.o Output.o main.cpp
	g++ -c main.cpp -I ./
