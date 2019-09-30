#include<stdio.h>
int main(){
  int n,p,m=0,i,t,sum=0;
  char s[1111][22];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s%d",s[i],&p);
    sum+=p;
    if(m<p){
      m=p;
      t=i;
    }
  }
  printf("%s\n",m*2>sum?s[t]:"atcoder");
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%d",s[i],&p);
     ^