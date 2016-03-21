all: main

main: main.o Individu.o Image.o Simulation.o Cell.o Env.o
	g++ -g main.o Individu.o Image.o Simulation.o Cell.o Env.o -o main -std=c++11 
	
main.o: main.cpp Individu.h
	g++ -g -c main.cpp -o main.o -std=c++11 
	
Individu.o: Individu.cpp Individu.h
	g++ -g -c Individu.cpp -o Individu.o -std=c++11 
	
Cell.o: Cell.cpp Cell.h
	g++ -g -c Cell.cpp -o Cell.o -std=c++11

Image.o: Image.cpp Image.h
	g++ -g -c Image.cpp -o Image.o -std=c++11
	
Simulation.o : Simulation.cpp Simulation.h
	g++ -g -c Simulation.cpp -o Simulation.o -std=c++11

Env.o: Env.cpp Env.h
	g++ -g -c Env.cpp -o Env.o -std=c++11
