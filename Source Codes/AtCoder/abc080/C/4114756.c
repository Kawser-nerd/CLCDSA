#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,k,n,F[100][10],P[100][11],d[10],bodays[100],t=0,sum=0,max=-1e+9;
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        for (j=0;j<10;j++)
        {
            scanf("%d",&F[i][j]);
        }
    }
    for (i=0;i<n;i++)
    {
        for (j=0;j<11;j++)
        {
            scanf("%d",&P[i][j]);
        }
    }
    for (i=1;i<1024;i++)
    {
        for (j=0;j<10;j++)
            d[j]=(i>>j)%2;
        for (k=0;k<n;k++)
        {
            for (t=0,j=0;j<10;j++)
            {
                if (F[k][j]&&d[j]) t++;
            }
            bodays[k]=t;
        }
        for (sum=0,k=0;k<n;k++)
            sum+=P[k][bodays[k]];
        if (sum>max) max=sum;
    }
    printf("%d",max);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:12:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&F[i][j]);
             ^
./Main.c:19:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&P[i][j]);
             ^