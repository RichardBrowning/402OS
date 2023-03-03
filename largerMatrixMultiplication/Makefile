# the compiler: gcc for C program, define as g++ for C++
CC = g++
# compiler flags:
CFLAGS  = -pthread -g -Wall -std=c++11

RM = rm -f

all: main
main: main.o matrix.o
	$(CC) $(CFLAGS) main.o matrix.o -o main
main.o: main.cpp matrix.h
	$(CC) $(CFLAGS) -c main.cpp
matrix.o: matrix.cc matrix.h
	$(CC) $(CFLAGS) -c matrix.cc

run: main
	./main
clean:
	$(RM) main *.o *.exe *~