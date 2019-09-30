#include <stdio.h>

int main(void){
  int N;
  scanf("%d",&N);

  int dist;
  int maxdist = 0;
  int num;
  for(int i = 2;i <= N;i++){
    printf("? 1 %d\n",i);
    fflush(stdout);
    scanf("%d",&dist);
    if(maxdist < dist){
      maxdist = dist;
      num = i;
    }
  }

  int ans = maxdist;
  for(int i = 2;i <= N;i++){
    if(i == num) continue;
    printf("? %d %d\n",num,i);
    fflush(stdout);
    scanf("%d",&dist);
    if(ans < dist) ans = dist;
  }

  printf("! %d\n",ans);
  fflush(stdout);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&dist);
     ^
./Main.c:25:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&dist);
     ^