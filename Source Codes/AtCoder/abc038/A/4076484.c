#include <stdio.h>
int main() {
  char s[51];
  int i;
  scanf("%s", s);
  for (i=0; s[i]!=0; i++);
  if (s[i-1]=='T') printf("YES\n");
  else printf("NO\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s);
   ^