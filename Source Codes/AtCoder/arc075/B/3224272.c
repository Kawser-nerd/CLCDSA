#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

int can(int k,int a,int b,int *h,int n){
  int64 cnt=0;
  int i;
  for(i=0;i<n;i++){
    if((int64)k*b>=h[i]) continue;
    int v=h[i]-k*b;
    int d=a-b;
    cnt+=(v+d-1)/d;
  }
  return cnt<=k;
}

void run(void){
  int n,a,b;
  scanf("%d%d%d",&n,&a,&b);
  int *h=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++) scanf("%d",h+i);
  int l=0;
  int r=1000000000;
  while(r-l>1){
    int m=(l+r)/2;
    if(can(m,a,b,h,n)){
      r=m;
    } else {
      l=m;
    }
  }
  printf("%d\n",r);
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&n,&a,&b);
   ^
./Main.c:23:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",h+i);
                    ^