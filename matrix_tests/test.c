#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "test.h"
#include "../src//functions.h"
#include "../src/matrix.h"

int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Argc must be 3, num_tests, current_test");
        return 1;
    }
    srand((unsigned)time(NULL));
    unsigned num_tests = atoi(argv[1]);
    unsigned current_test = atoi(argv[2]);
    int x, y1, y2;
    for (unsigned i = 0; i < num_tests; i++) {
        x = current_test + rand() % current_test;
        y1 = current_test + rand() % current_test;
        y2 = current_test + rand() % current_test;
        //printf("%d %d %d %d\n", x, y1, y2, x);
        testMatrixProduct(y1, x, x, y2);
        current_test += 1;
    }
}

void testMatrixProduct(unsigned num_rows1, unsigned num_cols1, unsigned num_rows2, unsigned num_cols2) {
    Matrix_t* A = createRandomMatrix(num_rows1, num_cols1);
    Matrix_t* B = createRandomMatrix(num_rows2, num_cols2);
    Matrix_t* C = matrixProduct(A, B);
    printf("%u,%u,%u,%u,", num_rows1, num_cols1, num_rows2, num_cols2);
    testPrintMatrix(A);
    printf(",");
    testPrintMatrix(B);
    printf(",");
    testPrintMatrix(C);
    printf(",");
}

