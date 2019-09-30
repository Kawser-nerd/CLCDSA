#include <stdio.h>

long long length[50],paty[50];

long long f(int N,long long X){
  if(N == 0){
    if(X <= 0) return 0;
    else return 1;
  }
  if(X <= 0) return 0;
  else if(X <= 1+length[N-1]) return f(N-1,X-1);
  else return paty[N-1]+1+f(N-1,X-2-length[N-1]);
}

int main(void){
  int N;
  long long X;

  scanf("%d%lld",&N,&X);

  length[0] = 1; paty[0] = 1;
  for(int i = 1;i < N;i++){
    length[i] = 3+2*length[i-1];
    paty[i] = 1+2*paty[i-1];
  }

  printf("%lld\n",f(N,X));
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%lld",&N,&X);
   ^