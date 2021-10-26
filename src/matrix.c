#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

#define FLOAT_PRECISION_TEST 20
#define FLOAT_PRECISION 2

Matrix_t* createMatrix(unsigned num_rows_, unsigned num_cols_) {
    if (num_rows_ == 0 || num_cols_ == 0 ) {
        fprintf(stderr, "Number of rows and columns cant be zero\n");
        return NULL;
    }
    Matrix_t* matrix = (Matrix_t*) malloc(sizeof(Matrix_t));
    matrix->num_rows = num_rows_;
    matrix->num_cols = num_cols_;
    matrix->data = (double*) malloc(matrix->num_rows * matrix->num_cols * sizeof(double));

    return matrix;
}

Matrix_t* createMatrixFromInput(const double* input, unsigned num_rows, unsigned num_cols) {
    /*
       unsigned input_len = vectorLen(input);
       if (input_len != num_rows * num_cols) {
       fprintf(stderr, "length of input doesnt match num_rows * num_cols\n");
       return NULL;
       }
       */

    Matrix_t* matrix = createMatrix(num_rows, num_cols);

    for (unsigned i = 0; i < matrix->num_rows; i++) {
        for (unsigned j = 0; j < matrix->num_cols; j++) {
            setMatrix(matrix, i, j, input[i * num_cols + j]); // copy from input to matrix
        }
    }
    return matrix;
}

Matrix_t* createRandomMatrix(unsigned num_rows_, unsigned num_cols_) {
    Matrix_t* matrix = createMatrix(num_rows_, num_cols_); 
    for (unsigned i = 0; i < num_rows_; i++) {
        for (unsigned j = 0; j < num_cols_; j++) {
            setMatrix(matrix, i, j, randDouble(-1, 1));
        }
    }
    return matrix;
}

void updateMatrixFromInput(Matrix_t* matrix, const double* input) {
    for (unsigned i = 0; i < matrix->num_rows; i++) {
        for (unsigned j = 0; j < matrix->num_cols; j++) {
            setMatrix(matrix, i, j, input[i * matrix->num_cols + j]); // copy from input to matrix
        }
    }
}

bool rowInRange(const Matrix_t* A, unsigned row) {
    if (row > A->num_rows)  {
        fprintf(stderr, "Specified row exceeds matrix dimensions\n");
        return false;
    }

    return true;
}

bool colInRange(const Matrix_t* A, unsigned col) {
    if (col > A->num_rows)  {
        fprintf(stderr, "Specified row exceeds matrix dimensions\n");
        return false;
    }
    return true;
}

bool setMatrix(Matrix_t* A, unsigned row, unsigned col, double value) {
    if (!(rowInRange(A, row)) && colInRange(A, col)) {
        return false;
    }
    unsigned index = row * A->num_cols + col;

    A->data[index] = value;

    return true;
}

double getMatrix(const Matrix_t* A, unsigned row, unsigned col) {
    if (!(rowInRange(A, row)) && colInRange(A, col)) {
        return false;
    }

    return A->data[row * A->num_cols + col];
}

Matrix_t* matrixProduct(const Matrix_t* A, const Matrix_t* B) {

    if (A->num_cols != B->num_rows) {
        fprintf(stderr, "Number of columns of first matrix must equal number of rows of second matrix\n");
        return NULL;
    }

    unsigned result_x = A->num_rows;
    unsigned result_y = B->num_cols;

    double* data = (double *) malloc(result_x * result_y * sizeof(double));
    (void) data; // FIXME

    Matrix_t* result_matrix = createMatrix(result_x, result_y);

    double sum_cell;

    for (unsigned i = 0; i < result_x; i++) {
        for (unsigned j = 0; j < result_y; j++) {
            sum_cell = 0;
            for (unsigned x = 0; x < A->num_cols; x++) {
                sum_cell += getMatrix(A, i, x) * getMatrix(B, x, j);
            }
            setMatrix(result_matrix, i, j, sum_cell);
        }
    }

    return result_matrix;
}

Matrix_t* matrixAddition(const Matrix_t* A, const Matrix_t* B) {
    if (!((A->num_cols == B->num_cols) && (A->num_rows && B->num_rows))) {
        fprintf(stderr, "Dimension of both matrices must match\n");
        return NULL;
    }

    Matrix_t* matrix = createMatrix(A->num_rows, A->num_cols);

    double first_value, second_value;

    for (unsigned i = 0; i < A->num_rows; i++) {
        for (unsigned j = 0; j < A->num_cols; j++) {
            first_value = getMatrix(A, i, j);
            second_value = getMatrix(B, i, j);
            setMatrix(matrix, i, j, first_value + second_value);
        }
    }
    return matrix;
}


Matrix_t* matrixTranspose(const Matrix_t* A) {
    if (A == NULL) {
        fprintf(stderr, "Argument Matrix_t* is NULL\n");
        return NULL;
    }
    Matrix_t* t_matrix = createMatrix(A->num_cols, A->num_rows);
    for (unsigned i = 0; i < A->num_cols; i++) {
        for (unsigned j = 0; j < A->num_rows; j++) {
            setMatrix(t_matrix, i, j, getMatrix(A, j, i));
        }
    }
    return t_matrix;
}

void freeMatrix(Matrix_t* A) {
    free(A->data);
    free(A);
}

void testPrintMatrix(const Matrix_t* A) {
    if (!A) {
        fprintf(stderr, "Cant print matrix, == NULL\n");
    }

    for (unsigned i = 0; i < A->num_rows; i++)  {
        for (unsigned j = 0; j < A->num_cols; j++) {
            if (i == 0 && j == 0) {
                printf("%*.*lf", 0, FLOAT_PRECISION_TEST, getMatrix(A, i, j));
            }
            else {
                printf(",%*.*lf", 0, FLOAT_PRECISION_TEST, getMatrix(A, i, j));
            }
        }
    }
}

void printMatrix(const Matrix_t* A) {
    if (!A) {
        fprintf(stderr, "Cant print matrix, == NULL\n");
    }

    printf("printing matrix of size (%d, %d)\n", A->num_rows, A->num_cols);
    for (unsigned i = 0; i < A->num_rows; i++)  {
        for (unsigned j = 0; j < A->num_cols; j++) {
            printf("%*.*lf%s", 0, FLOAT_PRECISION, getMatrix(A, i, j), j == A->num_cols - 1 ? "\n" : "  ");
        }
    }
    printf("\n");
}
