#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)

char str[25];
long long dp[100], sum[100], P[100];

bool isPalindrome(long long x){
    int i, j;
    char temp[25];

    for (i = 0; i < 18; i++){
        if (P[i] == x) return true;
    }
    return false;
}

long long F(long long n){
    if (n <= 10) return n;
    int i, j, flag = 0;

    long long x = 0, y = 0, res = 0;
    sprintf(str, "%lld", n);
    int len = strlen(str);
    int mid = len >> 1;
    for (j = mid; j < len; j++) x = (x * 10) + (str[j] - 48);
    for (j = mid - 1; j >= 0; j--) y = (y * 10) + (str[j] - 48);

    if (!x) return F(n - 1) + 1;
    for (i = 0; ;i++){
        if (P[i] > n) break;
    }

    res = x + y + sum[--i];
    if (isPalindrome(y)) res--;
    return res;
}

int main(){
    read();
    write();
    int T = 0, t, i, j, k;
    long long mul = 9, n, x, y, res;

    dp[0] = 1;
    for (i = 1; i < 100; i++){
        dp[i] = (dp[i - 1] + mul);
        if (!(i & 1)) mul *= 10;
    }

    for (i = 0; i < 100; i++){
        sum[i] = dp[i];
        if (i) sum[i] += sum[i - 1];
    }

    P[0] = 1;
    for (i = 1; i < 100; i++) P[i] = (P[i - 1] * 10);
    for (i = 0; i < 100; i++) sum[i]--;

    scanf("%d", &t);
    while (t--){
        scanf("%lld", &n);
        printf("Case #%d: %lld\n", ++T, F(n));
    }
    return 0;
}
