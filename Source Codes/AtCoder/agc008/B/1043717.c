#include<stdio.h>
int main(){
  long long mi=1e18,a=0,b=0,s=0,mx=-1e18;
  int n,m,i,d[100010],c=0,max=0;
  scanf("%d %d",&n,&m);
  for(i=0;i<n;i++){
    scanf("%d",&d[i]);
    if(d[i]>0)s+=d[i];
    if(d[i]<0)a+=d[i];
    if(d[i]>0)b+=d[i];
    if(i>=m){
      if(d[i-m]<0)a-=d[i-m];
      if(d[i-m]>0)b-=d[i-m];
    }
    if(i>=m-1){
      if(mx<a)mx=a;
      if(mi>b)mi=b;
    }//printf("%2d %2lld %2lld\n",d[i],a,b);
  }//printf("\n%d %lld %lld %lld\n",max,s,mx,mi);
  if(-mx>mi)s-=mi;
  else      s+=mx;
  printf("%lld\n",s);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&m);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&d[i]);
     ^