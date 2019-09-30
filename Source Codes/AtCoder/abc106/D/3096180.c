#include<stdio.h>
int main(){
  int n,m,q,i,j,d[510][510]={};
  int s[510][510]={};
  scanf("%d %d %d",&n,&m,&q);
  while(m--){
    scanf("%d %d",&i,&j);
    d[i][j]++;
  }
  for(i=505;i--;){
    for(j=1;j<505;j++)s[i][j]=d[i][j]-s[i+1][j-1]+s[i+1][j]+s[i][j-1];
  }
  while(q--){
    scanf("%d %d",&i,&j);
    printf("%d\n",s[i][j]);
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&n,&m,&q);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&i,&j);
     ^
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&i,&j);
     ^