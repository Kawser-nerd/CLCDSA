#include<stdio.h>
#include<stdlib.h>
int main()
{
    int N,i,j,sum=0;
    int A[100050]={0};
    scanf("%d",&N);
    for(i=1;i<N+1;i++)
        scanf("%d",&A[i]);
    for(i=1;i<N+1;i++)
        sum+=abs(A[i]-A[i-1]);
    sum+=abs(A[N]-A[0]);
    for(i=1;i<=N;i++)
        printf("%d\n",sum-abs(A[i]-A[i-1])-abs(A[i+1]-A[i])+abs(A[i+1]-A[i-1]));
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&A[i]);
         ^