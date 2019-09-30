#include<stdio.h>
#include<string.h>

int main(){
  char a[111],b[111];
  int ans=0;
  scanf("%s%s",a,b);
  if(strlen(a)==strlen(b)){
    ans=strcmp(a,b);
  }
  else if(strlen(a)>strlen(b)){
    ans++;
  }
  else {
    ans--;
  }
  puts(ans?ans>0?"GREATER":"LESS":"EQUAL");
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s%s",a,b);
   ^