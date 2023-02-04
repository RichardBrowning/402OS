# the compiler: gcc for C program, define as g++ for C++
CC = g++
# compiler flags:
CFLAGS  = -g -Wall -std=c++11
RM = rm -f

main: main.o rand-normal.o doubleTypeArray.o linkedListNode.o
	$(CC) $(CFLAGS) main.o rand-normal.o doubleTypeArray.o -o main 
main.o: main.cpp doubleTypeArray.h linkedListNode.h
	$(CC) $(CFLAGS) -c main.cpp
doubleTypeArray.o: doubleTypeArray.cpp doubleTypeArray.h
	$(CC) $(CFLAGS) -c doubleTypeArray.cpp
linkedListNode.o: linkedListNode.cpp linkedListNode.h
	$(CC) $(CFLAGS) -c linkedListNode.cpp
rand-normal.o: rand-normal.cpp
	$(CC) $(CFLAGS) -c rand-normal.cpp
run: main
	./main
clean: 
	$(RM) main *.o *~
valgrind: horseRace
	valgrind --leak-check:full ./main