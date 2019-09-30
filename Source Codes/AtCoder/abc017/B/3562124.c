#include <stdio.h>
#include <string.h>

int main() {
    char x[51] = { 0 };
    int p, len, flag = 0;

    scanf("%s", x);

    len = strlen(x);
    p = len - 1;
    while (p >= 0) {
        if (x[p-1] == 'c' && x[p] == 'h') {
            p = p - 2;
        } else if (x[p] == 'o') {
            p--;
        } else if (x[p] == 'k') {
            p--;
        } else if (x[p] == 'u') {
            p--;
        } else {
            flag = 1;
            break;
        }
    }

    if (flag == 1) {
        printf("NO\n");
    } else {
        printf("YES\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", x);
     ^