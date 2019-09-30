#include <stdio.h>
#include <string.h>
int main() {
  int a;
  int b;
  int age;
  scanf("%d",&age);
  if (age == 1)	{
    printf("Hello World\n");
  } else {
    scanf("%d %d",&a,&b);
    printf("%d\n",a+b);
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&age);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&a,&b);
     ^