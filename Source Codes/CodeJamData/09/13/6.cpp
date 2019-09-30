#include <stdio.h>

int n, c;
double C[41][41];
double data[41];

int main ()
{
    int t;
    int ct = 0;
    
    for (int i = 0; i <= 40; i ++)
        for (int j = 0; j <= 40; j ++)
            C[i][j] = 0.0;
    for (int i = 0; i <= 40; i ++)
    {
        C[i][0] = C[i][i] = 1.0;
        
        for (int j = 1; j < i; j ++)
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
    
    for (scanf("%d", &t); t > 0; t --)
    {
        scanf("%d%d", &n, &c);
        data[n] = 0;
        for (int i = n - 1; i >= 0; i --)
        {
            double tot = 0, totprob = 0;
            for (int j = 1; j <= c && i + j <= n; j ++)
            {
                totprob += C[n - i][j] * C[i][c - j];
                tot += C[n - i][j] * C[i][c - j] * data[i + j];
            }
            double realtot = totprob + C[n - i][0] * C[i][c];
            /*
                p = 1 + (tot / totprob) * totprob / realtot + p * (1 - totprob / realtot)
                p = 1 + tot / realtot + p - p * totprob / realtot
                p = realtot / totprob + tot / totprob
            */
            
            data[i] = (realtot + tot) / totprob;

//            printf("%d: %lf %lf %lf : %lf\n", i, tot, totprob, realtot, data[i]);
        }
        
        printf("Case #%d: %.7lf\n", ++ct, data[0]);
    }
    
    return 0;
}
