#include <stdio.h>

int main(void){
  int l, h;
  scanf("%d %d", &l, &h);
  int n;
  scanf("%d", &n);
  int i;
  
  for(i = 0; i < n; i++){
    int a;
    scanf("%d", &a);
    if(a < l) printf("%d\n", l - a);
    else if(h < a) printf("-1\n");
    else printf("0\n");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &l, &h);
   ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &a);
     ^