#include <stdio.h>

#define N_MAX 110

int testc, test, i, j, k1, k2;
int typeA[N_MAX], typeB[N_MAX], n, m;
long long accountA[N_MAX], accountB[N_MAX], f[N_MAX][N_MAX], sumA[N_MAX][N_MAX], sumB[N_MAX][N_MAX];

int main()
{
    FILE *fin = fopen("gcj3_3.in", "r");
    FILE *fout = fopen("gcj3_3.out", "w");
    
    fscanf(fin, "%d", &testc);
    for (test = 1; test <= testc; test++)
    {
        fscanf(fin, "%d%d", &n, &m);
        for (i = 1; i <= n; i++)
        {
            fscanf(fin, "%I64d%d", &(accountA[i]), &(typeA[i]));
            f[i][0] = 0;
        }
        for (j = 1; j <= m; j++)
        {
            fscanf(fin, "%I64d%d", &(accountB[j]), &(typeB[j]));
            f[0][j] =  0;
        }
        f[0][0] = 0;
        for (i = 1; i <= 100; i++)
            sumA[0][i] = sumB[0][i] = 0;
        for (i = 1; i <= n; i++)
            for (j = 1; j <= 100; j++)
                sumA[i][j] = typeA[i] == j ? sumA[i - 1][j] + accountA[i] : sumA[i - 1][j];
        for (i = 1; i <= m; i++)
            for (j = 1; j <= 100; j++)
                sumB[i][j] = typeB[i] == j ? sumB[i - 1][j] + accountB[i] : sumB[i - 1][j];
        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++)
            {
                f[i][j] = f[i - 1][j] > f[i][j - 1] ? f[i - 1][j] : f[i][j - 1];
                if (typeA[i] == typeB[j])
                {
                    int target = typeA[i];
                    for (k1 = 0; k1 < i; k1++)
                        for (k2 = 0; k2 < j; k2++)
                        {
                            long long delta = sumA[i][target] - sumA[k1][target] < sumB[j][target] - sumB[k2][target] ? sumA[i][target] - sumA[k1][target] : sumB[j][target] - sumB[k2][target];
                            f[i][j] = f[k1][k2] + delta > f[i][j] ? f[k1][k2] + delta : f[i][j];
                        }
                }
            }
        fprintf(fout, "Case #%d: %I64d\n", test, f[n][m]);
    }
    
    fclose(fin);
    fclose(fout);
    return 0;
}
