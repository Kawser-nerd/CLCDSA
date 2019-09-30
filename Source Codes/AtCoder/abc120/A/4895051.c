#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char buffer[15];
    int  A,B,C;
    if (fgets(buffer,15,stdin) != NULL) {
        A = atoi(strtok(buffer, " "));
        B = atoi(strtok(NULL, " "));
        C = atoi(strtok(NULL, " "));
    } else {
        return 1;
    }
    if (A*C <= B) {
        printf("%d", C);
    } else {
        printf("%d", B/A);
    }
    return 0;
}