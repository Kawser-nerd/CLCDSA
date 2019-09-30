#include<stdio.h>
#include<math.h>
double MAX(double a){return a<0?0:a;}
double MIN(double a,double b){return a<b?a:b;}
int main(){
  int i,j,k,n,a[1010],b[1010],c[1010]={};
  double d[1010][1010]={};
  scanf("%d %d %d %d %d",&a[0],&b[0],&a[1],&b[1],&n);
  n+=2;
  for(i=2;i<n;i++)scanf("%d %d %d",&a[i],&b[i],&c[i]);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++)d[i][j]=MAX(hypot(a[i]-a[j],b[i]-b[j])-c[i]-c[j]);
  }
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      for(k=0;k<n;k++)d[j][k]=MIN(d[j][k],d[j][i]+d[i][k]);
    }
  }
  printf("%.10lf\n",d[0][1]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d %d %d",&a[0],&b[0],&a[1],&b[1],&n);
   ^
./Main.c:10:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=2;i<n;i++)scanf("%d %d %d",&a[i],&b[i],&c[i]);
                   ^