#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int n;
  scanf("%d",&n);
  int *array=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++) scanf("%d",array+i);
  int64 ans=0;
  int t=0;
  int l=0;
  int r=0;
  while(r<n){
    while(r<n && (t&array[r])==0){
      t^=array[r];
      r++;
    }
    ans+=(int64)(r-l)*(r-l+1)/2;
    if(r==n) break;
    while(l<r && (t&array[r])!=0){
      t^=array[l];
      l++;
    }
    ans-=(int64)(r-l)*(r-l+1)/2;
  }
  printf("%lld\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:16:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",array+i);
                    ^