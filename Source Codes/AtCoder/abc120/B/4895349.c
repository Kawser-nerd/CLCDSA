// 10min
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char buffer[20];
    int  A, B, K;

    if (fgets(buffer, 20, stdin) != NULL) {
        A = atoi(strtok(buffer, " "));
        B = atoi(strtok(NULL, " "));
        K = atoi(strtok(NULL, " "));
    } else {
        return 1;
    }
    int max_num   = 0;
    if (A <= B) {
        max_num = A;
    } else {
        max_num = B;
    }

    int lcm_num = 0, lcm_value = 0;
    for (int i = max_num; 1 <= i; i--) {
        if (lcm_num != K) {
            if (A % i == 0 && B % i == 0) {
                lcm_num  += 1;
                lcm_value = i;
            }
        } else {
            break;
        }
    }
    printf("%d", lcm_value);
    return 0;
}