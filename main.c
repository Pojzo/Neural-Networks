#include <stdio.h>
#include <stdlib.h>
#include "layer.h"
#include "functions.h"
#include "matrix.h"

int main(int argc, char** argv) {
    const unsigned input_size = 10;
    const double a[2][3] = {{1, 2, 3}, {3, 4, 5}};
    const double b[3][2] = {{1, 2}, {2, 3}, {3, 4}};
   
    struct Matrix* A = createMatrix(2, 3);
    struct Matrix* B = createMatrix(3, 2);


    for (unsigned i = 0; i < 2; i++) {
        for (unsigned j = 0; j < 3; j++) {
            setMatrix(A, i, j, a[i][j]);
        }
    }

    for (unsigned i = 0; i < 3; i++) {
        for (unsigned j = 0; j < 2; j++) {
            setMatrix(B, i, j, b[i][j]);
        }
    }
    
    printf("%0.2lf\n", A->data[0]);
    printMatrix(A);
    printMatrix(B);

    struct Matrix* result = matrixProduct(A, B);
    printf("Printing result of matrix product ");
    printMatrix(result);
    

    return 0;
}
