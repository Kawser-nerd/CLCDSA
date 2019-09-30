#include <stdio.h>

int main(void){
  int N;
  int ans = 0;
  long long a;
  scanf("%d",&N);

  for(int i = 0;i < N;i++){
    scanf("%lld",&a);
    while(a%2 == 0){
      a /= 2;
      ans++;
    }
  }

  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&a);
     ^