#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    char buffer[10];
    int H, W, h, w;
    if (fgets(buffer, 10, stdin) != NULL) {
        H = atoi(strtok(buffer, " "));
        W = atoi(strtok(NULL, " "));
    } else {
        return 1;
    }
    if (fgets(buffer, 10, stdin) != NULL) {
        h = atoi(strtok(buffer, " "));
        w = atoi(strtok(NULL, " "));
    } else {
        return 1;
    }
    printf("%d\n",(H*W)-(h*W+(H-h)*w));
    return 0;
}