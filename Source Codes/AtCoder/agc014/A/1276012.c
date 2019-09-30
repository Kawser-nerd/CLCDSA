#include <stdio.h>
int solve(int a, int b, int c) {
    int ta, tb, tc;
    int i = 0;
    while(a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
        if(i >= 1000000) return -1;
        ta = a, tb = b, tc = c;
        a = tb / 2 + tc / 2;
        b = ta / 2 + tc / 2;
        c = ta / 2 + tb / 2;
        i++;
    }
    return i;
}
int main(void) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("%d\n", solve(a, b, c));
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d", &a, &b, &c);
     ^