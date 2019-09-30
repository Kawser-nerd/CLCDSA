#include <stdio.h>

int divneg2(int n) {
    int q = n / (-2);
    if (n < (-2) * q)
        q++;
    return q;
}

int main(void) {
    int n;
    char bit[100];
    int max_bit;

    scanf("%d", &n);

    for (int i = 0; ; i++) {
        int q = divneg2(n);
        int r = n - (-2) * q;

        if (r == 0) {
            bit[i] = '0';
        }
        else {
            bit[i] = '1';
        }

        if (q == 0) {
            max_bit = i;
            break;
        }

        n = q;
    }

    for (int i = max_bit; i >= 0; i--) {
        printf("%c", bit[i]);
    }
    printf("\n");

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^