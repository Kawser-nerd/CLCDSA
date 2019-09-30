#include <stdio.h>

int main()
{
    int t, casenum;
    int n;
    
    char grid[100][100];
    int w[100], p[100];
    double wp[100], owp[100], oowp[100];
    int i, j;
    
    scanf("%d", &t);
    
    for (casenum=1; casenum<=t; casenum++)
    {
        scanf("%d", &n);
        for (i=0; i<n; i++)
        {
            w[i] = p[i] = 0;
            scanf(" ");
            for (j=0; j<n; j++)
            {
                scanf("%c", &grid[i][j]);
                switch (grid[i][j])
                {
                case '1':
                    w[i]++;
                case '0':
                    p[i]++;
                }
            }
            wp[i] = (double)w[i] / p[i];
        }
        for (i=0; i<n; i++)
        {
            owp[i] = 0;
            for (j=0; j<n; j++)
            {
                if (grid[i][j] == '0')
                    owp[i] += (w[j] - 1.0) / (p[j] - 1.0);
                else if (grid[i][j] == '1')
                    owp[i] += w[j] / (p[j] - 1.0);
            }
            owp[i] /= p[i];
        }
        for (i=0; i<n; i++)
        {
            oowp[i] = 0;
            for (j=0; j<n; j++)
            {
                if (grid[i][j] != '.')
                    oowp[i] += owp[j];
            }
            oowp[i] /= p[i];
        }
        
        printf("Case #%d:\n", casenum);
        for (i=0; i<n; i++)
        {
            printf("%.8f\n", 0.25*wp[i] + 0.5*owp[i] + 0.25*oowp[i]);
        }
    }
    
    return 0;
}
