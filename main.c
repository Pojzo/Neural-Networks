#include <stdio.h>
#include <stdlib.h>
#include "layer.h"
#include "functions.h"
#include "matrix.h"

int main(int argc, char** argv) {
    const unsigned input_size = 10;
    //const double a[4][3] = {{1, 2, 3}, {3, 4, 5}, {5, 6, 7}, {8, 9, 10}};
    //const double b[3][2] = {{1, 2}, {2, 3}, {3, 4}};

    const double a[] = {1., 2., 3., 3., 4., 5., 6., 7., 8., 9., 10.};
    const double b[] = {1., 2., 2., 3., 3., 5.,};

    struct Matrix* A = createMatrixFromInput(a, 4, 3);
    struct Matrix* B = createMatrixFromInput(b, 3, 2);

    printMatrix(A);
    printMatrix(B);

    struct Matrix* result = matrixProduct(A, B);

    printMatrix(result);

    return 0;
   
    //struct Matrix* A = createMatrix(4, 3);
    //struct Matrix* B = createMatrix(3, 2);
    /*
    for (unsigned i = 0; i < 4; i++) {
        for (unsigned j = 0; j < 3; j++) {
            setMatrix(A, i, j, a[i][j]);
        }
    }

    for (unsigned i = 0; i < 3; i++) {
        for (unsigned j = 0; j < 2; j++) {
            setMatrix(B, i, j, b[i][j]);
        }
    }

    printMatrix(A);
    printMatrix(B);

    struct Matrix* result = matrixProduct(A, B);
    printf("Printing result of matrix product ");
    printMatrix(result);
    */ 

    return 0;
}
