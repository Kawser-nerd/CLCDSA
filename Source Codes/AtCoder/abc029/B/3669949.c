#include <stdio.h>
#include <string.h>

int main(void) {
  int cnt = 0;
  char s[13][11];
  for(int i=0; i<12; i++) {
    scanf("%s",s[i]);
    if((strchr(s[i],'r') != NULL)) cnt++;
  }
  printf("%d\n",cnt);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s[i]);
     ^