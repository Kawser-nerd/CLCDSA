#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

#define POS(i,j) ((i)*m+(j))

int cmp(const void *a,const void *b){
  return -*(int *)a+*(int *)b;
}

void run(void){
  int n,m,p,q,r;
  scanf("%d%d%d%d%d",&n,&m,&p,&q,&r);
  int *g=(int *)calloc(n*m,sizeof(int));
  while(r--){
    int x,y,z;
    scanf("%d%d%d",&x,&y,&z);
    x--;y--;
    g[POS(x,y)]=z;
  }
  int max=0;
  for(int i=1;i<(1<<n);i++){
    int c=0;
    int t=i;
    while(t>0){
      c+=t&1;
      t>>=1;
    }
    if(c!=p) continue;
    int score[18];
    for(int j=0;j<m;j++){
      score[j]=0;
      for(int k=0;k<n;k++){
	score[j]+=((i>>k)&1)*g[POS(k,j)];
      }
    }
    qsort(score,m,sizeof(int),cmp);
    int sum=0;
    for(int j=0;j<q;j++) sum+=score[j];
    max=MAX(max,sum);
  }
  printf("%d\n",max);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d%d",&n,&m,&p,&q,&r);
   ^
./Main.c:23:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&x,&y,&z);
     ^