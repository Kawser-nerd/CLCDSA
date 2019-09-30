#include <stdio.h>

int gcd2(int x, int y) {
    int tmp;
    if( x < y) { tmp = x; x = y; y = tmp; }
    if( y < 1) { return -1; }

    if(x % y == 0) {return y;}
    return gcd2( y, x%y);
}

int gcd1(int *a, int i, int j){
    if(j - i == 0) { return a[i]; }
    if(j - i == 1) { return gcd2(a[i], a[j]); }
    return gcd2( gcd1(a, i, i + (j-i)/2), gcd1(a, i + (j-i)/2 + 1, j));
}

int gcd(int *a, int size) {
    return gcd1(a, 0, size-1);
}

int main(void) 
{
    int n, x, i = 0;
    scanf("%d %d", &n, &x);
    int a[n];
    while(i < n) {
        scanf("%d", &a[i] ); a[i] -= x; 
        if(a[i] < 0) { a[i] *= -1; } i++;
    }
    printf("%d\n", gcd(a, n));
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:25:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &x);
     ^
./Main.c:28:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &a[i] ); a[i] -= x; 
         ^