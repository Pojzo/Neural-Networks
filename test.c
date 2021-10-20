#include <stdio.h>

int main() {
    float num = 2.34242;
    unsigned precision = 3;
    printf("%*.*f\n", 0, precision, num);
    return 0;
}
