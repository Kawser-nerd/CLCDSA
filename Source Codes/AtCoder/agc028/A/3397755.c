#include <stdio.h>
#include <stdlib.h>

int main(void){
  
  int N, M;
  int temp;
  int n, m;
  int r;
  int i = 0, k = 0;
  int l = 0;

  scanf("%d %d", &N, &M);

  char *S, *T;

  S = malloc(100000);
  T = malloc(100000);

  scanf("%s %s", S, T);

  n = N, m = M;

  if(n < m){
    temp = n;
    n = m;
    m = temp;
  }

  r = n % m;
  while(r != 0){
    n = m;
    m = r;
    r = n % m;
  }

  while(i < N && k < M){
    if(S[i] == T[k]){
      l++;
      i = i + (N / m);
      k = k + (M / m);
    }else{
      break;
    }
  }

  if(l == m){
    printf("%ld\n",(long) N * M / m);
  }else{
    printf("-1\n");
  }

  free(S);
  free(T);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &N, &M);
   ^
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s %s", S, T);
   ^