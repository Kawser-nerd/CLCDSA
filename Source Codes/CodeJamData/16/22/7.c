#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 20
#define lol(x) (((x)<0)?-(x):(x))
#define min(a,b) ((a)<(b) ? (a):(b))
#define max(a,b) ((a)>(b) ? (a):(b))
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("out.txt", "w", stdout)

const long long fuck = 7391201922174776LL;

int t, n;
long long P[MAX], dp[5][MAX];
char A[MAX], B[MAX], first[MAX], second[MAX], visited[5][MAX];

long long F(int flag, int i){
    if (i == n) return 0;
    if (visited[flag][i]) return dp[flag][i];

    int j, k, l, c, d;
    long long x, y, z, r, res = fuck;
    for (j = 0; j < 10; j++){
        for (k = 0; k < 10; k++){
            c = j, d = k;
            if (first[i] != '?') c = first[i] - 48;
            if (second[i] != '?') d = second[i] - 48;

            if (flag == 0){
                for (l = 0; l < 2; l++){
                    z = (P[n - i - 1] * (c - d)) + F(l, i + 1);
                    if (res == fuck) res = z;
                    else if (z < res) res = z;
                }
            }

            if (flag == 1){
                for (l = 0; l < 2; l++){
                    z = (P[n - i - 1] * (c - d)) + F(l, i + 1);
                    if (res == fuck) res = z;
                    else if (z > res) res = z;
                }
            }

            if (flag == 2){
                for (l = 2; l < 4; l++){
                    z = (P[n - i - 1] * (d - c)) + F(l, i + 1);
                    if (res == fuck) res = z;
                    else if (z < res) res = z;
                }
            }

            if (flag == 3){
                for (l = 2; l < 4; l++){
                    z = (P[n - i - 1] * (d - c)) + F(l, i + 1);
                    if (res == fuck) res = z;
                    else if (z > res) res = z;
                }
            }

            if (flag == 4){
                z = (P[n - i - 1] * lol(c - d)) + F(4, i + 1);
                if (res == fuck) res = z;
                else if (z < res) res = z;

                if (c != d){
                    if (c < d){
                        z = (P[n - i - 1] * (c - d)) + F(1, i + 1);
                        z = lol(z);
                        if (res == fuck) res = z;
                        else if (z < res) res = z;

                    }
                    else{
                        z = (P[n - i - 1] * (d - c)) + F(3, i + 1);
                        z = lol(z);
                        if (res == fuck) res = z;
                        else if (z < res) res = z;
                    }
                }
            }
        }
    }

    visited[flag][i] = true;
    return (dp[flag][i] = res);
}

void backtrack(int flag, int i){
    if (i == n) return;

    int j, k, l, c, d, r1, r2, r3 = -1;
    long long x, y, z, r, res = fuck;
    for (j = 0; j < 10; j++){
        for (k = 0; k < 10; k++){
            c = j, d = k;
            if (first[i] != '?') c = first[i] - 48;
            if (second[i] != '?') d = second[i] - 48;

            if (flag == 0){
                for (l = 0; l < 2; l++){
                    z = (P[n - i - 1] * (c - d)) + F(l, i + 1);
                    if (res == fuck) res = z, r1 = c, r2 = d, r3 = l;
                    else if (z < res) res = z, r1 = c, r2 = d, r3 = l;
                }
            }

            if (flag == 1){
                for (l = 0; l < 2; l++){
                    z = (P[n - i - 1] * (c - d)) + F(l, i + 1);
                    if (res == fuck) res = z, r1 = c, r2 = d, r3 = l;
                    else if (z > res) res = z, r1 = c, r2 = d, r3 = l;
                }
            }

            if (flag == 2){
                for (l = 2; l < 4; l++){
                    z = (P[n - i - 1] * (d - c)) + F(l, i + 1);
                    if (res == fuck) res = z, r1 = c, r2 = d, r3 = l;
                    else if (z < res) res = z, r1 = c, r2 = d, r3 = l;
                }
            }

            if (flag == 3){
                for (l = 2; l < 4; l++){
                    z = (P[n - i - 1] * (d - c)) + F(l, i + 1);
                    if (res == fuck) res = z, r1 = c, r2 = d, r3 = l;
                    else if (z > res) res = z, r1 = c, r2 = d, r3 = l;
                }
            }

            if (flag == 4){
                z = (P[n - i - 1] * lol(c - d)) + F(4, i + 1);
                if (res == fuck) res = z, r1 = c, r2 = d, r3 = 4;
                else if (z < res) res = z, r1 = c, r2 = d, r3 = 4;

                if (c != d){
                    if (c < d){
                        z = (P[n - i - 1] * (c - d)) + F(1, i + 1);
                        z = lol(z);
                        if (res == fuck) res = z, r1 = c, r2 = d, r3 = 1;
                        else if (z < res) res = z, r1 = c, r2 = d, r3 = 1;

                    }
                    else{
                        z = (P[n - i - 1] * (d - c)) + F(3, i + 1);
                        z = lol(z);
                        if (res == fuck) res = z, r1 = c, r2 = d, r3 = 3;
                        else if (z < res) res = z, r1 = c, r2 = d, r3 = 3;
                    }
                }
            }
        }
    }

    A[i] = r1 + 48, B[i] = r2 + 48;
    backtrack(r3, i + 1);
}

int main(){
    read();
    write();
    int T = 0, i, j, k, l;
    for (P[0] = 1, i = 1; i < MAX; i++) P[i] = P[i - 1] * 10;

    scanf("%d", &t);
    while (t--){
        scanf("%s %s", first, second);
        n = strlen(first);

        clr(visited);
        backtrack(4, 0);
        A[n] = 0, B[n] = 0;
        printf("Case #%d: %s %s\n", ++T, A, B);
    }
    return 0;
}
