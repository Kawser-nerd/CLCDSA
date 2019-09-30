#include <stdio.h>

int main(){
  int n,m;
  scanf("%d %d\n",&n,&m);
  int food[m];
  int num;
  int like;
  for(int i = 0; i < m; ++i) food[i] = 0;
  for(int i = 0; i < n; ++i){
    scanf("%d",&num);
    for(int j = 0; j < num; ++j){
      scanf("%d",&like);
      food[like-1]++;
    }
    scanf("\n");
  }
  int like_num = 0;
  for(int i = 0; i < m; ++i) if(food[i] == n) like_num++;
  printf("%d\n",like_num);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d\n",&n,&m);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&num);
     ^
./Main.c:13:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",&like);
       ^
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("\n");
     ^