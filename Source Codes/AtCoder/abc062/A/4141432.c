#include <stdio.h>

int main(void){
  int x, y;
  int z = 0;
  int w = 0;
  scanf("%d %d", &x, &y);
  int a[7] = { 1, 3, 5, 7, 8, 10, 12};
  int b[4] = { 4, 6, 9, 11};
  for(int i = 0; i < 7; i++){
    if(a[i] == x) z = 1;
    if(a[i] == y) w = 1;
  }
  for(int i = 0; i < 4; i++){
    if(b[i] == x) z = 2;
    if(b[i] == y) w = 2;
  }

  if(z == w) printf("Yes\n");
  else printf("No\n");

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &x, &y);
   ^