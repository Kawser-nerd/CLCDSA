#include <stdio.h>

int main(void) {
    FILE *fin = fopen("C.in", "r");
    FILE *fout = fopen("C.out", "w");
    int T, K, n, d[100];
    int KI[5001];
    int i, j, k, cur;
    
    fscanf(fin, "%d", &T);
    for (i = 1; i <= T; i++) {
        fscanf(fin, "%d", &K);
        fscanf(fin, "%d", &n);
        for (j = 0; j < n; j++)
            fscanf(fin, "%d", &d[j]);
        for (j = 1; j <= K; j++)
            KI[j] = 0;
        cur = 1;
        for (j = 1; j <= K; j++) {
            k = 1;
            while (k <= j) {
                if (KI[cur] == 0)
                    k++;
                cur++;
                if (cur > K)
                    cur %= K;
            }
            if (cur == 1)
                KI[K] = j;
            else
                KI[cur-1] = j;
        }
        fprintf(fout, "Case #%d:", i);
        for (j = 0; j < n; j++)
            fprintf(fout, " %d", KI[d[j]]);
        fprintf(fout, "\n");
    }
    
    return 0;
}
