#include <stdio.h>
int main(void){
char s[10];
  scanf("%s",&s);
  if(s[0]==s[1]&&s[1]==s[2]&&s[2]==s[3]){printf("Yes");return 0;}
    if(s[0]==s[1]&&s[1]==s[2]){printf("Yes");return 0;}
    if(s[1]==s[2]&&s[2]==s[3]){printf("Yes");return 0;}
  printf("No");
              
return 0;
} ./Main.c: In function �main�:
./Main.c:4:9: warning: format �%s� expects argument of type �char *�, but argument 2 has type �char (*)[10]� [-Wformat=]
   scanf("%s",&s);
         ^
./Main.c:4:3: warning: ignoring return value of �scanf�, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",&s);
   ^