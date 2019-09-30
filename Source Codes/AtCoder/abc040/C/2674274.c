#include<stdio.h>
#define N 100000

int main(){
  int i,n;
  int a[N+1];
  int cost[N+1]={0};

  scanf("%d", &n);
  for(i=1;i<=n;i++)scanf("%d", &a[i]);

  cost[1]=0;
  cost[2]=abs(a[2]-a[1]);

  for(i=3;i<=n;i++){
    if( (cost[i-2]+abs(a[i]-a[i-2])) > (cost[i-1]+abs(a[i]-a[i-1])) )
      cost[i] = cost[i-1]+abs(a[i]-a[i-1]);
    else
      cost[i] = cost[i-2]+abs(a[i]-a[i-2]);
  }

  printf("%d\n",cost[n]);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:11: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
   cost[2]=abs(a[2]-a[1]);
           ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:10:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=1;i<=n;i++)scanf("%d", &a[i]);
                    ^