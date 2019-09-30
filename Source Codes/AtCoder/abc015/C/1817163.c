#include <stdio.h>
int main(void)
{
  int n,k;
  int i,j;
  int v;
  int t[5][5];
  int x[6][128]={1};
  scanf("%d%d",&n,&k);
  for(i=0;i<n;++i){
    for(j=0;j<k;++j){
      scanf("%d",&t[i][j]);
      for(v=0;v<128;++v){
        if(x[i][v]){
          x[i+1][v^t[i][j]]=1;
        }
      }
    }
  }
  if(x[n][0]) printf("%s\n", "Found");
  else printf("%s\n", "Nothing");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&k);
   ^
./Main.c:12:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",&t[i][j]);
       ^