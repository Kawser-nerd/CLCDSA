#include<stdio.h>
int main()
{
  int a ;
  scanf("%d", &a);

  if (a % 400 == 0) {
    printf("YES\n");
  } else if (a % 100 == 0) {
    printf("NO\n");
  } else if (a % 4 == 0) {
    printf("YES\n");
  } else
    printf("NO\n");

    return 0;

} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a);
   ^