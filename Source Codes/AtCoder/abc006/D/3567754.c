#include<stdio.h>
#include<stdlib.h>

#define MIN(a,b) ((a)<(b)?(a):(b))

void run(void){
  int n;
  scanf("%d",&n);
  int *c=(int *)calloc(n,sizeof(int));
  int i;
  for(i=0;i<n;i++) scanf("%d",c+i);
  int *dp=(int *)calloc(n,sizeof(int));
  for(i=1;i<n;i++) dp[i]=n+1;
  dp[0]=-1;
  int max=0;
  for(i=0;i<n;i++){
    int l=0;
    int r=max+1;
    while(l+1<r){
      int m=(l+r)/2;
      if(dp[m]<c[i]){
	l=m;
      } else {
	r=m;
      }
    }
    dp[r]=c[i];
    if(r>max) max=r;
  }
  printf("%d\n",n-max);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:11:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",c+i);
                    ^