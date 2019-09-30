#include<stdio.h>

#define POS(i,j) ((i)*n+(j))

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  int g[144];
  int i,j;
  for(i=0;i<n;i++) for(j=0;j<n;j++) g[POS(i,j)]=0;
  for(i=0;i<m;i++){
    int x,y;
    scanf("%d%d",&x,&y);
    x--;y--;
    g[POS(x,y)]=g[POS(y,x)]=1;
  }
  int max=1;
  for(i=1;i<(1<<n);i++){
    int t[12];
    int len=0;
    for(j=0;j<n;j++) if((i>>j)&1) t[len++]=j;
    int can=1;
    int k;
    for(j=0;j<len;j++){
      for(k=j+1;k<len;k++){
	if(g[POS(t[j],t[k])]==0) can=0;
      }
    }
    if(can && max<len) max=len;
  }
  printf("%d\n",max);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&x,&y);
     ^