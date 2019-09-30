#include<stdio.h>
long long R=1,C=1,H[2000010],N[2000010];
//????????MIN?
int hyouka(int a,int b){
  if(C<b)return 1;
  if(C<a||b==0)return 0;
  return N[H[a]]<N[H[b]]?1:0;
}
//????
void hin(long long a){
  int i=C++;
  for(N[H[0]=R]=a;hyouka(0,i/2);i/=2)H[i]=H[i/2];
  H[i]=R++;
}
//??????
int hout(){
  int rt=H[1],i,j=2,k=H[--C];
  for(i=1;hyouka(i,C);i=j)H[i]=H[j=i*2+1-hyouka(i*2,i*2+1)];
  H[j/2]=k;
  return rt;
}
int lb(int l,int r,long long n,long long *d){
  int m=(l+r)/2;
  if(l==r)return m;
  return n<=d[m]?lb(l,m,n,d):lb(m+1,r,n,d);
}
int ub(int l,int r,long long n,long long *d){
  int m=(l+r)/2;
  if(l==r)return m;
  return n<d[m]?ub(l,m,n,d):ub(m+1,r,n,d);
}
int main(){
  long long n,i,j,d[200010],ans=0,a,b,f[200010]={};
  scanf("%lld",&n);
  for(i=0;i<n;i++){
    scanf("%lld",&a);
    hin(a);
  }
  for(i=0;i<n;i++)d[i]=N[hout()];
  for(i=0;i<n;i++)f[i]=ub(0,n,d[i],d)-lb(0,n,d[i],d);
  for(i=n;i--;){
    b=lb(0,n,d[i],d);
    if(f[b]==0)continue;
    f[b]--;
    //printf("%d:",d[i]);
    for(j=0;j<32;j++){
      a=lb(0,n,(1LL<<(31-j))-d[b],d);
      //printf("%d ",a);
      if(a<n&&f[a]&&d[b]+d[a]==(1LL<<(31-j))){
	ans++;
	f[a]--;
	break;
      }
    }//printf("\n");
  }
  printf("%lld\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:34:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&n);
   ^
./Main.c:36:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&a);
     ^