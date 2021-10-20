#include <stdlib.h>
#include <stdio.h>
#include "functions.h"
#include "matrix.h"


double randDouble(const double start, const double end) {
    if (start > end) {
        fprintf(stderr, "End must be greater than start");
        return -1.;
    }

    float random = ((float) rand()) / (float) RAND_MAX;

    float range = end - start;
    return (random * range) + start;
}
