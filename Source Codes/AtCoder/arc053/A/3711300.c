#include<stdio.h>

int main(){
int h,w;scanf("%d%d",&h,&w);
int ans=0;
ans+=(w-1)*h;
ans+=(h-1)*w;
printf("%d\n",ans);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 int h,w;scanf("%d%d",&h,&w);
         ^