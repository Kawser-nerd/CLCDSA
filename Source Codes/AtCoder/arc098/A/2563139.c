#include<stdio.h>
int MIN(int a,int b){return a<b?a:b;}
int main(){
  int n,m=1e9,i,d[2][300010]={};
  char s[300010];
  scanf("%d %s",&n,s);
  for(i=0;i<n;i++)d[0][i+1]=d[0][i]+(s[i  ]=='W');
  for(i=n;i  ;i--)d[1][i-1]=d[1][i]+(s[i-1]=='E');
  for(i=0;i<n;i++)m=MIN(m,d[0][i]+d[1][i+1]);
  //for(i=0;i<=n;i++)printf("%d %d\n",d[0][i],d[1][i]);
  printf("%d\n",m);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %s",&n,s);
   ^