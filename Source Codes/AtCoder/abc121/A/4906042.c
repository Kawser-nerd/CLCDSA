#include <stdio.h>
   #include <stdlib.h>

    
   int main(){
       int H, W;
       scanf("%d %d", &H, &W);
       int h,w;
       scanf("%d %d", &h, &w);
       int ans;
       ans=H*W;
       ans-=h*W;
       ans-=w*H;
       ans+=h*w;
       printf("%d",ans);
       return 0;
   } ./Main.c: In function ‘main’:
./Main.c:7:8: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
        scanf("%d %d", &H, &W);
        ^
./Main.c:9:8: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
        scanf("%d %d", &h, &w);
        ^