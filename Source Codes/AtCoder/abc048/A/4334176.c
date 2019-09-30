#include<stdio.h>
int main (){
char a[100],b[100],c[100];
  scanf ("%s%s%s",a,b,c);
  printf("A%cC",b[0]);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%s%s%s",a,b,c);
   ^