#include <stdio.h>
#include<stdlib.h>


int main(void){
    int N,A;
    scanf("%d %d",&N,&A);
    long long int kotaekazu[51][2501]={}; //??????????????????
    kotaekazu[0][0]=1;
    int kari;
    for(int i=0;i<N;i++){
        scanf("%d",&kari);
        for(int j=N-1;j>=0;j--){
            for(int k=49*N;k>=0;k--){
                kotaekazu[j+1][k+kari]+=kotaekazu[j][k];
            }
        }
    }
    long long int ans=0;
    for(int i=1;i<=N;i++)ans+=kotaekazu[i][A*i];
    printf("%lld",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&N,&A);
     ^
./Main.c:12:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&kari);
         ^