#include<stdio.h>
long long MIN(long long a,long long b){return a<b?a:b;}
long long MAX(long long a,long long b){return a<b?b:a;}
int ta[1010],to[1000010],nt[1000010],co[1000010],F[1010];
long long MF(int s,int t,int e,int min){
  if(s==t||min==0)return min;
  long long i,r;
  F[s]=1;
  for(i=ta[s];i+1;i=nt[i]){
    if(F[to[i]])continue;
    r=MF(to[i],t,e,MIN(min,co[i]));
    co[i]-=r;
    co[(i+e)%(2*e)]+=r;
    if(r)return r;
  }
  return 0;
}
//?????
//s??t??????????????v???e?a??b????c????????
long long maxf(int s,int t,int v,int e,int *a,int *b,int *c){
  long long i,f,r;
  for(i=0;i<v;i++)ta[i]=-1;
  for(i=0;i<e;i++){
    nt[i  ]=ta[to[i+e]=a[i]];
    nt[i+e]=ta[to[i  ]=b[i]];
    co[ta[a[i]]=i  ]=c[i];
    co[ta[b[i]]=i+e]=0;
  }
  for(f=0;r=MF(s,t,e,1000000000);f+=r){
    for(i=0;i<v;i++)F[i]=0;
  }
  return f;
}
int main(){
  int n,a[100010],b[100010],c[100010],d[100010],r=0,i,j;
  long long s=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&d[i]);
  for(i=1;i<=n;i++){
    a[r]=0;
    b[r]=i;
    c[r++]=MAX(0,d[i-1]);
    s+=c[r-1];
    a[r]=i;
    b[r]=n+1;
    c[r++]=MAX(0,-d[i-1]);
    for(j=i-1;j;j--){
      if(i%j==0){
	a[r]=i;
	b[r]=j;
	c[r++]=1e9;
      }
    }
  }//printf("%d\n",s);
  printf("%lld\n",s-maxf(0,n+1,n+2,r,a,b,c));
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:37:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:38:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++)scanf("%d",&d[i]);
                   ^