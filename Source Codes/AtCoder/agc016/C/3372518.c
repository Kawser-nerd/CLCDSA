#include<stdio.h>
#define mc 999999999
#define pc -1000000000

int main(){
  long long i,j,h,w,sh,sw,v,t=0,p,q;
  long long arr[512][512]={0};
  scanf("%lld%lld%lld%lld",&h,&w,&sh,&sw);
  if(h==sh && w==sw){
    printf("No\n");return 0;
  }
  if(sh==1 && sw==1){
    printf("No\n");return 0;
  }
  v=-(sh*sw);
  for(i=1;i<=h;i++){
    for(j=1;j<=w;j++){
      p=i%sh;
      if(p==0){p=sh;}
      q=j%sw;
      if(q==0){q=sw;}
      if(p==1 && q==1){
        arr[i][j]=mc;
        t+=mc;
      }
      else if(p==sh && q==sw){
        arr[i][j]=pc;
        t+=pc;
      }
      else{arr[i][j]=0;}
    }
  }
  if(t<=0){printf("No\n");return 0;}
  printf("Yes\n");
  for(i=1;i<=h;i++){
    for(j=1;j<=w;j++){
      if(j!=1){printf(" ");}
      printf("%lld",arr[i][j]);
    }
    printf("\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld%lld",&h,&w,&sh,&sw);
   ^