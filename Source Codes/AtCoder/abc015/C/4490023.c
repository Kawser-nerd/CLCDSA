#include <stdio.h>

int N,K;
int data[5][5];
int flag = 0;

void dfs(int depth,int res){
  if(depth == N){
    if(!res) flag = 1;
    return;
  }
  for(int i = 0;i < K;i++)
    dfs(depth+1,res^data[depth][i]); 
}


int main(void){
  scanf("%d%d",&N,&K);

  for(int i = 0;i < N;i++){
    for(int j = 0;j < K;j++){
      scanf("%d",&data[i][j]);
    }
  }

  dfs(0,0);

  if(flag) printf("Found\n");
  else printf("Nothing\n");

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&N,&K);
   ^
./Main.c:22:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",&data[i][j]);
       ^