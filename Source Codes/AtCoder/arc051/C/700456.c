#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MOD 1000000007
 
int compare (const void *a, const void *b) {
  long long x = *(long long *)a-*(long long *)b;
  if (x>0) return 1;
  else if (x==0) return 0;
  else return -1;
}
 
//void power(long long *x, int N, int A, int K) {
long long power(int A, int K) {
  //  int B = K/N, j;
  long long P = A, powA=1;
  while (K) {
    if (K&1) {
      powA *= P;
      powA %= MOD;
    }
    P *= P;
    P %= MOD;
    K >>= 1;
  }
  return powA;
  /*
  for (j=0;j<N;j++) {
    *(x+j) *= powA;
    *(x+j) %= MOD;
  }
  for (j=0;j<K%N;j++) {
    *(x+j) *= A;
    *(x+j) %= MOD;
    }
 */
}

void printing(long long *x, int N) {
  int i;
  for (i=0;i<N;i++) {
    printf("%lld ", *(x+i));
  }
  printf("\n");
}

int main() {
  int i, N, A, B, r, flag, dble[50], k, l=0, stack[50000];
  long long x[50], y[50], min;
  scanf("%d%d%d", &N, &A, &B);
  for (i=0;i<N;i++) {
    scanf("%lld", &x[i]);
    y[i] = x[i];
  }
 
  if (A==1) {
    qsort(x, N, sizeof(long long), compare);
    for (i=0;i<N;i++) printf("%lld\n", x[i]%MOD);
  } else {
    while (1) {
      flag = 1;
      for (i=0;i<N;i++) flag &= dble[i];
      if (flag) break;

      min = 2e18;
      for (i=0;i<N;i++) {
	if (min>y[i]) {
	  min = y[i];
	  k = i;
	}
      }
      y[k] *= A;
      //      y[k] %= MOD;
      stack[l++] = k;
      dble[k] = 1;
    }

    if (B<l-N) {
      for (i=0;i<B;i++) {
	x[stack[i]] *= A;
      }
      qsort(x, N, sizeof(long long), compare);
      for (i=0;i<N;i++) printf("%lld\n", x[i]%MOD);
    } else {
      int loop = (B-(l-N))/N;
      int rest = (B-(l-N))%N;
      int powA = power(A, loop);

      for (i=0;i<l-N;i++) {
	x[stack[i]] *= A;
	x[stack[i]] %= MOD;
      }
      for (i=0;i<N;i++) {
	x[i] *= powA;
	x[i] %= MOD;
      }
      for (i=0;i<rest;i++) {
	x[stack[l-N+i]] *= A;
	x[stack[l-N+i]] %= MOD;
      }
      for (i=rest;i<N;i++) {
	printf("%lld\n", x[stack[l-N+i]]);
      }
      for (i=0;i<rest;i++) {
	printf("%lld\n", x[stack[l-N+i]]);
      }
    }
  }

    /*    while (B--) {
      x[0] *= A;
      x[0] %= MOD;
      qsort(x, N, sizeof(long long), compare);
      //     printing(x, N);
      //      if (A*x[0]>=x[N-1]) break;
    }
    if (B>0) { power(x,N,A,B); r = B%N; }
    else r = 0;
  }
 
  for (i=r;i<N;i++) {
    printf("%lld\n", x[i]);
  }
  for (i=0;i<r;i++) {
    printf("%lld\n", x[i]);
  }
    */ 
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:51:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &N, &A, &B);
   ^
./Main.c:53:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld", &x[i]);
     ^