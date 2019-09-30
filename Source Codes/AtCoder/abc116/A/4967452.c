#include <stdio.h>

int main(void) {
    int AB, BC;
    if (scanf("%d %d", &AB, &BC) != EOF) {
        printf("%d", AB*BC/2);
    }
    return 0;
}