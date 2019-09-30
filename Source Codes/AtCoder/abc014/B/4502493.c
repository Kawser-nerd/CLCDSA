#include <stdio.h>

int main(void){
  int N,X;
  scanf("%d%d",&N,&X);
  
  int a[N];
  for(int i = 0;i < N;i++) scanf("%d",&a[i]);

  int ans = 0;
  for(int i = 0;i < N;i++){
    if((X >> i)&1) ans += a[i];
  }

  printf("%d\n",ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&N,&X);
   ^
./Main.c:8:28: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int i = 0;i < N;i++) scanf("%d",&a[i]);
                            ^