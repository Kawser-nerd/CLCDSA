#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char buffer[10];
    int N = atoi(fgets(buffer, 10, stdin));
    if (N < 1000) {
        printf("ABC");
    } else {
        printf("ABD");
    }
    return 0;
}