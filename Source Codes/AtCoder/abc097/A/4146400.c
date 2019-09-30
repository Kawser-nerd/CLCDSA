#include <stdio.h>

int main(void){
  int a[5] = { 0 };
  for(int i = 0; i < 4; i++) scanf("%d" , &a[i]);
  a[0] -= a[1];
  a[2] -= a[1];
  a[4] = a[0] - a[2];
  for(int i = 0; i < 5; i++){
    if(a[i] < 0) a[i] = -a[i];
  }
  if(a[4] <= a[3] || (a[0] <=a[3] && a[2] <= a[3])) printf("Yes\n");
  else printf("No\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:30: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int i = 0; i < 4; i++) scanf("%d" , &a[i]);
                              ^