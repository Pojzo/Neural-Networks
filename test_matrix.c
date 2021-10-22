
    struct Matrix* A = createMatrixFromInput(a, 4, 3);
    struct Matrix* B = createMatrixFromInput(b, 3, 2);

    printMatrix(A);
    printMatrix(B);
    printMatrix(B);

    struct Matrix* result = matrixProduct(A, B);
    
    printf("result of matrix product\n");
    printMatrix(result);
    
    struct Matrix* transposed = matrixTranspose(result);
    printf("transposed matrix\n");
    printMatrix(transposed);

    printf("Freeing matrix from memory\n");
    freeMatrix(transposed);
    printMatrix(transposed);
 
