#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_int(const void *a,const void *b){
  return *(long*)a-*(long*)b;
}

int main(void){
  char s[100000];
  scanf("%s",s);
  int sum[strlen(s)];
  int ans[strlen(s)],cnt = 0;
  for(int i = 0;i < strlen(s);i++) sum[i] = 0;
  for(int i = strlen(s)-1;i >= 0;i--){
    if(i == strlen(s)-1){
      if(s[i] == '+') sum[i] = 1;
      else if(s[i] == '-') sum[i] = -1;
      else ans[cnt++] = 0;
      continue;
    }
    if(s[i] == '+'){
      sum[i] += sum[i+1]+1;
    }else if(s[i] == '-'){
      sum[i] += sum[i+1]-1;
    }else{
      sum[i] = sum[i+1];
      ans[cnt++] = sum[i];
    }
  }

  qsort(ans,cnt,sizeof(int),compare_int);

  int res = 0;
  for(int i = 0;i < cnt;i++){
    if(i < cnt/2) res -= ans[i];
    else res += ans[i];
  }
  printf("%d\n",res);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^