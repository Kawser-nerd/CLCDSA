#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char buffer[100010];
    int  cube_num = 0, value = 0;
    int  zero_num = 0, one_num = 0;
    if (fgets(buffer,100010,stdin) != NULL) {
        cube_num = strlen(buffer);
        for (int i = 0; i < cube_num-1; i++) {
            value = buffer[i]-'0';
            if (value) {
                one_num += 1;
            } else {
                zero_num += 1;
            }
        }
    } else {
            fprintf(stderr, "[x] fgets() error.\n");
        return 1;
    }
    if (zero_num <= one_num) {
        printf("%d",zero_num*2);
    } else {
        printf("%d",one_num*2);
    }
    return 0;
}