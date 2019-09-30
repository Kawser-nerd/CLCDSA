#include<stdio.h>
#include<stdint.h>

int main(){
  int32_t r,x1,y1,x2,y2,x3,y3;
  scanf("%d %d %d",&x1,&y1,&r);
  scanf("%d %d %d %d",&x2,&y2,&x3,&y3);
  int32_t r2=r*r;
  int32_t x21=x1-x2;
  int32_t x31=x3-x1;
  int32_t y21=y1-y2;
  int32_t y31=y3-y1;
  if(x21<r||x31<r||y21<r||y31<r){
    printf("YES\n");
  }else{
    printf("NO\n");
  }
  if(x21*x21+y21*y21>r2||x31*x31+y21*y21>r2||x21*x21+y31*y31>r2||x31*x31+y31*y31>r2){
    printf("YES\n");  
  }else{
    printf("NO\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&x1,&y1,&r);
   ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d %d",&x2,&y2,&x3,&y3);
   ^