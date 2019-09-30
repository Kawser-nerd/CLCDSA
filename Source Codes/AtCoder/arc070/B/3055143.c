#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

#define POS(i,j) ((i)*k+(j))

int cmp(const void *a,const void *b){
  return *(int *)a-*(int *)b;
}

void run(void){
  int n,k;
  scanf("%d%d",&n,&k);
  int *a=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  qsort(a,n,sizeof(int),cmp);
  int *dp=(int *)malloc(sizeof(int)*k);
  int l=-1;
  int r=n;
  while(r-l>1){
    int m=(l+r)/2;
    for(i=0;i<k;i++) dp[i]=0;
    dp[0]=1;
    for(i=0;i<n;i++){
      if(i==m) continue;
      int j;
      for(j=k-1;j>=a[i];j--){
	if(dp[j-a[i]]==0) continue;
	dp[j]=1;
      }
    }
    for(i=k-1;dp[i]==0;i--);
    if(i+a[m]>=k){
      r=m;
    } else {
      l=m;
    }
  }
  printf("%d\n",l+1);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&k);
   ^
./Main.c:22:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",a+i);
                    ^