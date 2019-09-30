#include <bits/stdc++.h>
using namespace std;

long long dp[40][2][2][2];
int a[100], b[100], c[100];

long long f(int x, int uA, int uB, int uK) {
    if (x == -1) {
        return 1;
    }
    if (dp[x][uA][uB][uK] != -1) return dp[x][uA][uB][uK];
    int upA = 1, upB = 1, upK = 1;
    if (uA) upA = a[x];
    if (uB) upB = b[x];
    if (uK) upK = c[x];
    long long ans = 0;
    for (int numa = 0; numa <= upA; numa++) {
        for (int numb = 0; numb <= upB; numb++) {
            if (numa & numb > upK) continue;
            int tuA = 0, tuB = 0, tuK = 0;
            if (uA && numa == a[x]) tuA = 1;
            if (uB && numb == b[x]) tuB = 1;
            if (uK && (numa & numb) == c[x]) tuK = 1;
            ans += f(x - 1, tuA, tuB, tuK);
        }
    }
    return dp[x][uA][uB][uK] = ans;
}

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        int A, B, K;
        scanf("%d%d%d", &A, &B, &K);
        A--;
        B--;
        K--;
        for (int i = 0; i < 40; i++) {
            a[i] = A % 2;
            b[i] = B % 2;
            c[i] = K % 2;
            A /= 2;
            B /= 2;
            K /= 2;
        }
        memset(dp, -1, sizeof(dp));
        printf("Case #%d: %I64d\n", cas, f(39, 1, 1, 1));
    }
    return 0;
}
