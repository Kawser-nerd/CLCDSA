#include<stdio.h>
int main(){
  int n,i,j,d[2][100010]={};
  scanf("%d",&n);
  for(i=0;i<2;i++){
    for(j=0;j<n;j++)scanf("%d",&d[i][j]);
  }
  for(i=1;i<n;i++)d[0][  i  ]+=d[0][i-1];
  for(i=1;i<n;i++)d[1][n-i-1]+=d[1][n-i];
  //for(i=0;i<n;i++)printf("%2d %2d\n",d[0][i],d[1][i]);
  for(i=j=0;i<n;i++){
    if(j<d[0][i]+d[1][i])j=d[0][i]+d[1][i];
  }
  printf("%d\n",j);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:6:21: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(j=0;j<n;j++)scanf("%d",&d[i][j]);
                     ^