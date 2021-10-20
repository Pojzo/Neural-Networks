#ifndef LAYER_H
#define LAYER_H

struct DenseLayer {
    double* weights;
    double* biases;
    unsigned size;
};

struct InputLayer {
    double* inputs;
    unsigned size;
};

typedef struct DenseLayer DenseLayer;
typedef struct InputLayer InputLayer;

DenseLayer* createDenseLayer(const unsigned size);
InputLayer* createInputLayer(const double* inputs, const unsigned size);

double* initWeights();
void loadWeights(const double* inputs, double* layer_inputs, const unsigned size);
double* initBiases();

void printWeights(const double* weights, const unsigned size);
void printBiases(const double* biases, const unsigned size);
#endif
