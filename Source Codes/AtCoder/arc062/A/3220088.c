#include<stdio.h>

typedef long long int int64;

void run(void){
  int n;
  scanf("%d",&n);
  int64 x,y;
  scanf("%lld%lld",&x,&y);
  int i;
  for(i=1;i<n;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    int64 nx=(x+a-1)/a*a;
    int64 ny=nx/a*b;
    if(nx<x || ny<y) {
      ny=(y+b-1)/b*b;
      nx=ny/b*a;
    }
    x=nx;
    y=ny;
  }
  printf("%lld\n",x+y);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&x,&y);
   ^
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^