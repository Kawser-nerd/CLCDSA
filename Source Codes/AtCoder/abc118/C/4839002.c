#include <stdio.h>

long long gcd(long long x,long long y){
    if(y == 0) return x;
    return gcd(y,x%y);
}

int main(void){
  int N;
  scanf("%d",&N);

  int A[N];
  for(int i = 0;i < N;i++) scanf("%d",&A[i]);

  int ans = A[0];
  for(int i = 1;i < N;i++){
    ans = gcd(A[i],ans);
  }

  printf("%d\n",ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:13:28: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int i = 0;i < N;i++) scanf("%d",&A[i]);
                            ^