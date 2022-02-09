all: q1

q1: StkTest.o Stack.o
	g++ -Wall -o q1 StkTest.o Stack.o 

StkTest.o: StkTest.cpp Stack.h 
	g++ -Wall -c StkTest.cpp

Stack.o: Stack.h Stack.cpp
	g++ -Wall -c Stack.cpp

clean:
	rm -f q1 *.o