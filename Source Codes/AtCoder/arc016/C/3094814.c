#include<stdio.h>
#include<stdlib.h>

#define POS(i,j) ((i)*10+(j))

const double ini=-1.0;
double *dp=NULL;
int n,m;
int c[4];
int cost[4];
int idol[40];
int prob[40];

double calc(int bit){
  if(dp[bit]!=ini) return dp[bit];
  double local=100*3000*10;
  int i,j;
  for(i=0;i<m;i++){
    int p=0;
    double e=cost[i];
    for(j=0;j<c[i];j++){
      if((bit>>idol[POS(i,j)])&0x01){
	e+=(double)prob[POS(i,j)]/100*calc(bit^(1<<idol[POS(i,j)]));
      } else {
	p+=prob[POS(i,j)];
      }
    }
    if(p==100) continue;
    e=e*100/(100-p);
    if(e<local) local=e;
  }
  dp[bit]=local;
  return local;
}

void run(void){
  scanf("%d%d",&n,&m);
  int i,j;
  for(i=0;i<m;i++){
    scanf("%d%d",c+i,cost+i);
    for(j=0;j<c[i];j++){
      scanf("%d%d",idol+POS(i,j),prob+POS(i,j));
      idol[POS(i,j)]--;
    }
  }
  dp=(double *)malloc(sizeof(double)*(1<<n));
  for(i=0;i<(1<<n);i++) dp[i]=ini;
  dp[0]=0;
  double ans=calc((1<<n)-1);
  printf("%.9lf\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:37:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:40:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",c+i,cost+i);
     ^
./Main.c:42:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d%d",idol+POS(i,j),prob+POS(i,j));
       ^