#include <stdio.h>
#include <string.h>
int main(){
  char str[10];
  int i,N,sum=0,num;
  
  scanf("%s",str);
  
  for(i=0;i<strlen(str);i++){
    //printf("%d\n",str[i]-'0');
    sum += (str[i]-'0');
  }
  num = atoi(str);
  if( num%sum == 0 )printf("Yes\n");
  else printf("No\n");
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:9: warning: implicit declaration of function ‘atoi’ [-Wimplicit-function-declaration]
   num = atoi(str);
         ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",str);
   ^