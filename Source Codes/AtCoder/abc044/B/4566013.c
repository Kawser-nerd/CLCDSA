#include <stdio.h>
#include <string.h>
#include <math.h>
int main(void){
  char s[110];
  scanf("%s",s);
  int i,n=strlen(s),cnt[200]={0};
  for(i=0;i<n;i++){
    int num=s[i]-'a';
    //printf("%d\n",num);
    cnt[num]++;
  }
  for(i=0;i<26;i++){
  //  printf("%d\n",cnt[i]);
    if(cnt[i]%2==1&&cnt[i]!=0){
      printf("No");
      return 0;
    }
  }
  printf("Yes");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^