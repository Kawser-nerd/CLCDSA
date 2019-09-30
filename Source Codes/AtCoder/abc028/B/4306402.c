#include <stdio.h>
#include<string.h>

int main() {
  int i,a[6]={};
  char s[111];
  scanf("%s",s);
  for(i=0;i<strlen(s);i++){
    a[s[i]-65]++;
  }
  printf("%d %d %d %d %d %d\n",a[0],a[1],a[2],a[3],a[4],a[5]);
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^