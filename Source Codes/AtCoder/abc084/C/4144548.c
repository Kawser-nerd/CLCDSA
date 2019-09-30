#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    int C[501],S[501],F[501],Result[501];
    int i,j;
    scanf("%d",&N);
    for (i=0;i<N-1;i++)
    {
        scanf("%d%d%d",&C[i],&S[i],&F[i]);
    }
    for (i=0;i<N-1;i++)
    {
        Result[i]=S[i]+C[i];
        for (j=i+1;j<N-1;j++)
        {
            if (Result[i]<S[j])
            {
                Result[i]=S[j];
            }
            else
            {
                if (Result[i]%F[j]!=0)
                {
                    Result[i]=Result[i]-(Result[i]%F[j])+F[j];
                }
            }
            Result[i]+=C[j];
        }
    }
    Result[N-1]=0;
    for (i=0;i<N;i++)
    {
        printf("%d\n",Result[i]);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:12:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d%d",&C[i],&S[i],&F[i]);
         ^