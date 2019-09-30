#include <stdio.h>


int main(void){
    int po[114514]={};
    int N;
    scanf("%d",&N);
    int ans=0;
    for(int i=0;i<N;i++){
        int kari;
        scanf("%d",&kari);
        if(kari<114514)po[kari]++;
        else ans++;
    }
    for(int i=0;i<114514;i++){
        if(po[i]>=i)ans+=po[i]-i;
        else ans+=po[i];
    }
    printf("%d",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&kari);
         ^