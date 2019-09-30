#include<stdio.h>
#include<string.h>

int main(void){
  char s[1001];
  int a[1001],i,j,cnt=0;
  scanf("%s",s);
  for(i=0;i<strlen(s);i+=cnt){
    cnt=0;
    for(j=i;s[i]==s[j];j++){
      cnt++;
    }
    printf("%c",s[i]);
    printf("%d",cnt);
  }
  printf("\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^