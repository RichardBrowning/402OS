#include <iostream>
#include <thread>
#include <algorithm>
#include "matrix.h"

#define MATRIX_SIZE 1024
#define NUM_THREADS 12

/**
 * Multiply a certian rows of A and columns of B
 * @param a matrix A
 * @param b matrix B
 * @param result matrix result
 * @param size size of the matrix
 * @param start starting row of Result
 * @param end ending row of Result
*/
void matrixMultiply(double** a, double** b, double** result, int size, int start, int end){
    //multiply a and b
    //row of result
    for(int i = start; i < end; i++){
        //column of result
        for(int j = 0; j < size; j++){
            result[i][j] = 0;
            //"row first, column later
            for(int k = 0; k < size; k++){
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    //end of multiply a and b
}

int main(void){
    //prevent hiddden convertion
    int size = MATRIX_SIZE;
    thread ths[NUM_THREADS];

    //read matrix a
    double** a = read2d("a.mat", size, size);
    //read matrix b
    double** b = read2d("b.mat", size, size);
    //allocate matrix c
    double** result = allocate2d(MATRIX_SIZE, MATRIX_SIZE);
    
    //multi-threaded matrix multiplication
    for (int i = 0; i < NUM_THREADS; i++){
        //for each thread, set start
        int start = i*MATRIX_SIZE/NUM_THREADS;
        int end = std::min((i+1)*MATRIX_SIZE/NUM_THREADS, MATRIX_SIZE);
        ths[i] = thread(matrixMultiply, a, b, result, MATRIX_SIZE, start, end);
    }
    //engage all threads
    for (int i = 0; i < NUM_THREADS; i++){
        ths[i].join();
    }
    //end of multi-threaded matrix multiplication

    //print matrix result
    print2d("resulting matrix", result, MATRIX_SIZE, MATRIX_SIZE);
    //write matrix result
    //write2d("result.mat", result, MATRIX_SIZE, MATRIX_SIZE);
    //free memory
    free2d(a);
    free2d(b);
    free2d(result);

    return 0;
}

