#include <stdio.h>
#include <string.h>

int main(){
  char s[210] = {};
  int l;
  int flag;

  scanf("%s", s);
  l = strlen(s);//s[]??????

  for(int i = 1; i <= l/2; i++){
    s[l-(2*i-1)] = 0;
    s[l-(2*i  )] = 0;

    flag = 1;
    for(int j = 0; j <= strlen(s)/2 - 1; j++){
      if(s[j] != s[j+strlen(s)/2]){
        flag = 0;
        break;
      }
    }

    if(flag == 1){
      printf("%lu\n", strlen(s));
      return 0;
    }
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s);
   ^