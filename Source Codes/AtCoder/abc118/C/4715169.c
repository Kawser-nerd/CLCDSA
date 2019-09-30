#include <stdio.h>
#include <stdlib.h>

int lc(int a, int b) {
    int tmp;
    if(a > b) { tmp = a; a = b; b = tmp; }

    while(1){
        if(b == 0) { break; }
        a = a % b;
        tmp = a; a = b; b = tmp;
    }
    return a;
}

int lcursion(int *a, int i, int j) {
    if(i == j) { return a[i]; }
    else if(j - i == 1) { return lc(a[i], a[j]); }
    else { 
        int h = (i + j)/2;
        return lc(lcursion(a, i, h), lcursion(a, h+1, j) );
    }
}

int lcm(int *a, int n) {
    return lcursion(a, 0, n-1);
}

int main(void)
{
    int n, i; scanf("%d", &n);
    int *a = (int*)malloc((n+2) * sizeof(int));
    for(i = 0; i < n; ++i) { scanf("%d", &a[i]); }
    printf("%d\n", lcm(a, n));
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:31:15: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     int n, i; scanf("%d", &n);
               ^
./Main.c:33:30: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(i = 0; i < n; ++i) { scanf("%d", &a[i]); }
                              ^