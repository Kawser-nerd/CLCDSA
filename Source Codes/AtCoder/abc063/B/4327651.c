#include<stdio.h>
#include<string.h>

int main(){
  int a[26]={},i;
  char s[30];
  scanf("%s",s);
  for(i=0;i<strlen(s);i++){
    a[s[i]-97]++;
    if(a[s[i]-97]>1){
      i=0;
      break;
    }
  }
  puts(i?"yes":"no");
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^