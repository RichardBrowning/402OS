#include <iostream>
#include <vector>
#include <thread>
#include "matrix.h"

void hello(){
    std::cout << "Hello from thread" << std::endl;
}

int main(void){
    int MATRIX_SIZE = 1024;
    std::cout << "Hello World" << std::endl;
    std::vector <std::thread> threads;

    for (int i = 0; i < 10; i++){
        threads.push_back(std::thread(hello));
    }

    //read matrix a
    double** a = read2d("a.mat", MATRIX_SIZE, MATRIX_SIZE);
    //read matrix b
    double** b = read2d("b.mat", MATRIX_SIZE, MATRIX_SIZE);
    //allocate matrix c
    double** result = allocate2d(MATRIX_SIZE, MATRIX_SIZE);
    
    // //multiply a and b
    // for(int i = 0; i < MATRIX_SIZE; i++){
    //     for(int j = 0; j < MATRIX_SIZE; j++){
    //         c[i][j] = 0;
    //         for(int k = 0; k < MATRIX_SIZE; k++){
    //             c[i][j] += a[i][k] * b[k][j];
    //         }
    //     }
    // }
    // //write matrix c
    // write2d("result.mat", result, MATRIX_SIZE, MATRIX_SIZE);
    // //free memory
    // free2d(a);
    // free2d(b);
    // free2d(c);

    return 0;
}