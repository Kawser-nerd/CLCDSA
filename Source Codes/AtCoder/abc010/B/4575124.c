#include <stdio.h>

int main(void){
  int N;
  scanf("%d",&N);

  int a;
  int ans = 0;
  for(int i = 0;i < N;i++){
    scanf("%d",&a);
    while(1){
      if(a == 1) break;
      if(a%2 == 0 || a%3 == 2){
        a--;
        ans++;
        continue;
      }
      break;
    }
  }

  printf("%d\n",ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^