#include<stdio.h>
#include<string.h>
int main(){
  char c[100],s[][5]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
  int i;
  scanf("%s",c);
  for(i=6;strncmp(c,s[6-i],3);i--);
  printf("%d\n",i%6);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",c);
   ^