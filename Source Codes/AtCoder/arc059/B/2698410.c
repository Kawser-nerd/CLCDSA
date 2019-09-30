#include<stdio.h>
#include<string.h>

int main(){
  int n,i,flag=0;
  char s[110000];
  scanf("%s",s);
  n=strlen(s);
  for(i=0;i<n-2;i++){
    if(s[i]==s[i+1]){
      flag=1;
      break;
    }
    else if(s[i]==s[i+2]){
      flag=2;
      break;
    }
  }
  if(s[i]==s[i+1])
    flag=1;
  if(flag)
    printf("%d %d\n",i+1,i+1+flag);
  else
    printf("-1 -1\n");
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^