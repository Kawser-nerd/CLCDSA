#include <stdio.h>
#include <string.h>

int max(int a,int b){
  if(a > b){
    return a;
  }
  return b;
}

int min(int a,int b){
  if(a < b){
    return a;
  }
  return b;
}

int main(void){
  char S[100000];
  scanf("%s",S);

  char past = S[0];
  int ans = 0;
  int cnt = 0;
  for(int i = 1;i < strlen(S);i++){
    if(past != S[i]){
      ans = max(ans,min(i,strlen(S)-i+cnt));
      cnt = 1;
    }else{
      cnt++;
    }
    past = S[i];
  }

  if(ans == 0) ans = strlen(S);
  ans = max(ans,cnt);
  printf("%d\n",ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",S);
   ^