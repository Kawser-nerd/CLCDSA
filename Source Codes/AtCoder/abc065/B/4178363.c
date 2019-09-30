#include <stdio.h>

int main(void){
  int n, i;
  scanf("%d", &n);
  int a[n];
  for(i = 0; i < n; i++) scanf("%d", &a[i]);
  int num = 0;
  int count = 0;
  i = 0;
  while(num < n){
    count = a[i];
    if(count == 2){
      num++;
      printf("%d\n", num);
      break;
    }else{
      i = count - 1;
      num++;
    }
    if(num == n) printf("-1\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:7:26: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i = 0; i < n; i++) scanf("%d", &a[i]);
                          ^