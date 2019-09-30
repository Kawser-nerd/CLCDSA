#include <stdio.h>

int main(){
  int h,w;
  scanf("%d%d", &h, &w);
  char c[h][w+1];
  int i;
  for(i=0;i<h;i++){
    scanf("%s", c[i]);
  }
  for(i=0;i<h;i++){
    printf("%s\n%s\n", c[i], c[i]);
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &h, &w);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", c[i]);
     ^