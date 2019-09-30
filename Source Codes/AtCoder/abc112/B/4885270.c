#include <stdio.h>
#include <math.h>

int main(){
    int n,T,ans=10000;
    scanf("%d%d",&n,&T);
    for(int i = 0;i < n;i ++){
        int c,t;
        scanf("%d%d",&c,&t);
        ans = t<=T&&c<ans?c:ans;
    }
    if(ans==10000) printf("TLE\n");
    else printf("%d",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&T);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d",&c,&t);
         ^