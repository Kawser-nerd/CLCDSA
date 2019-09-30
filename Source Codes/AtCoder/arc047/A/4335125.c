#include<stdio.h>
int main(){
  char s[111111];
  int n,l,i,ans=0,t=1;
  scanf("%d%d%s",&n,&l,s);
  for(i=0;i<n;i++){
    if(s[i]=='+'){
      if(t==l){
        t=1;
        ans++;
      }
      else t++;
    }
    else if(s[i]=='-'){
      t--;
    }
  }
  printf("%d\n",ans);
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%s",&n,&l,s);
   ^