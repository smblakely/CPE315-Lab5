#include <stdlib.h>
#include "matmul.h"

Matrix Allocate2ndMatrix(int height, int width, int init);

void matmul( float*, const float*, const float*, unsigned int, unsigned int, unsigned int);

////////////////////////////////////////////////////////////////////////////////
//! C = A * B
//! @param C          result matrix
//! @param A          matrix A 
//! @param B          matrix B
//! @param hA         height of matrix A
//! @param wB         width of matrix B
////////////////////////////////////////////////////////////////////////////////

/* You'll need to modify this function such that matrix B is accessed
 * correctly once you change the memory layout to column-major. */
void matmul(float* C, const float* A, const float* B, unsigned int hA, 
    unsigned int wA, unsigned int wB)
{
unsigned int c = 32;
   for (unsigned int i = 0; i < (hA / c); ++i){
    for (unsigned int j = 0; j < (wB / c); ++j){
     for (unsigned int z = 0; z < (wA / c); ++z) {
      for (unsigned int x = 0; x < c; ++x) {
       for (unsigned int y = 0; y < c; ++y) {
        for (unsigned int k = 0; k < c; ++k) {
          double a = A[(x * hA) + k + (z * c) + (i * (c * hA))];
          double b = B[(y * wB) + k + (z * c) + (j * (c * wB))];
          C[(x * hA) + y + (j * c) + (i * c * hA)] += (a * b);
        }
       }
      }
     }
    }
   }

//  for (unsigned int i = 0; i < hA; ++i)
//    for (unsigned int j = 0; j < wB; ++j) {
//      double sum = 0;
//      for (unsigned int k = 0; k < wA; ++k) {
//        double a = A[i * wA + k];
//        double b = B[j * wB + k];//Mine
//        //double b = B[k * wB + j];//Original
//        sum += a * b;
//      }
//      C[i * wB + j] = (float)sum;
//    }
}

// Allocate a matrix of dimensions height*width
Matrix Allocate2ndMatrix(int height, int width)
{
  Matrix M;
  M.width = M.pitch = width;
  M.height = height;
  int size = M.width * M.height;
  M.elements = NULL;

  M.elements = (float*) malloc(size*sizeof(float));

  /* This is a row-major allocation and initialization.
   * You need to modify this function which is only called
   * for Matrix B such that a column-major ordering is
   * performed. */

//My code

   for(unsigned int i = 0; i < M.width; i++){
      for(unsigned int j = 0; j < M.height; j++){
         unsigned int x = i + (j * M.width);
         M.elements[x] = (rand() / (float)RAND_MAX);
      }
   }

//Original Code

//  for(unsigned int i = 0; i < M.height * M.width; i++)
//  {
//    M.elements[i] = (rand() / (float)RAND_MAX);
//  }
  return M;
}	

