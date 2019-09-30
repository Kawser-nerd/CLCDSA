#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char* buffer = malloc(sizeof(char)*10);
    if (fgets(buffer, 10, stdin) == NULL) {
        return 1;
    }
    int new_len = atoi(buffer)*2;
    char* buffer2 = malloc(sizeof(char)*new_len);
    if(fgets(buffer2, new_len, stdin) != NULL) {
        if (strstr(buffer2, "Y") != NULL) {
            printf("Four");
        } else {
            printf("Three");
        }
    }
    return 0;
}