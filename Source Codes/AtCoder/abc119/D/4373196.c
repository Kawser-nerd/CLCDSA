#include<stdio.h>
long long MIN(long long a,long long b){return a<b?a:b;}
int lb(int l,int r,long long n,long long *d){
  int m=(l+r)/2;
  if(l==r)return m;
  return n<=d[m]?lb(l,m,n,d):lb(m+1,r,n,d);
}
int main(){
  long long n,m,q,i,j,x,ans,a[100010],b[100010],c[100010],d[100010];
  scanf("%lld %lld %lld",&n,&m,&q);
  for(i=0;i<n;i++)scanf("%lld",&a[i]);
  for(i=0;i<m;i++)scanf("%lld",&b[i]);
  a[n]=b[m]=c[n]=d[m]=1e18;
  
  for(i=0;i<n;i++){
    j=lb(0,m,a[i],b);
    c[i]=b[j]-a[i];
    if(j)c[i]=MIN(c[i],a[i]-b[j-1]);
  }
  for(i=0;i<m;i++){
    j=lb(0,n,b[i],a);
    d[i]=a[j]-b[i];
    if(j)d[i]=MIN(d[i],b[i]-a[j-1]);
  }
  //for(i=0;i<n;i++)printf("%lld ",c[i]);printf("\n");
  //for(i=0;i<m;i++)printf("%lld ",d[i]);printf("\n");
  while(q--){
    scanf("%lld",&x);
    i=lb(0,n,x,a);
    j=lb(0,m,x,b);
    ans=MIN(a[i]-x+c[i],b[j]-x+d[j]);//printf("%lld ",ans);
    if(i)ans=MIN(ans,x-a[i-1]+c[i-1]);
    if(j)ans=MIN(ans,x-b[j-1]+d[j-1]);
    printf("%lld\n",ans);
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld %lld %lld",&n,&m,&q);
   ^
./Main.c:11:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++)scanf("%lld",&a[i]);
                   ^
./Main.c:12:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<m;i++)scanf("%lld",&b[i]);
                   ^
./Main.c:28:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&x);
     ^