#include <stdio.h>

int main(void)
{
    int i,j,x,N,count=0,a[50]={0};
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%d",&x);
        for(j=0;j<N;j++)
        {
            if(x<=a[j])
            {
                a[j]=x;
                break;
            }
            if(a[j]==0)
            {
                a[j]=x;
                count++;
                break;
            }
        }
    }
    printf("%d\n",count);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&x);
         ^