#include<stdio.h>
long long MAX(long long a,long long b){return a<b?b:a;}
long long MIN(long long a,long long b){return a<b?a:b;}
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
int ub(int l,int r,long long n,long long *d){
  if(n<0)return 0;
  int m=(l+r)/2;
  if(l==r)return m;
  return n<d[m]?ub(l,m,n,d):ub(m+1,r,n,d);
}
long long D[200010];
int main(){
  int n,i,j;
  long long m,s[100010],t,max=0,d[100010],v,a[100010],b[100010];
  scanf("%d %lld",&n,&m);
  for(i=0;i<n;i++)scanf("%lld %lld",&a[i],&b[i]);
  if(n<=30){
    for(i=0;i<(1<<(n/2));i++){
      s[R]=t=0;
      for(j=0;j<n/2;j++){
	if(i&(1<<j)){
	  s[R]+=a[j];
	  t+=b[j];
	}
      }
      hin(t);
    }
    for(i=0;i<(1<<(n/2));i++){
      j=hout();
      d[i]=N[j];
      D[i]=s[j];
      if(i)D[i]=MAX(D[i],D[i-1]);
    }
    /*for(i=0;i<(1<<(n/2));i++){
      if(d[i]<=m)printf("%3lld %3lld\n",d[i],D[i]);
    }
    printf("\n");//*/
    for(i=0;i<(1<<((n+1)/2));i++){
      for(j=v=t=0;j<(n+1)/2;j++){
	if(i&(1<<j)){
	  v+=a[j+n/2];
	  t+=b[j+n/2];
	}
      }//if(t<=m)printf("%3lld %3lld\n",v,t);
      j=ub(0,1<<(n/2),m-t,d);//if(j)printf("!!%d %lld\n",j,D[j-1]+v);
      if(j)max=MAX(D[j-1]+v,max);
    }
    printf("%lld\n",max);
    return 0;
  }
  for(i=0;i<n;i++){
    if(b[i]>1000)goto END;
  }
  for(i=0;i<n;i++){
    for(j=n*1000;j--;){
      D[j+b[i]]=MAX(D[j+b[i]],D[j]+a[i]);
    }
  }
  printf("%lld\n",D[m]);
  return 0;
  END:;
  for(i=1;i<n*1000;i++)D[i]=1e18;
  for(i=D[0]=0;i<n;i++){
    for(j=n*1000;j--;){
      D[j+a[i]]=MIN(D[j+a[i]],D[j]+b[i]);
    }
  }
  for(j=0;j<n*1000;j++){
    if(D[j]>m)continue;
    v=j;
  }
  printf("%lld\n",v);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:34:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %lld",&n,&m);
   ^
./Main.c:35:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++)scanf("%lld %lld",&a[i],&b[i]);
                   ^