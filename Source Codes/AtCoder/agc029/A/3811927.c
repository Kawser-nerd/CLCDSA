#include <stdio.h>
#define MAX 200000
int main(void){
  long long a,b,i;
  char s[MAX + 2];
  scanf("%s",s);
  for(i = a = b = 0;i < MAX && s[i] != '\0';i++){
    a += (s[i] == 'W')*(b += (s[i] == 'B'));
  }
  printf("%lld\n",a);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^