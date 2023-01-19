# the compiler: gcc for C program, define as g++ for C++
CC = g++
# compiler flags:
CFLAGS  = -g -Wall -std=c++11


main: main.o rand-normal.o doubleTypeArray.o 
	$(CC) $(CFLAGS) -o main main.o rand-normal.o doubleTypeArray.o 
main.o: main.cpp rand-normal.h doubleTypeArray.h

rand-normal.o: rand-normal.h rand-normal.cpp

doubleTypeArray.o: doubleTypeArray.h doubleTypeArray.cpp

linkedList.o: doubleTypeArray.h doubleTypeArray.cpp

clean: 
	$(RM) main *.o *~
