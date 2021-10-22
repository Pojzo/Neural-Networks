#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "test.h"
#include "../functions.h"
#include "../matrix.h"

int main() {
    srand((unsigned)time(NULL));
    const unsigned num_rows1 = 5, num_rows2 = 5;
    const unsigned num_cols1 = 3, num_cols2 = 3;

    testMatrixProduct(num_rows1, num_rows2, num_cols1, num_cols2);
}

void testMatrixProduct(unsigned num_rows1, unsigned num_rows2, unsigned num_cols1, unsigned num_cols2) {
    Matrix_t* A = createRandomMatrix(num_rows1, num_cols1);
    testPrintMatrix(A);
    Matrix_t* B = createRandomMatrix(num_rows2, num_cols2);
    testPrintMatrix(B);
}

