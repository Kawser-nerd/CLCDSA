#include <stdio.h>

int ax,ay,bx,by;

int f(int a,int b,int c,int d){
  return a*d-b*c > 0;
}

int g(int a,int b,int c,int d){
  return f(bx-ax,by-ay,a-ax,b-ay)^f(bx-ax,by-ay,c-ax,d-ay) && f(c-a,d-b,ax-a,ay-b)^f(c-a,d-b,bx-a,by-b);
}

int main(void){
  int N;
  int cnt = 0;
  scanf("%d%d%d%d",&ax,&ay,&bx,&by);
  scanf("%d",&N);


  int x[N+1],y[N+1];
  for(int i = 0;i < N;i++) scanf("%d%d",&x[i],&y[i]);
  x[N] = x[0]; y[N] = y[0];

  for(int i = 0;i < N;i++){
    cnt += g(x[i],y[i],x[i+1],y[i+1]);
  }

  printf("%d\n",1+cnt/2);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d",&ax,&ay,&bx,&by);
   ^
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:21:28: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int i = 0;i < N;i++) scanf("%d%d",&x[i],&y[i]);
                            ^