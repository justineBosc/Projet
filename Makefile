all: main

main: main.o Individu.o Environnement.o Image.o
	g++ -g main.o Individu.o Environnement.o Image.o -o main -std=c++11 
	
main.o: main.cpp Individu.h
	g++ -g -c main.cpp -o main.o -std=c++11 
	
Individu.o: Individu.cpp Individu.h
	g++ -g -c Individu.cpp -o Individu.o -std=c++11 

Environnement.o: Environnement.cpp Environnement.h
	g++ -g -c Environnement.cpp -o Environnement.o -std=c++11

Image.o: Image.cpp Image.h
	g++ -g -c Image.cpp -o Image.o -std=c++11
