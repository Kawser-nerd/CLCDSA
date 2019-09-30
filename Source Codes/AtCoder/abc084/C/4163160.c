#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    int n;
    scanf("%d",&n);
    int C[510],S[510],F[510];
    int i;
    for(i=1;i<n;i++)
        scanf("%d%d%d",&C[i],&S[i],&F[i]);
    int j,h;
    int sum;
    sum=0;
    for(i=1;i<n;i++)
    {
        sum=S[i]+C[i];
        for(j=1;j<n-i;j++)
        {
            int m;
            if(sum<S[i+j])
                m=S[i+j];
            else
            {
                for(h=1;  ;h++)
                {
                    m=S[i+j]+h*F[i+j];
                    if(m>=sum && m%F[i+j]==0)
                        break;
                }
            }
            sum=C[i+j]+m;
        }
        printf("%d\n",sum);
    }
    if(i==n)
        printf("0\n");
    
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d%d",&C[i],&S[i],&F[i]);
         ^