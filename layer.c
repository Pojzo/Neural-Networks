#include <stdio.h>
#include <stdlib.h>
#include "layer.h"
#include "functions.h"

DenseLayer* createDenseLayer(unsigned int size) {
    DenseLayer* dense_layer = (DenseLayer*) malloc(sizeof(DenseLayer));
    dense_layer->size = size;    

    dense_layer->weights = initWeights(dense_layer->size);
    dense_layer->biases = initBiases(dense_layer->size);

    if (dense_layer->weights == NULL || dense_layer->biases == NULL) {
        return NULL;
    }
    return dense_layer;
}

InputLayer* createInputLayer(const double* inputs, const unsigned size) {
    InputLayer* input_layer = (InputLayer*) malloc(sizeof(InputLayer));
    input_layer->size = size;

    if (inputs == NULL) {
        printf("Inputs are null, filling random values");
        input_layer->inputs = initWeights(size);
    }
    else {
        input_layer = (InputLayer* ) malloc(input_layer->size * sizeof(InputLayer));
        input_layer->inputs = (double*) malloc(input_layer->size * sizeof(double));
        loadWeights(inputs, input_layer->inputs, size);
    }
    return input_layer;
}

double* initWeights(const unsigned size) {
    double* weights = (double*) malloc(size * sizeof(double));
    for (unsigned int i = 0; i < size; i++) {
        weights[i] = randDouble(-1, 1);
    }
    return weights;
}

void loadWeights(const double* inputs, double* weights, const unsigned size) {
    return; 
}

double* initBiases(unsigned int size) {
    double* biases = (double*) malloc(size * sizeof(double));
    for (unsigned int i = 0; i < size; i++) {
        biases[i] = randDouble(-1, 1);
    }
    return biases;
}

void forward(InputLayer* input_layer, DenseLayer* dense_layer) {

}

void printWeights(const double* weights, const unsigned size) {
    if (weights == NULL) {
        fprintf(stderr, "Argument layer is NULL");
        return;
    }
    printf("Printing weights of size %d\n", size);
    for (unsigned int i = 0; i < size; i++) {
        printf("%lf %c", weights[i], i == size - 1 ? '\n' : ' ');
    }
}

void printBiases(const double* biases, const unsigned size) {
    if (biases == NULL) {
        fprintf(stderr, "Argument layer is NULL");
        return;
    }
    printf("Printing biases of size %d\n", size);
    for (unsigned i = 0; i < size; i++) {
        printf("%lf %c", biases[i], i == size - 1 ? '\n' : ' ');
    }
}

