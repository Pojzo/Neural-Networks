#ifndef MATRIX_H
#define MATRIX_H

#include <stdbool.h>
#include "functions.h"

struct Matrix {
    double *data;
    unsigned num_rows;
    unsigned num_cols;
};

typedef struct Matrix Matrix_t;

Matrix_t* createMatrix(unsigned num_rows_, unsigned num_cols_);
Matrix_t* createRandomMatrix(unsigned num_rows_, unsigned num_cols_);
Matrix_t* createMatrixFromInput(const double* input, unsigned num_rows, unsigned num_cols);

void updateMatrixFromInput(Matrix_t* matrix, const double* input);

bool rowInRange(const Matrix_t*, unsigned row);
bool colInRange(const Matrix_t*, unsigned col);

bool setMatrix(Matrix_t*, unsigned row, unsigned col, double value);
double getMatrix(const Matrix_t* matrix, unsigned row, unsigned col);

Matrix_t* matrixProduct(const Matrix_t* matrix, const Matrix_t* B);
Matrix_t* MatrixAddition(const Matrix_t* matrix, const Matrix_t* B);
Matrix_t* matrixTranspose(const Matrix_t* matrix);

void freeMatrix(Matrix_t* matrix);

void testPrintMatrix(const Matrix_t* matrix);
void printMatrix(const Matrix_t* matrix);

#endif
