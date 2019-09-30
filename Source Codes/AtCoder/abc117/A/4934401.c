#include <stdio.h>

int main(void) {
    float T, X;
    if (scanf("%3f %3f", &T, &X) != EOF) {
        printf("%f", T / X);
    }
    return 0;
}