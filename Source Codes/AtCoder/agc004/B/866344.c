#include<stdio.h>

#define MIN(x,y) (((x)<(y))?(x):(y))

int main(void){
  int min[2000][2000];
  long long a[2000];
  long long N,x;
  long long sum,summin;
  int i,j,k;

  scanf("%lld%lld",&N,&x);
  for(i=0;i<N;i++) scanf("%lld",&a[i]);
  
  for(i=0;i<N;i++){
    min[0][i]=a[i];
    sum+=a[i];
  }
  summin=sum;

  for(i=1;i<N;i++){
    sum=0;
    for(j=0;j<N;j++){
      k=(j-i>=0)?j-i:N+j-i;
      min[i][j]=MIN(min[i-1][j],a[k]);
      sum+=min[i][j];

    }
    sum+=i*x;
    if(sum<summin) summin=sum;
  }
  printf("%lld\n",summin);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&N,&x);
   ^
./Main.c:13:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<N;i++) scanf("%lld",&a[i]);
                    ^