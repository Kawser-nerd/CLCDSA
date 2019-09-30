#include <stdio.h>
int main(){
  int a,b,c,x;
  scanf("%d%d%d%d",&a,&b,&c,&x);
  int ans = 0;
  int i,j;
  for(i=0;i<=a;i++){
    for(j=0;j<=b;j++){
      int tmp = i * 500 + j * 100;
      if (x - tmp >= 0 && x - tmp <= c * 50){
        ans++;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d",&a,&b,&c,&x);
   ^