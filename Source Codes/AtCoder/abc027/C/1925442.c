#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define rep(n, i) for(int i = 0; i < n; i++)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

void solve(void){
    unsigned long n, m, k, x;
    scanf("%lu\n", &n);
    k = 0; m = n;
    while (m > 1) {
        m /= 2;
        k++;
    }
    x = 1;
    long count = 0;
    if (k % 2 == 0){
        while (x <= n) {
            if (count % 2 == 1) x = 2*x;
            else x = 2*x+1;
            count++;
        }
        if (count % 2 == 0) printf("Takahashi\n");
        else printf("Aoki\n");
    }
    else{
        while (x <= n) {
            if (count % 2 == 0) x = 2*x;
            else x = 2*x+1;
            count++;
        }
        if (count % 2 == 0) printf("Takahashi\n");
        else printf("Aoki\n");
    }
}

int main(void){
  solve();
  return 0;
} ./Main.c: In function ‘solve’:
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lu\n", &n);
     ^