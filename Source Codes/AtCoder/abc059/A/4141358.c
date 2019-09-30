#include <stdio.h>
#include <ctype.h>

int main(void){
  char s[35];
  char ans[4];
  fgets(s, 35, stdin);
  ans[0] = s[0];
  ans[3] = '\0';
  int c = 0;
  int f = 0;
  while(f != 2){
    if(s[c] == ' ' && f == 1) {
      ans[2] = s[c + 1];
      f++;
    }
    if(s[c] == ' ' && f == 0) {
      ans[1] = s[c + 1];
      f++;
    }
    c++;
  }
  for(int i = 0; i < 3; i++){
    ans[i] = toupper(ans[i]);
  }
  printf("%s\n", ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(s, 35, stdin);
   ^