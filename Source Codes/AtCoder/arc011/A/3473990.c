#include <stdio.h>
int main(void){
    int n,m,N,ans=0,s=0;
    scanf("%d%d%d",&m,&n,&N);
    while(N!=0){
        ans+=N;
        s+=N;
        N=s/m*n;
        s=s%m;
    }
    printf("%d\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&m,&n,&N);
     ^