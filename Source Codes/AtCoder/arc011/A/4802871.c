#include <stdio.h>
int main(void){
    int m,n,N,i,sum,henka;
    scanf("%d%d%d",&m,&n,&N);
    sum=N;
    while(N/m*n!=0){
        sum+=N/m*n;
        N=N%m+N/m*n;
    }
    printf("%d\n",sum);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&m,&n,&N);
     ^