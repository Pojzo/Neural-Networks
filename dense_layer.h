#ifndef LAYER_H
#define LAYER_H

#include <stdbool.h>
#include "matrix.h"
#include "functions.h"

struct DenseLayer {
    unsigned num_inputs;
    unsigned num_neurons;
    struct Matrix* weights;
    struct Matrix* biases;
};

typedef struct DenseLayer DenseLayer_t;

DenseLayer_t* createDenseLayer(unsigned num_rows, unsigned num_cols);

void initLayer(DenseLayer_t* dense_layer);
void initWeights(DenseLayer_t* dense_layer);
void initBiases(DenseLayer_t* dense_layer);

void updateWeightsFromInput(DenseLayer_t* dense_layer, const Matrix_t* weights);
void updateBiasesFromInput(DenseLayer_t* dense_layer, const Matrix_t* biases);

void printWeights(DenseLayer_t* dense_layer);
void printBiases(DenseLayer_t* dense_layer);

#endif
