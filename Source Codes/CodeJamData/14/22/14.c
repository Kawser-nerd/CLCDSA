#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)

int n = 32;
bool visited[35][2][2][2];
long long int dp[35][2][2][2];
char A[35], B[35], K[35], str[35], temp[35];

long long int F(int i, bool a, bool b, bool k){
    if (i == n) return 1;
    if (visited[i][a][b][k]) return dp[i][a][b][k];

    int d, j, l;
    long long int res = 0;
    for (j = 0; j < 2; j++){
        for (l = 0; l < 2; l++){
            d = j & l;
            if ( (a || j <= A[i]) && (b || (l <= B[i])) && (k || (d <= K[i])) ){
                res = res + F(i + 1, (a || j < A[i]), (b || l < B[i]), (k || d < K[i]));
            }
        }
    }

    visited[i][a][b][k] = true;
    return (dp[i][a][b][k] = res);
}

void convert(int x, int i){
    int j, k = 0, d = 0;
    for (; ;){
        temp[d++] = (x & 1) + 48;
        x >>= 1;
        if (!x) break;
    }
    for (j = n - d; j; j--) str[k++] = 48;
    for (j = d - 1; j >= 0; j--) str[k++] = temp[j];
    str[k] = 0;

    if (i == 0) strcpy(A, str);
    if (i == 1) strcpy(B, str);
    if (i == 2) strcpy(K, str);
}

int main(){
    read();
    write();
    int T = 0, t, a, b, k, i, j;

    scanf("%d", &t);
    while (t--){
        scanf("%d %d %d", &a, &b, &k);
        a--, b--, k--;
        convert(a, 0);
        convert(b, 1);
        convert(k, 2);
        for (i = 0; i < n; i++) A[i] -= 48, B[i] -= 48, K[i] -= 48;

        clr(visited);
        long long int res = F(0, false, false, false);
        printf("Case #%d: %lld\n", ++T, res);
    }
    return 0;
}
