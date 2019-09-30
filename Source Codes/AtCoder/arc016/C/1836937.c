#include<stdio.h>
void prib(int a,int k){while(k--)printf("%d",(a>>k)%2);}
double MIN(double a,double b){return a<b?a:b;}
int main(){
  int n,m,r[20],a[20][20],p[20][20],c[20],i,j,k;
  double s,d[2010]={};
  scanf("%d %d",&n,&m);
  for(i=0;i<(1<<n);i++)d[i]=1e9;
  for(i=0;i<m;i++){
    scanf("%d %d",&r[i],&c[i]);
    for(j=0;j<r[i];j++){
      scanf("%d %d",&a[i][j],&p[i][j]);
      a[i][j]--;
    }
  }
  n=1<<n;
  d[n-1]=0;
  while(n--){
    for(i=0;i<m;i++){
      s=c[i];
      k=100;
      for(j=0;j<r[i];j++){
	if(n&(1<<a[i][j]))k-=p[i][j];
	else              s+=d[n|(1<<a[i][j])]*(p[i][j]/100.0);
      }
      d[n]=MIN(d[n],k?100.0*s/k:1e9);
    }
    //prib(n,5);
    //printf(" %lf\n",d[n]);
  }
  printf("%lf\n",d[0]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&m);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&r[i],&c[i]);
     ^
./Main.c:12:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d %d",&a[i][j],&p[i][j]);
       ^