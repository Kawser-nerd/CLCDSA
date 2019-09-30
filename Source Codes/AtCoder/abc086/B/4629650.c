#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void){
  char a[9],b[9];
  scanf("%s %s",a,b);
  int num=atoi(strcat(a,b)),i;
  for(i=1;i<1000;i++){
    if(i*i==num) {
      puts("Yes");
      return 0;
    }
  }
  puts("No");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s %s",a,b);
   ^