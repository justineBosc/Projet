all: main

main: main.o Individu.o Image.o Simulation.o Cell.o Env.o
	g++ main.o Individu.o Image.o Simulation.o Cell.o Env.o -o main -std=c++11 -O4
	
main.o: main.cpp Individu.h
	g++ -c main.cpp -o main.o -std=c++11 -O4
	
Individu.o: Individu.cpp Individu.h
	g++ -c Individu.cpp -o Individu.o -std=c++11 -O4
	
Cell.o: Cell.cpp Cell.h
	g++ -c Cell.cpp -o Cell.o -std=c++11 -O4

Image.o: Image.cpp Image.h
	g++ -c Image.cpp -o Image.o -std=c++11 -O4
	
Simulation.o : Simulation.cpp Simulation.h
	g++ -c Simulation.cpp -o Simulation.o -std=c++11 -O4

Env.o: Env.cpp Env.h
	g++ -c Env.cpp -o Env.o -std=c++11 -O4
