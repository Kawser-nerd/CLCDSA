#include <stdio.h>
#include <string.h>

int main(void){
  char s[100];
  scanf("%s",s);

  int cnt[6] = {0,0,0,0,0,0};
  for(int i = 0;i < strlen(s);i++){
    cnt[s[i]-'A']++;
  }
  for(int i = 0;i < 5;i++){
    printf("%d ",cnt[i]);
  }
  printf("%d\n",cnt[5]);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^