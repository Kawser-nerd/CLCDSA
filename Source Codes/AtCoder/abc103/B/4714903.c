#include <stdio.h>
#include <string.h>
#define LEN 103

void rot(char *str, int n) {
  char tmp = str[n-1];
  int i;
  for(i = 0; i < n-1; ++i) {
    str[n-1-i] = str[n-2-i];
  }
  str[0] = tmp;
}

int main(void)
{
  int i, len, flag = 0;
  char s1[LEN], s2[LEN];
  scanf("%s", s1); scanf("%s", s2);
  len = strlen(s1);
  
  for(i = 0; i < len; ++i) {
    if(strcmp(s1, s2) == 0) { flag = 1; break; }
    rot(s1, len);
    if(strcmp(s1, s2) == 0) { flag = 1; break; }
  }
  if(flag == 1) { printf("Yes\n"); } else { printf("No\n"); }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s1); scanf("%s", s2);
   ^
./Main.c:18:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s1); scanf("%s", s2);
                    ^