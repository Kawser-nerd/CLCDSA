#include <stdio.h>

int main(void){
  int N;
  scanf("%d",&N);

  int h[N];
  for(int i = 0;i < N;i++) scanf("%d",&h[i]);

  int ans = h[0];
  for(int i = 1;i < N;i++){
    if(h[i-1] <= h[i]) ans += h[i]-h[i-1];
  }

  printf("%d\n",ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:8:28: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int i = 0;i < N;i++) scanf("%d",&h[i]);
                            ^