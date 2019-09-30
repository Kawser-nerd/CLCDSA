#include <stdio.h>

int main(void){
  char s[35];
  char x, y, z, w;
  fgets(s, 35, stdin);
  int c = 0;
  int f = 0;
  while(f != 2){
    if(s[c] == ' ' && f == 1) {
      z = s[c - 1];
      w = s[c + 1];
      f++;
    }
    if(s[c] == ' ' && f == 0) {
      x = s[c - 1];
      y = s[c + 1];
      f++;
    }
    c++;
  }
  if(x == y && z == w) printf("YES\n");
  else printf("NO\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(s, 35, stdin);
   ^