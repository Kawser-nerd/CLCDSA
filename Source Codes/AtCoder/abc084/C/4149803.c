#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,train[500][3],t[500]={0};
    scanf("%d",&n);
    for (i=0;i<(n-1);i++)
    {
        scanf("%d %d %d",&train[i][1],&train[i][2],&train[i][3]);
    }
    for (i=0;i<(n-1);i++)
    {
        t[i]=train[i][1]+train[i][2];
        for (j=i+1;j<(n-1);j++)
        {
            if (t[i]<train[j][2]) t[i]=train[j][2];
            if (t[i]%train[j][3]!=0)
                t[i]=(t[i]/train[j][3]+1)*train[j][3];
            t[i]+=train[j][1];
        }
    }
    for (i=0;i<n;i++)
    {
        printf("%d\n",t[i]);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d %d",&train[i][1],&train[i][2],&train[i][3]);
         ^