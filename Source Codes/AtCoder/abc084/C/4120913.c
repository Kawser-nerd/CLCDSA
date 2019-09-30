#include <stdio.h>
int main()
{
    int n,i,j;
    int Time[500][4]={0};
    scanf("%d",&n);
    for(i=0;i<n-1;i++)
    {
        for (j=0;j<3;j++)
        {
            scanf("%d",&Time[i][j]);
        }
    }
    for (i=0;i<n;i++)
    {
        for (j=i;j<n-1;j++)
        {
            if (j==i) Time[i][3]+=Time[j][1];
            if (Time[i][3]>=Time[j][1])
            {
                if (Time[i][3]%Time[j][2]==0)
                {
                    goto a;
                }
                else Time[i][3]+=Time[j][2]-Time[i][3]%Time[j][2];
            }
            else Time[i][3]=Time[j][1];
            a:
            Time[i][3]+=Time[j][0];
        }
        printf("%d\n",Time[i][3]);
    }
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:11:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&Time[i][j]);
             ^