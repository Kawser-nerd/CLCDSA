#include<stdio.h>
#include<stdlib.h>

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

#define POS(i,j) ((i)*n+(j))

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  int *g=(int *)calloc(n*n,sizeof(int));
  int i,j,k;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      g[POS(i,j)]=(i==j?0:1000*300+1);
    }
  }
  while(m--){
    int a,b,t;
    scanf("%d%d%d",&a,&b,&t);
    a--;b--;
    g[POS(a,b)]=g[POS(b,a)]=t;
  }
  for(k=0;k<n;k++){
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
	g[POS(i,j)]=MIN(g[POS(i,j)],g[POS(i,k)]+g[POS(k,j)]);
      }
    }
  }
  int min=300*1000+1;
  for(i=0;i<n;i++){
    int max=0;
    for(j=0;j<n;j++) max=MAX(max,g[POS(i,j)]);
    min=MIN(min,max);
  }
  printf("%d\n",min);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:21:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&a,&b,&t);
     ^