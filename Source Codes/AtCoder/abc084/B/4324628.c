#include<stdio.h>

int main(){
  char s[12];
  int a,b,i,ans=1;
  scanf("%d%d%s",&a,&b,s);
  for(i=0;i<a+b+1;i++){
    if(i==a){
      if(s[i]!='-'){
        ans=0;
        break;
      }
    }
    else{
      if(s[i]=='-'){
        ans=0;
        break;
      }
    }
  }
  puts(ans?"Yes":"No");
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%s",&a,&b,s);
   ^