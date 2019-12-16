

output: Main.o  Zoo.o Animal.o Tigers.o Penguins.o Turtles.o InputValidation.o NewSpecies.o
	g++ -std=c++11 Main.o Zoo.o Animal.o Tigers.o Penguins.o Turtles.o InputValidation.o  NewSpecies.o -o output

Main.o: Main.cpp
	g++ -std=c++11 -c Main.cpp

Zoo.o: Zoo.cpp
	g++ -std=c++11 -c Zoo.cpp

Animal.o: Animal.cpp
	g++ -std=c++11 -c Animal.cpp

Tigers.o: Tigers.cpp
	g++ -std=c++11 -c Tigers.cpp

Penguins.o: Penguins.cpp
	g++ -std=c++11 -c Penguins.cpp

Turtles.o: Turtles.cpp
	g++ -std=c++11 -c Turtles.cpp

InputValidation.o: InputValidation.cpp
	g++ -std=c++11 -c InputValidation.cpp

NewSpecies.o: NewSpecies.cpp
	g++ -std=c++11 -c NewSpecies.cpp

clean:
	rm *.o output
