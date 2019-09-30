#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare_char_ao(const void *a, const void *b){
  return *(char *)a - *(char *)b;
}

int compare_char_do(const void *a, const void *b){
  return *(char *)b - *(char *)a;
}

int main(){
  char s[110] = {};
  char t[110] = {};

  scanf("%s %s", s, t);
  int ls = strlen(s), lt = strlen(t);

  qsort(s, ls, sizeof(char), compare_char_ao);
  qsort(t, lt, sizeof(char), compare_char_do);

  if(s[0] < t[0]){
    printf("Yes\n");
  }else if(ls < lt && s[ls-1] == s[0] && s[0] == t[0] && t[0] == t[ls-1]){
    printf("Yes\n");
  }else{
    printf("No\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s %s", s, t);
   ^