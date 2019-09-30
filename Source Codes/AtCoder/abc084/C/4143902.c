#include<stdio.h>
int main()
{
    int C[500],S[500],F[500];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
        scanf("%d%d%d",C+i,S+i,F+i);
    for(int i=0;i<=n-1;i++)
    {
        int t = 0;
        for(int j = i;j<n-1;j++)
        {
            int temp = S[j]/F[j];
            int m = t/F[j];
            m += ((t%F[j]==0)?0:1);
            if(m<=temp) t = S[j]+C[j];
            else t = m*F[j]+C[j];
        }
        printf("%d\n",t);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d%d",C+i,S+i,F+i);
         ^