#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N;
    scanf("%d",&N);
    int S[N],C[N],F[N],t=0;
    int i,j;
    for(i=1; i<N; i++)
    {
        scanf("%d%d%d",&C[i],&S[i],&F[i]);
    }
    int result[N];
    memset(result,0,sizeof(result));
    for(i=1; i<=N-1; i++)
    {
        for(j=i;j<=N-1;j++)
        {
            if(t<S[j])
                t=S[j];
            if(t%F[j]==0)
                t+=C[j];
            else
            {
                while(t%F[j]!=0)
                    t++;
                t+=C[j];
            }
        }
        result[i]=t;
        t=0;

    }

    for(i=1; i<=N-1; i++)
        printf("%d\n",result[i]);
    printf("%d\n",0);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:13:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d%d",&C[i],&S[i],&F[i]);
         ^