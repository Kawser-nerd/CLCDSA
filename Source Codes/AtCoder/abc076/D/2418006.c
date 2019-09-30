#include<stdio.h>

double min(double x,double y){
  if(x<y) return x;
  else return y;
}

int main(){
  int n,t[100],sum[100],i,j;
  double dis=0,vl[40002],vv[40002],v[100];
  scanf("%d",&n);
  scanf("%d",&t[0]);
  sum[0]=t[0];
  for(i=1;i<n;i++){
    scanf("%d",&t[i]);
    sum[i]=sum[i-1]+t[i];
  }
  int max=sum[n-1];
  for(i=0;i<=2*max;i++)
    vl[i]=100.0;
  for(i=0;i<200;i++)
    vl[2*max-i]=(double)i/2;
  for(i=0;i<n;i++){
    scanf("%lf",&v[i]);
  }
  for(i=n-1;i>0;i--){
    for(j=2*sum[i-1];j<=2*sum[i];j++){
      vl[j]=min(vl[j],v[i]);}
    for(j=0;(double)j/2+v[i]<=100&&2*sum[i-1]-j>=0;j++)
      vl[2*sum[i-1]-j]=min(vl[2*sum[i-1]-j],v[i]+((double)j/2));
  }
  for(j=0;j<=2*sum[0];j++){
      vl[j]=min(vl[j],v[i]);}
  vv[0]=0.0;
  for(i=0;i<=2*max;i++){
    if(vv[i]<vl[i+1]) vv[i+1]=vv[i]+0.5;
    else if(vv[i]>vl[i+1]) vv[i+1]=vv[i]-0.5;
    else vv[i+1]=vv[i];
    dis+=vv[i+1]/2;
  }
  printf("%lf\n",dis);
  
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&t[0]);
   ^
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&t[i]);
     ^
./Main.c:24:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lf",&v[i]);
     ^