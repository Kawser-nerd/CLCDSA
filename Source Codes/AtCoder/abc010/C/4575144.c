#include <stdio.h>
#include <math.h>

double dist(int x,int y){
  return sqrt(x*x+y*y);
}

int main(void){
  int sx,sy,gx,gy;
  int T,V;
  scanf("%d%d%d%d",&sx,&sy,&gx,&gy);
  scanf("%d%d",&T,&V);

  int N;
  scanf("%d",&N);

  int ans = 0;
  int x,y;
  for(int i = 0;i < N;i++){
    scanf("%d%d",&x,&y);
    double cur = dist(sx-x,sy-y)+dist(gx-x,gy-y);
    if(cur <= T*V) ans = 1;
  }

  if(ans) printf("YES\n");
  else printf("NO\n");

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d",&sx,&sy,&gx,&gy);
   ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&T,&V);
   ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:20:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&x,&y);
     ^