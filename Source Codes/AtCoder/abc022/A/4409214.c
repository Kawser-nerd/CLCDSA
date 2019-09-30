#include <stdio.h>

int main(void){
  int N,S,T,W;
  scanf("%d%d%d%d",&N,&S,&T,&W);

  int ans = 0;
  int a;
  if(S <= W && W <= T) ans++;
  for(int i = 0;i < N-1;i++){
    scanf("%d",&a);
    W += a;
    if(S <= W && W <= T) ans++;
  }

  printf("%d\n",ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d",&N,&S,&T,&W);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^