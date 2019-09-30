#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    char buffer[20];
    int  a,b;
    if (fgets(buffer, 20, stdin)) {
        a = atoi(strtok(buffer, " "));
        b = atoi(strtok(NULL, " "));
    }
    int b_length = 0;
    for (int i = 1; i <= b-a; i++) {
        b_length += i;
    }
    printf("%d",b_length-b);
    return 0;
}