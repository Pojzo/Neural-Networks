#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"
#include "functions.h"

#define FLOAT_PRECISION 2

Matrix_t* createMatrix(unsigned rows_, unsigned cols_) {
    if (rows_ == 0 || cols_ == 0 ) {
        fprintf(stderr, "Number of rows and columns cant be zero");
        return NULL;
    }
    Matrix_t* matrix = (Matrix_t*) malloc(sizeof(Matrix_t));
    matrix->rows = rows_;
    matrix->cols = cols_;
    matrix->data = (double*) malloc(matrix->rows * matrix->cols * sizeof(double));

    return matrix;
}

Matrix_t* createMatrixFromInput(const double* input, unsigned rows, unsigned cols) {
    /*
    unsigned input_len = vectorLen(input);
    if (input_len != rows * cols) {
        fprintf(stderr, "length of input doesnt match rows * cols\n");
        return NULL;
    }
    */
    
    Matrix_t* matrix = createMatrix(rows, cols);
    printf("rows: %u\ncols: %u\n", matrix->rows, matrix->cols);

    for (unsigned i = 0; i < matrix->rows; i++) {
        for (unsigned j = 0; j < matrix->cols; j++) {
            setMatrix(matrix, i, j, input[i * cols + j]); // copy from input to matrix
        }
    }
    return matrix;
}

bool rowInRange(const Matrix_t* A, unsigned row) {
    if (row > A->rows)  {
        fprintf(stderr, "Specified row exceeds matrix dimensions\n");
        return false;
    }

    if (row < 0) {
        fprintf(stderr, "Argument row must be greater or equal to zero\n");
        return false;
    }
    return true;
}

bool colInRange(const Matrix_t* A, unsigned col) {
    if (col > A->rows)  {
        fprintf(stderr, "Specified row exceeds matrix dimensions\n");
        return false;
    }

    if (col < 0) {
        fprintf(stderr, "Argument col must be greater or equal to zero\n");
        return false;
    }
    return true;
}

bool setMatrix(Matrix_t* A, unsigned row, unsigned col, double value) {
    if (!(rowInRange(A, row)) && colInRange(A, col)) {
        return false;
    }
    unsigned index = row * A->cols + col;

    A->data[index] = value;

    return true;
}

double getMatrix(const Matrix_t* A, unsigned row, unsigned col) {
    if (!(rowInRange(A, row)) && colInRange(A, col)) {
        return false;
    }

    return A->data[row * A->cols + col];
}

Matrix_t* matrixProduct(const Matrix_t* A, const Matrix_t* B) {

    if (A->cols != B->rows) {
        fprintf(stderr, "dim1 and dim2 of matrices must match\n");
        return NULL;
    }

    unsigned result_x = A->rows;
    unsigned result_y = B->cols;

    double* data = (double *) malloc(result_x * result_y * sizeof(double));

    Matrix_t* result_matrix = createMatrix(result_x, result_y);

    double sum_cell;

    for (unsigned i = 0; i < result_x; i++) {
        for (unsigned j = 0; j < result_y; j++) {
            sum_cell = 0;
            for (unsigned x = 0; x < A->cols; x++) {
                sum_cell += getMatrix(A, i, x) * getMatrix(B, x, j);
            }
            setMatrix(result_matrix, i, j, sum_cell);
        }
    }

    return result_matrix;
}

void printMatrix(const Matrix_t* A) {
    printf("Printing matrix of size (%d, %d) with precison to %d decimal points\n\n", A->rows, A->cols, FLOAT_PRECISION);
    for (unsigned i = 0; i < A->rows; i++)  {
        for (unsigned j = 0; j < A->cols; j++) {
            printf("%*.*lf%c", 0, FLOAT_PRECISION, getMatrix(A, i, j), j == A->cols - 1 ? '\n' : ' ');
        }
    }
    printf("\n");
}
