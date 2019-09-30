#include<stdio.h>
#include<stdlib.h>

#define POS(i,j) ((i)*(n+1)+(j))

void run(void){
  int n,d,x,y;
  scanf("%d%d%d%d",&n,&d,&x,&y);
  if(x<0) x=-x;
  if(y<0) y=-y;
  if(x%d!=0 || y%d!=0 || (x+y)/d>n || (n-(x+y)/d)%2!=0){
    printf("0\n");
    return;
  }
  x/=d;
  y/=d;
  double *comb=(double *)calloc((n+1)*(n+1),sizeof(double));
  comb[0]=1;
  int i,j;
  for(i=1;i<=n;i++){
    comb[POS(i,0)]=comb[POS(i-1,0)]*0.5;
    for(j=1;j<=i;j++) comb[POS(i,j)]=0.5*(comb[POS(i-1,j-1)]+comb[POS(i-1,j)]);
  }
  double ans=0;
  for(int i=x;i<=n-y;i+=2){
    ans+=comb[POS(n,i)]*comb[POS(i,(i-x)/2)]*comb[POS(n-i,(n-i-y)/2)];
  }
  printf("%.9lf\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d",&n,&d,&x,&y);
   ^