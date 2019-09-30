#include <stdio.h>
#include <stdlib.h>

typedef long long int llint;
const int M = 40;

int takebit(llint x, int m)
{
  return (x>>m)&1;
}

llint g(llint x, llint (*s)[2])
{
  llint r = 0;
  for(int m=0; m<M; m++) {
    r+=s[m][takebit(x,m)];
  }

  return r;
}

// kill before m-th
llint downzeromask(llint x, int m)
{
  return x&((llint)(-1)<<m);
}

// kill from m-th
llint upzeromask(llint x, int m)
{
  return x&(((llint)(1)<<m)-1);
}

int main(void)
{
  llint N, K;
  int n, m;
  llint *A, (*S)[2];
  llint s, Y, Kb, ans, new, Z;

  /* input */
  scanf("%lld%lld",&N,&K);
  A = malloc(sizeof(llint)*N);
  for(n=0;n<N;n++) {
    scanf("%lld",&(A[n]));
  }

  S = malloc(sizeof(llint)*N*2);
  Y = 0;
  for(m=0;m<M;m++) {
    s = 0;
    for(n=0;n<N;n++) {
      s += takebit(A[n],m);
    }
    S[m][0] = s<<m;
    S[m][1] = (N-s)<<m;
    if(2*s < N) {
      Y |= (llint)(1)<<m;
    }
  }
  
  Kb = K+1;
  ans = 0;
  for(m=0;m<M;m++) {
    if(takebit(Kb,m)==1) {
      Z = downzeromask(K,m+1) + upzeromask(Y,m);
      new = g(Z,S);
      if(new > ans) {
        ans = new;
      }
    }
  }

  printf("%lld\n",ans);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:42:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&N,&K);
   ^
./Main.c:45:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&(A[n]));
     ^