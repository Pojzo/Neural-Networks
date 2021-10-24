#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "test.h"
#include "../src//functions.h"
#include "../src/matrix.h"

int main(int argc, char** argv) {
    if (argc == 1) {
        fprintf(stderr, "Missing argument 'number of tests\n");
        return 1;
    }
    srand((unsigned)time(NULL));
    unsigned num_rows1 = 5, num_rows2 = 3;
    unsigned num_cols1 = 3, num_cols2 = 5;
    unsigned num_tests = atoi(argv[1]);

    for (unsigned x = 1; x < num_tests; x++) {
        testMatrixProduct(x, 20 - x + 1, 20 - x + 1, 20);
    }
}

void testMatrixProduct(unsigned num_rows1, unsigned num_rows2, unsigned num_cols1, unsigned num_cols2) {
    Matrix_t* A = createRandomMatrix(num_rows1, num_cols1);
    Matrix_t* B = createRandomMatrix(num_rows2, num_cols2);
    Matrix_t* C = matrixProduct(A, B);
    printf("%u,%u,%u,%u,", num_rows1, num_rows2, num_cols1, num_cols2);
    testPrintMatrix(A);
    printf(",");
    testPrintMatrix(B);
    printf(",");
    testPrintMatrix(C);
    printf(",");
}

