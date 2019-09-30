#include <stdio.h>
#include <string.h>

int main(void){
  char s[10];
  int ans = 0;
  for(int i = 0;i < 12;i++){
    scanf("%s",s);
    for(int j = 0;j < strlen(s);j++){
      if(s[j] == 'r'){
        ans++;
        break;
      }
    }
  }

  printf("%d\n",ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^