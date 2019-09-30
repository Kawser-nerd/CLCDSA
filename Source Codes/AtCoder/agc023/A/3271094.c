#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

int cmp(const void *a,const void *b){
  int64 p=*(int64 *)a;
  int64 q=*(int64 *)b;
  return p==q?0:p<q?-1:1;
}

void run(void){
  int n;
  scanf("%d",&n);
  int64 *sum=(int64 *)malloc(sizeof(int64)*(n+1));
  sum[0]=0;
  int i;
  for(i=1;i<=n;i++){
    int a;
    scanf("%d",&a);
    sum[i]=a+sum[i-1];
  }
  qsort(sum,n+1,sizeof(int64),cmp);
  int64 ans=0;
  i=0;
  while(i<n+1){
    int j=i+1;
    while(j<n+1&& sum[i]==sum[j]) j++;
    int d=j-i;
    ans+=(int64)d*(d-1)/2;
    i=j;
  }
  printf("%lld\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:20:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^