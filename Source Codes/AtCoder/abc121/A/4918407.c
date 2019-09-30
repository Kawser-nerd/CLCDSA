#include<stdio.h>
int main(){
  int A[10][10];
  int i,j;
  int H,W,h,w;
  
  scanf("%d %d",&H,&W);
  scanf("%d %d",&h,&w);
  
  int ans;
  ans=H*W-(h*W+w*H-h*w);
  printf("%d",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&H,&W);
   ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&h,&w);
   ^