#include<stdio.h>
#define mc 999999999
#define pc -1000000000

int main(){
  long long i,j,h,w,sh,sw,v,t=0,p,q;
  long long arr[512]={0};
  scanf("%lld%lld%lld%lld",&h,&w,&sh,&sw);
  if(h%sh==0 && w%sw==0){
    printf("No\n");return 0;
  }
  if(w%sw!=0){
  arr[0]=0;
  for(i=1;i<sw;i++){
    arr[i]=114514;
  }
  for(i=sw;i<=w;i++){
    arr[i]=arr[i-sw]-1;
  }
  printf("Yes\n");
  for(i=0;i<h;i++){
    for(j=1;j<=w;j++){
      if(j!=1){printf(" ");}
      printf("%lld",arr[j]-arr[j-1]);
    }
    printf("\n");
  }
  }
  else{
  arr[0]=0;
  for(i=1;i<sh;i++){
    arr[i]=114514;
  }
  for(i=sh;i<=h;i++){
    arr[i]=arr[i-sh]-1;
  }
  printf("Yes\n");
  for(i=1;i<=h;i++){
    for(j=1;j<=w;j++){
      if(j!=1){printf(" ");}
      printf("%lld",arr[i]-arr[i-1]);
    }
    printf("\n");
  }
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld%lld",&h,&w,&sh,&sw);
   ^