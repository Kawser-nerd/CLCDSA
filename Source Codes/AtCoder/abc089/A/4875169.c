#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char buffer[10];
    int N = atoi(fgets(buffer, 10, stdin));
    int count = 0;
    while (N >= 3) {
        N -= 3;
        count++;
    }
    printf("%d", count);
    return 0;
}