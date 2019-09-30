#include <stdio.h>

int N, M, V, G[10000], C[10000], I[10000], req[10000];

int smin(int n) {
    int min1 = 0, min2 = 0, min3 = 0;
    if (n > (M-1)/2) {
        if (req[n] != I[n])
            return 10000;
        else
            return 0;
    }
    if (req[n] == I[n])
        return 0;
    if (C[n] == 0) {
        if (req[n] == 0) {
            if (G[n] == 0)
                min1 = min2 = 10000;
            else {
                req[2*n] = 0; req[2*n+1] = 1;
                min1 += smin(2*n) + smin(2*n+1);
                req[2*n] = 1; req[2*n+1] = 0;
                min2 += smin(2*n) + smin(2*n+1);
            }
            req[2*n] = 0; req[2*n+1] = 0;
            min3 += smin(2*n) + smin(2*n+1);
        }
        if (req[n] == 1) {
            if (G[n] == 1)
                min1 = min2 = 10000;
            else {
                req[2*n] = 0; req[2*n+1] = 1;
                min1 += smin(2*n) + smin(2*n+1);
                req[2*n] = 1; req[2*n+1] = 0;
                min2 += smin(2*n) + smin(2*n+1);
            }
            req[2*n] = 1; req[2*n+1] = 1;
            min3 += smin(2*n) + smin(2*n+1);
        }
    }
    if (C[n] == 1) {
        if (req[n] == 0) {
            if (G[n] == 0)
                min1 = min2 = 1;
            req[2*n] = 0; req[2*n+1] = 1;
            min1 += smin(2*n) + smin(2*n+1);
            req[2*n] = 1; req[2*n+1] = 0;
            min2 += smin(2*n) + smin(2*n+1);
            req[2*n] = 0; req[2*n+1] = 0;
            min3 += smin(2*n) + smin(2*n+1);
        }
        if (req[n] == 1) {
            if (G[n] == 1)
                min1 = min2 = 1;
            req[2*n] = 0; req[2*n+1] = 1;
            min1 += smin(2*n) + smin(2*n+1);
            req[2*n] = 1; req[2*n+1] = 0;
            min2 += smin(2*n) + smin(2*n+1);
            req[2*n] = 1; req[2*n+1] = 1;
            min3 += smin(2*n) + smin(2*n+1);
        }
    }
    if (min1 <= min2 && min1 <= min3)
        return min1;
    else if (min2 <= min1 && min2 <= min3)
        return min2;
    else
        return min3;
}

int main(void) {
    FILE *fin = fopen("A.in", "r");
    FILE *fout = fopen("A.out", "w");
    int i, j, min;
    
    fscanf(fin, "%d", &N);
    for (i = 1; i <= N; i++) {
        fscanf(fin, "%d %d", &M, &V);
        for (j = 1; j <= (M-1)/2; j++)
            fscanf(fin, "%d %d", &G[j], &C[j]);
        for (j = (M-1)/2+1; j <= M; j++)
            fscanf(fin, "%d", &I[j]);
        for (j = (M-1)/2; j >= 1; j--) {
            if (G[j] == 0) {
                if (I[2*j] == 1 || I[2*j+1] == 1)
                    I[j] = 1;
                else
                    I[j] = 0;
            }
            else {
                if (I[2*j] == 1 && I[2*j+1] == 1)
                    I[j] = 1;
                else
                    I[j] = 0;
            }
        }
        req[1] = V;
        min = smin(1);
        fprintf(fout, "Case #%d: ", i);
        if (min >= 10000)
            fprintf(fout, "IMPOSSIBLE\n");
        else
            fprintf(fout, "%d\n", min);
    }
    
    return 0;
}
