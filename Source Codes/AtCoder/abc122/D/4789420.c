#include <stdio.h>
#include <stdbool.h>
//T -- 0 A -- 1 G -- 2 C -- 3
long mod = 1e9+7;

long add(long a, long b) {
    return (a + b) % mod;
}

bool ng(int a, int b, int c) {
    return (a == 1 && b == 2 && c == 3);
}

void solve(int n) {
    int i, a, b, c, d;
    long ans;
    long dp[n+2][4][4][4];
    for(i = 0; i <=n; ++i) {
        for(a = 0; a < 4; ++a){
            for(b = 0; b < 4; ++b) {
                for(c = 0; c < 4; ++c) {
                    if(i == 0 && a == 0 && b == 0 && c == 0) {
                        dp[i][a][b][c] = 1;
                    }
                    else { dp[i][a][b][c] = 0; }
                }
            }
        }
    }
    for(i = 0; i <n; ++i) {
        for(a = 0; a < 4; ++a) {
            for(b = 0; b < 4; ++b) {
                for(c = 0; c < 4; ++c) {
                    for(d = 0; d < 4; ++d) {
                        if(ng(b,c,d) || ng(c,b,d) || ng(b,d,c)) { continue; }
                        if(ng(a,c,d) || ng(a,b,d)) { continue; }
                        dp[i+1][b][c][d] = add(dp[i+1][b][c][d], dp[i][a][b][c]);
                    }
                }
            }
        }
    }
    ans = 0L;
    for(a = 0; a < 4; ++a) {
        for(b = 0; b < 4; ++b) {
            for(c = 0; c < 4; ++c) {
                ans = add(ans, dp[n][a][b][c]);
            }
        }
    }
    //printf("mod: %d\n", 1000000009);
    printf("%ld\n", ans);
}

int main(void) {
    int n;
    scanf("%d", &n);
    solve(n);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:57:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^