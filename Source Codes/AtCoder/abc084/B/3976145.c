#include <stdio.h>

int main(void){
  int a, b, i;
  char s[100];
  scanf("%d%d", &a, &b);
  scanf("%s", &s);
  int flag = 0;
  for(i = 0; i < a; i++){
    if(s[i] < '0' || '9' < s[i]) flag = 1;
  }
  if(s[a] != '-') flag = 1;
  for(i = a + 1; i < a + b + 1; i++){
    if(s[i] < '0' || '9' < s[i]) flag = 1;
  }
  
  if(flag) printf("No\n");
  else printf("Yes\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:9: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[100]’ [-Wformat=]
   scanf("%s", &s);
         ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &a, &b);
   ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", &s);
   ^