#include <stdio.h>
#include <string.h>
int main(){
  char s[11] = {0};
  char ans[11] = {0};
  int ans_cnt = 0;

  scanf("%s", s);

  for(int cnt = 0; cnt < strlen(s); cnt++){
    if(s[cnt] == '0' || s[cnt] == '1'){
      ans[ans_cnt] = s[cnt];
      ans_cnt++;
    }else{
      if(ans_cnt > 0){
	ans_cnt--;
	ans[ans_cnt] = '\0';
      }else{
	// do nothing
      }
    }
  }

  printf("%s", ans);

  printf("\n");
  
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s);
   ^