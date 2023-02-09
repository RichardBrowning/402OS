# the compiler: gcc for C program, define as g++ for C++
CC = g++
# compiler flags:
CFLAGS  = -g -Wall -std=c++11
ifdef OS
   RM = del /Q
   FixPath = $(subst /,\,$1)
else
   ifeq ($(shell uname), Linux)
      RM = rm -f
      FixPath = $1
   endif
endif

main: main.o rand-normal.o DoubleTypeArray.o LinkedListNode.o 
	$(CC) $(CFLAGS) main.o rand-normal.o DoubleTypeArray.o LinkedListNode.o -o main
main.o: main.cpp DoubleTypeArray.h LinkedListNode.h TimeInterval.h
	$(CC) $(CFLAGS) -c main.cpp
DoubleTypeArray.o: DoubleTypeArray.cpp DoubleTypeArray.h
	$(CC) $(CFLAGS) -c DoubleTypeArray.cpp
LinkedListNode.o: LinkedListNode.cpp LinkedListNode.h
	$(CC) $(CFLAGS) -c LinkedListNode.cpp
rand-normal.o: rand-normal.cpp
	$(CC) $(CFLAGS) -c rand-normal.cpp
# timeInterval.o: TimeInterval.h
# $(CC) $(CFLAGS) -c TimeInterval.h

run: main
	./main
clean: 
	$(RM) main *.o *.exe *~
valgrind: main
	valgrind --leak-check:full ./main