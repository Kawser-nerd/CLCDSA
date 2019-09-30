#include<stdio.h>
#include<string.h>
int main(){
  char s[201];
  int i,len,k;
  scanf("%s",s);
  len=strlen(s);
  if(len%2) s[len-1]=0;
  else {
    //s[len-1]=0;
    s[len-2]=0;
  }
  while(1){
    len=strlen(s);
    for(i=0;i<strlen(s)/2;i++){
      if(s[i]!=s[i+len/2]){
        k=0;
        break;
      }
      k=1;
    }
    if(k) break;
    else {
      //s[len-1]=0;
      s[len-2]=0;
    }
  }
  printf("%d",len);
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^