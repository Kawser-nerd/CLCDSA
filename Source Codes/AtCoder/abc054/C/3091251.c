#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

#define POS(i,j) ((i)*8+(j))

int calc(int k,int *c,int *used,int depth,int n){
  if(used[k]) return 0;
  if(depth==n-1) return 1;
  used[k]=1;
  int res=0;
  int i;
  for(i=0;i<n;i++){
    if(c[POS(k,i)]==0) continue;
    res+=calc(i,c,used,depth+1,n);
  }
  used[k]=0;
  return res;
}

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  int c[64]={};
  int i;
  for(i=0;i<m;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    a--;b--;
    c[POS(a,b)]=1;
    c[POS(b,a)]=1;
  }
  int used[8]={};
  int ans=calc(0,c,used,0,n);
  printf("%d\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:29:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:34:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^