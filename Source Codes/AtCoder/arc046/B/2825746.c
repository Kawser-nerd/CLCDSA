#include<stdio.h>
int main(){
  int n,a,b;
  char s[2][100]={"Takahashi","Aoki"};
  scanf("%d %d %d",&n,&a,&b);
  if(n<=a){
    printf("%s\n",s[0]);
    return 0;
  }
  if(n==b+1){
    printf("%s\n",s[1]);
    return 0;
  }
  if(a==b){
    if(a==1)printf("%s\n",s[1-n%2]);
    else printf("%s\n",s[n%(a+1)?0:1]);
  }
  else printf("%s\n",a<b?s[1]:s[0]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&n,&a,&b);
   ^