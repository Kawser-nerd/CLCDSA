#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int* calc(int *l,int n,int a){
  int *dp=(int *)calloc(1<<n,sizeof(int));
  dp[0]=1000000;
  for(int i=1;i<(1<<n);i++){
    int sum=0;
    int cost=-10;
    int j;
    for(j=0;j<n;j++){
      if((i>>j)&1){
	sum+=l[j];
	cost+=10;
      }
    }
    dp[i]=ABS(sum-a)+cost;
  }
  return dp;
}

void run(void){
  int n,a,b,c;
  scanf("%d%d%d%d",&n,&a,&b,&c);
  int l[8];
  int i,j,k;
  for(i=0;i<n;i++) scanf("%d",l+i);
  int *dpA=calc(l,n,a);
  int *dpB=calc(l,n,b);
  int *dpC=calc(l,n,c);
  int min=1000000;
  for(i=1;i<(1<<n);i++){
    for(j=1;j<(1<<n);j++){
      for(k=1;k<(1<<n);k++){
	if((i&j)==0 && (j&k)==0 && (k&i)==0){
	  min=MIN(min,dpA[i]+dpB[j]+dpC[k]);
	}
      }
    }
  }
  printf("%d\n",min);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:31:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d",&n,&a,&b,&c);
   ^
./Main.c:34:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",l+i);
                    ^