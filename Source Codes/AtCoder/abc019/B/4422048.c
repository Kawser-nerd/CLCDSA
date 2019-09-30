#include<stdio.h>
#include<string.h>

int main(){
  char s[1111],c;
  scanf("%s",s);
  int i,j,t;
  for(i=0;i<strlen(s);){
    c=s[i];
    t=0;
    for(j=i;j<strlen(s)&&s[i]==s[j];j++)t++;
    printf("%c%d",c,t);
    i+=t;
  }
  puts("");
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^