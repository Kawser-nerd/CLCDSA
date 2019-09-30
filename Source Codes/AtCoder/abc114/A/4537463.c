#include <stdio.h>

int main()  {
  int age;
  scanf("%d", &age);
  switch(age) {
    case 3:
    case 5:
    case 7:
      printf("YES\n");
      break;
    default:
      printf("NO\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &age);
   ^