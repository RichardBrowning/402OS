#include <iostream>
#include <fstream>
#include "matrix.h"
using namespace std;

/**
 * Allocate a 2D array of doubles
 * @param rows number of rows
 * @param cols number of columns
 * @return pointer to the array
 * @note the array is allocated as a single block of memory
*/
double **allocate2d(int rows, int cols)
{
  // allocate the array of pointers
  double **data; 
  // if either dimension is zero, return a null pointer
  if (rows == 0 || cols == 0)
    data = nullptr; 
  else {
    // data is array: "rows" of pointers
    data = new double *[rows];
    // temp is a pointer to a block of memory, with size of row*col
    double *temp = new double[rows * cols];
    for (size_t i = 0; i < rows; i++)
      // ith cell of data is a pointer 
      data[i] = temp + i * cols;
  }
  //return the data full of pointers
  return data; 
}

void free2d(double **x)
{
  // if x is not a null pointer
  if (x != nullptr) {
    // delete the first element of the array
    delete [] x[0];
    // delete the array of pointers
    delete [] x;
  }
}
// read a 2D array from a binary file
double **read2d(string filename, int &nr, int &nc)
{
  // input file stream
  ifstream fin;
  // open the file
  fin.open(filename, ios::binary);
  // read the number of rows and columns
  fin.read((char *) &nr, sizeof(int));
  fin.read((char *) &nc, sizeof(int));
  // allocate the array
  double **x = allocate2d(nr, nc);
  // read the data
  fin.read((char *) x[0], sizeof(double)*nr*nc); 
  // close the file
  fin.close();
  // return the array
  return x; 
}
// write a 2D array to a binary file
void write2d(string filename, double **x, int nr, int nc)
{
  // output file stream
  ofstream fout;
  // open the file
  fout.open(filename, ios::binary);
  // write the number of rows and columns
  fout.write((char *) &nr, sizeof(int));
  fout.write((char *) &nc, sizeof(int));
  // write the data
  fout.write((char *) x[0], sizeof(double)*nr*nc);
  fout.close(); 
}

void print2d(string msg, double **x, int nr, int nc)
{
  if (msg.length() > 0)
    cout << msg;
  cout << "(" << nr << "*" << nc << ")" << endl;

  for (int i=0; i<nr; i++) {
    if (nr > 8 && i == 6) {
      cout << "...\n";
      i = nr-2;
      continue; 
    }
      
    if (nc < 9) {
      for (int j=0; j<nc; j++)
	cout << x[i][j] << ((j+1==nc || (j+1)%8 == 0)?"\n":" ");
    }
    else {
      for (int j=0; j<6; j++)
	cout << x[i][j] << " ";
      cout << "... " << x[i][nc-1] << "\n"; 
    }
  }
}
