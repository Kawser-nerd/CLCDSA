#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,C[100];
    scanf("%d",&N);
    int i,j;
    for(i=0;i<N;i++){
        scanf("%d",&C[i]);
    }
    int cnt[100]={0};
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(i==j)continue;
            if(C[i]%C[j]==0){
                cnt[i]++;
            }
        }
    }
    double ans=0;
    double tmp;
    for(i=0;i<N;i++){
        tmp=0;
        if(cnt[i]%2==1){
            tmp+=(double)1/2;
        }else{
            tmp+=(double)(cnt[i]+2)/(2*(cnt[i]+1));
        }
        ans+=tmp;
    }
    for(j=2;j<=N;j++)tmp/=j;
    printf("%lf\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&C[i]);
         ^