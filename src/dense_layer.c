#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dense_layer.h"

#define FLOAT_PRECISION 2

const double RANDOM_RANGE_START = -1;
const double RANDOM_RANGE_END = 1;

DenseLayer_t* createDenseLayer(unsigned num_inputs_, unsigned num_neurons_) {
    DenseLayer_t* dense_layer = (DenseLayer_t*) malloc(sizeof(DenseLayer_t));

    dense_layer->num_neurons = num_neurons_; 
    dense_layer->num_inputs = num_inputs_;

    dense_layer->weights = createMatrix(dense_layer->num_neurons, dense_layer->num_inputs);
    dense_layer->biases = createMatrix(1, dense_layer->num_neurons);

    return dense_layer;
}

void initLayer(DenseLayer_t* dense_layer) {
    initWeights(dense_layer);
    initBiases(dense_layer);
}

void initWeights(DenseLayer_t* dense_layer) {
    for (unsigned i = 0; i < dense_layer->weights->num_rows; i++) {
        for (unsigned j = 0; j < dense_layer->weights->num_cols; j++) {
            setMatrix(dense_layer->weights, i, j, randDouble(RANDOM_RANGE_START, RANDOM_RANGE_END));
        }
    }
}

void initBiases(DenseLayer_t* dense_layer) {
    for (unsigned i = 0; i < dense_layer->biases->num_rows; i++) {
        for (unsigned j = 0; j < dense_layer->biases->num_cols; j++) {
            setMatrix(dense_layer->biases, i, j, randDouble(RANDOM_RANGE_START, RANDOM_RANGE_END));
        }
    }
}

void updateWeightsFromInput(DenseLayer_t* dense_layer, const Matrix_t* weights) {
    updateMatrixFromInput(dense_layer->weights, weights->data);
}

void updateBiasesFromInput(DenseLayer_t* dense_layer, const Matrix_t* biases) {
    updateMatrixFromInput(dense_layer->biases, biases->data);
}


void printWeights(DenseLayer_t* dense_layer) {
    printMatrix(dense_layer->weights);
}

void printBiases(DenseLayer_t* dense_layer) {
    printMatrix(dense_layer->biases);
}
