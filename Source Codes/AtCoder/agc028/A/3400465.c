#include <stdio.h>

int gcd(int u, int v) {
  int r;
  while (0 != v) {
    r = u % v; u = v; v = r; /* swap */
  }
  return u;
}
int main(){
  // get input
  int N;
  int M;
  scanf("%d",&N);
  scanf("%d",&M);
  char S[1000000];
  char T[1000000];
  
  scanf("%s", S);
  scanf("%s", T);
  
  //puts(S);
  //puts(T);
  
  // get gcd of N,M
  int C = gcd(N, M);
  int n = N/C;
  int m = M/C;
  // test
  int test = 1;
  for(int i = 0; i < C; i++){
    if(S[n*i] != T[m*i]){
      test = 0;
      break;
    }
  }
  // print result
  if(test == 1){
    printf("%ld", (long)N*(long)M/(long)C);
  }
  else printf("-1");
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&M);
   ^
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", S);
   ^
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", T);
   ^