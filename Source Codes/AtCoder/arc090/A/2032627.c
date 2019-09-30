#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,a[2][101],p=0,m=0,max,sum;
    scanf("%d",&n);
    for(i=0;i<2;i++)
    for(j=0;j<n;j++)
    {
        scanf("%d",&a[i][j]);
    }
    max=0;
    for(j=0;j<n;j++)
    {
        max=max+a[1][j];
    }
    max=max+a[0][0];
    while(p<n)
    {
        sum=0;
        for(j=0;j<=m;j++)
        {
            sum=sum+a[0][j];
        }
    for(j=m;j<n;j++)
    {
        sum=sum+a[1][j];
    }
    if(max<sum)
    {
        max=sum;
    }
        m++;
        p++;

    }
    printf("%d\n",max);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i][j]);
         ^