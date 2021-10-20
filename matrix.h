#ifndef PAIR_H
#define PAIR_H
#include <stdbool.h>

struct Matrix {
    double *data;
    unsigned rows;
    unsigned cols;
};

typedef struct Matrix Matrix_t;

Matrix_t* createMatrix(unsigned rows, unsigned cols);
Matrix_t* createMatrixFromInput(const double* input, unsigned rows, unsigned cols);

bool rowInRange(const Matrix_t*, unsigned row);
bool colInRange(const Matrix_t*, unsigned col);

bool setMatrix(Matrix_t*, unsigned row, unsigned col, double value);
double getMatrix(const Matrix_t* A, unsigned row, unsigned col);

Matrix_t* matrixProduct(const Matrix_t* A, const Matrix_t* B);
void printMatrix(const Matrix_t* A);

#endif
