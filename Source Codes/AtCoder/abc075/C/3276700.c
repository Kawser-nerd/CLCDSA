#include<stdio.h>

#define POS(i,j) ((i)*n+(j))

int connected(int *g,int n){
  int q[50];
  int used[50];
  int i;
  for(i=0;i<n;i++) used[i]=0;
  int front=0,last=0;
  q[last++]=0;
  used[0]=1;
  while(front<last){
    int v=q[front++];
    for(i=0;i<n;i++){
      if(g[POS(v,i)] && !used[i]){
	q[last++]=i;
	used[i]=1;
      }
    }
  }
  return last==n;
}

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  int g[2500];
  int i,j;
  for(i=0;i<n*n;i++) g[i]=0;
  for(i=0;i<m;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    a--;b--;
    g[POS(a,b)]=1;
    g[POS(b,a)]=1;
  }
  int cnt=0;
  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      if(g[POS(i,j)]){
	g[POS(i,j)]=g[POS(j,i)]=0;
	cnt+=connected(g,n);
	g[POS(i,j)]=g[POS(j,i)]=1;
      }
    }
  }
  printf("%d\n",m-cnt);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:27:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:33:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^