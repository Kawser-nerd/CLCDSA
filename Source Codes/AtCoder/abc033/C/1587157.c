#include<stdio.h>
#include<string.h>

int f(char *p) {
  int ret = 1;
  for(int i = 0; *(p+i) != '\0'; i++) if(*(p+i) == '0') ret = 0;
  return ret;
}

int main() {
  char s[100001];
  int ans = 0;
  scanf("%s", s);
  char *p = strtok(s, "+");
  while(p != NULL) {
    if(f(p)) ans++;
    p = strtok(NULL, "+");
  }
  printf("%d\n", ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s);
   ^