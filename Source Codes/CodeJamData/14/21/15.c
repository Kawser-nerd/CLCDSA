#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i,j;
    int ii,jj,kk;
    int res;
    int m;
    int end, xw, ow;
    int r1,r2;
    int count; 
    int n,k;
    char str[200][200];
    char str2[200][200];
    int num[200][200];

    unsigned long long result;
    int match;
    int ans;

    scanf("%d", &m);

    for(ii = 1; ii <= m; ii++)
    {
        memset(str, 0, 40000);
        memset(str2, 0, 40000);
        memset(num, 0, 200 * sizeof(int));
        ans = 0;
        scanf("%d", &n);
        for(i = 0; i < n; i++)
            scanf("%s", &str[i]);
      
        for(i = 0; i < n; i++)
        {
            k = 0;
            for(j = 0; j < strlen(str[i]); j++)
            {
                if(j == 0 || str[i][j] != str[i][j-1])
                {
                    num[i][k] = 1;
                    str2[i][k++] = str[i][j];
                }
                else
                {
                    num[i][k-1]++;
                }
            }
        }
        match = 1;
        for(i = 1; i < n; i++)
        {
            if(strcmp(str2[i], str2[i-1]) != 0)
            {
                match =0;
                break;
            }
        }

        int min;
        if(match == 1)
        {
            for(j = 0; num[0][j] != 0 ; j++)
            {
                min = 999999999;
                for(i =0; i < n; i++)
                {
                    int temp = 0;
                    for(jj = 0; jj < n; jj++)
                    {
                        if(i == jj)
                            continue;
                        else
                        {
                            int t2;
                            t2 = num[jj][j] - num[i][j];
                            if(t2 < 0)
                                t2 *= -1;

                            temp += t2;
                        }
                    }
                    if(temp < min)
                        min = temp;
                }
                ans += min;
            }
        }

        if(match == 0)
            printf("Case #%d: Fegla Won\n", ii);
        else
            printf("Case #%d: %d\n", ii, ans);
    }
}
