#include <stdio.h>
#include <string.h>
int main(){
  char str[3];
  int sum,i;
  scanf("%s",str);
  
  for(i=0;i<strlen(str);i++){
    sum += (str[i]-'0');
  }
  
  printf("%d\n",sum);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",str);
   ^