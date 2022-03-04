PROJECT2: driver.o Command.o
	g++ -o PROJECT2 driver.o Command.o

driver.o: driver.cpp Command.h
	g++ -c driver.cpp

Command.o: Command.cpp Command.h
	g++ -c Command.cpp 