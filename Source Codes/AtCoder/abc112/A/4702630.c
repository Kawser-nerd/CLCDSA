#include <stdio.h>

int main() {
  int n;
  scanf("%d",&n);
  if (n == 1) {
    printf("Hello World\n");
  }
  if (n == 2) {
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d\n",a+b);
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&a,&b);
     ^