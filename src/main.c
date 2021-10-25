#include <stdio.h>
#include <stdlib.h>
#include "dense_layer.h"
#include "functions.h"
#include "matrix.h"


const unsigned num_inputs = 4;
const unsigned num_neurons = 3;

int main(int argc, char** argv) {
    (void) argc;
    (void) argv;

    Matrix_t* test = createRandomMatrix(4, 5);
    printMatrix(test);

    return 0;
    DenseLayer_t* layer = createDenseLayer(num_inputs, num_neurons);
    initLayer(layer);
    //double* test = malloc(sizeof(double));
     
    double inputs_ar[] = {1., 2., 3., 2.5};
    double weights_ar[] = {0.2, 0.8, -0.5, 1.0, 0.5, -0.91, 0.26, -0.5, -0.26, -0.27, 0.17, 0.87};
    double biases_ar[] = {2., 3., 0.5};

    Matrix_t* inputs = createMatrixFromInput(inputs_ar, 1, 3);
    Matrix_t* weights = createMatrixFromInput(weights_ar, num_neurons, num_inputs);
    Matrix_t* biases = createMatrixFromInput(biases_ar, 1, 3);

    updateMatrixFromInput(layer->weights, weights->data);
    updateMatrixFromInput(layer->biases, biases->data);

    updateWeightsFromInput(layer, weights);
    updateBiasesFromInput(layer, biases);

    printf("This is input\n");
    printMatrix(inputs);

    printf("This are weights\n");
    printWeights(layer);

    printf("This are biases\n");
    printBiases(layer);

    //Matrix_t* result_matrix = matrixProduct(inputs, weights);
    //printMatrix(result_matrix);

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
