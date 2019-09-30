#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int func(int m,int a,int b,const int *h,int n){
  int cnt=0;
  int i;
  for(i=0;i<n;i++){
    if((int64)b*m>=h[i]) continue;
    cnt+=(h[i]-b*m+(a-b)-1)/(a-b);
    if(cnt>m) return 0;
  }
  return 1;
}

void run(void){
  int n,a,b;
  scanf("%d%d%d",&n,&a,&b);
  int *h=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++) scanf("%d",h+i);
  int max=h[0];
  for(i=1;i<n;i++) max=MAX(max,h[i]);
  int l=0;
  int r=(max+b-1)/b;
  while(l+1<r){
    int m=(l+r)/2;
    if(func(m,a,b,h,n)){
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
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&n,&a,&b);
   ^
./Main.c:27:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",h+i);
                    ^