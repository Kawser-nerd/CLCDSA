#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int main(void){
  char a[10],b[10];
  scanf("%s %s",a,b);
  strcat(a,b);
  int ab=atoi(a);
  for(int i=1;i<400;i++){
    if(i*i==ab) {printf("Yes");return 0;}
  }
  printf("No");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s %s",a,b);
   ^