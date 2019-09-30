#include <stdio.h>

#define Nmax 110000
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
int memo[Nmax];

int dp(int n) {
    if (memo[n] != -1) return memo[n];
    if (n == 0) return 0;
    int ans = 100000000;
    for (int n6 = 1; n6 <= n; n6 *= 6) {
        ans = MIN(ans, 1 + dp(n - n6));
    }
    for (int n9 = 1; n9 <= n; n9 *= 9) {
        ans = MIN(ans, 1 + dp(n - n9));
    }
    return memo[n] = ans;
}

int main() {
    int N;
    scanf("%d",&N);  
    for (int i=0; i<Nmax; i++) memo[i] = -1;
    printf("%d", dp(N));
} ./Main.c: In function ‘main’:
./Main.c:23:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);  
     ^