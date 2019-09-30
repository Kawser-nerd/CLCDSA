#include <stdio.h>

int main(){
  int n, x;
  int i, a, y;
  unsigned long long int r;
  scanf("%d%d", &n, &x);
  r = 0;
  y = x;
  for(i=0;i<n;i++){
    scanf("%d",&a);
    if(y < a){
      r += a - y;
      y = x - y;
    }
    else y = x - a;
  }
  printf("%llu\n", r);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &n, &x);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^