#include <stdio.h>
#include <stdlib.h>

int compare_int(const void *b,const void *a){
  if(*(long long*)a-*(long long*)b > 0)
    return 1;
  return -1;
}

long long max(long long a,long long b){
  if(a > b){
    return a;
  }
  return b;
}

int main(void){
  int N,M;
  scanf("%d%d",&N,&M);

  long long x[N],y[N],z[N];
  long long sum[N];
  for(int i = 0;i < N;i++){
    scanf("%lld%lld%lld",&x[i],&y[i],&z[i]);
  }

  long long array[N];
  long long ans = 0;
  for(int i = 0;i < 1<<3;i++){
    int sign[3];
    for(int j = 0;j < 3;j++){
      sign[j] = (i>>j)&1==1 ? 1:-1;
    }
    for(int j = 0;j < N;j++){
      array[j] = x[j]*sign[0]+y[j]*sign[1]+z[j]*sign[2];
    }
    qsort(array,N,sizeof(long long),compare_int);
    long long res = 0;
    for(int j = 0;j < M;j++){
      res += array[j];
    }
    ans = max(ans,res);
  }

  printf("%lld\n",ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&N,&M);
   ^
./Main.c:24:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld%lld",&x[i],&y[i],&z[i]);
     ^