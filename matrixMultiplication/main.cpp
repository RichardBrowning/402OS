#include <iostream>
#include <thread>
#include <algorithm>
#include <cmath>
#include <chrono>
#include <mutex>

#include "matrix.h"

#define MATRIX_SIZE 1024
#define NUM_THREADS 16
std::mutex mtx;

//get microsecond time
class Timer{
    public:
        Timer(){
            start = std::chrono::high_resolution_clock::now();
        }
        ~Timer(){
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            std::cout << "Time taken by program: " << duration.count() << " microseconds" << std::endl;
        }
    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> start;
};

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

/** 
 * sum of a matrix
 * @param result matrix result
 * @param sum reference to sum
 * @param size size of the matrix
 * @param start starting row of Result
 * @param end ending row of Result
*/
void matrixSum(double** result, double& sum, int size, int start, int end){
    mtx.lock();
    //row of result
    for (int i = start; i < end; i++){
        //column of result
        for (int j = 0; j < size; j++){
            sum += result[i][j];
        }
    }
    mtx.unlock();
}
void matrixSdNumerator(double** result, double& rSdNumerator, int size, double mean, int start, int end){
    mtx.lock();
    //row of result
    for (int i = start; i < end; i++){
        //column of result
        for (int j = 0; j < size; j++){
            rSdNumerator += (result[i][j] - mean)*(result[i][j] - mean);
        }
    }
    mtx.unlock();
}

int main(void){
    //prevent hiddden convertion
    int size = MATRIX_SIZE;
    std::thread ths[NUM_THREADS];
    std::thread ths2[NUM_THREADS];
    std::thread ths3[NUM_THREADS];

    //read matrix a
    double** a = read2d("a.mat", size, size);
    //read matrix b
    double** b = read2d("b.mat", size, size);
    //allocate matrix c
    double** result = allocate2d(MATRIX_SIZE, MATRIX_SIZE);
    
    // for(int i = 0; i < MATRIX_SIZE; i++){
    //     //column of result
    //     for(int j = 0; j < size; j++){
    //         result[i][j] = 0;
    //         //"row first, column later
    //         for(int k = 0; k < size; k++){
    //             result[i][j] += a[i][k] * b[k][j];
    //         }
    //     }
    // }
    Timer* timer = new Timer();
    //multi-threaded matrix multiplication
    for (int i = 0; i < NUM_THREADS; i++){
        //for each thread, set start
        int start = i*MATRIX_SIZE/NUM_THREADS;
        int end = std::min((i+1)*MATRIX_SIZE/NUM_THREADS, MATRIX_SIZE);
        ths[i] = std::thread(matrixMultiply, a, b, result, MATRIX_SIZE, start, end);
    }
    //engage all threads
    for (int i = 0; i < NUM_THREADS; i++){
        if(ths[i].joinable())
            ths[i].join();
        else
            std::cout << "ths[" << i << "] is not joinable" << std::endl;
    }

    //end of multi-threaded matrix multiplication
    //element number
    int elementNum = MATRIX_SIZE*MATRIX_SIZE;
    //sum of the matrix, average, sd
    double sum = 0;
    double mean = 0;
    double sdNumerator = 0;
    double& rSum = sum;
    //sd's numerator
    double& rSdNumerator = sdNumerator;

    // for (int i = 0; i < MATRIX_SIZE; i++){
    //     for (int j = 0; j < MATRIX_SIZE; j++){
    //         sum = result[i][j] + sum;
    //     }
    // }
    // for (int i = 0; i < MATRIX_SIZE; i++){
    //     for(int j = 0; j < MATRIX_SIZE; j++){
    //         sdNumerator = (result[i][j] - mean)*(result[i][j] - mean) + sdNumerator;
    //     }
    // }
    
    for (int i = 0; i < NUM_THREADS; i++){
        //for each thread, set start
        int start = i*MATRIX_SIZE/NUM_THREADS;
        int end = std::min((i+1)*MATRIX_SIZE/NUM_THREADS, MATRIX_SIZE);
        ths2[i] = std::thread(matrixSum, result, std::ref(rSum), MATRIX_SIZE, start, end);
    }
    //engage all threads
    for (int i = 0; i < NUM_THREADS; i++){
        if(ths2[i].joinable())
            ths2[i].join();
        else
            std::cout << "ths2[" << i << "] is not joinable" << std::endl;
    }
    
    for (int i = 0; i < NUM_THREADS; i++){
        //for each thread, set start
        int start = i*MATRIX_SIZE/NUM_THREADS;
        int end = std::min((i+1)*MATRIX_SIZE/NUM_THREADS, MATRIX_SIZE);
        ths3[i] = thread(matrixSdNumerator, result, std::ref(rSdNumerator), MATRIX_SIZE, mean, start, end);
    }
    //engage all threads
    for (int i = 0; i < NUM_THREADS; i++){
        if (ths3[i].joinable())
            ths3[i].join();
        else
            std::cout << "ths3[" << i << "] is not joinable" << std::endl;
    }

    //print matrix result
    print2d("resulting matrix", result, MATRIX_SIZE, MATRIX_SIZE);
    //sum and mean
    std::cout << "sum: " << sum << std::endl;
    mean = sum/elementNum;
    std::cout << "mean: " << mean << std::endl;
    
    //sd
    std::cout << "sd: " << std::sqrt(sdNumerator/elementNum) << std::endl;
    delete timer;
    //write matrix result
    write2d("result.mat", result, MATRIX_SIZE, MATRIX_SIZE);
    //free memory
    free2d(a);
    free2d(b);
    free2d(result);

    return 0;
}

