#include<stdio.h>

int n;
int k;
int t[5][5];

int dfs(int v,int x){
  int i;
  if(v==n){
    if(x==0)return 1;
    return 0;
  }
  for(i=0;i<k;i++){
    if(dfs(v+1,x^t[v][i])==1)return 1;
  }
}
  
  
int main(void)
{
  int i,j;

  scanf("%d%d",&n,&k);
  for(i=0;i<n;i++){
    for(j=0;j<k;j++){
      scanf("%d",&t[i][j]);
    }
  }
  

  if(dfs(0,0)==1){
    printf("Found\n");
  }else{
    printf("Nothing\n");
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:23:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&k);
   ^
./Main.c:26:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",&t[i][j]);
       ^