#include<stdio.h>
#include<stdlib.h>
long long CO[100010];
long long R=1,C=1,H[2000010],N[2000010];
//????????MAX?
long long hyouka(long long a,long long b){
  if(C<b)return 1;
  if(C<a||b==0)return 0;
  return N[H[a]]<N[H[b]]?1:0;
}
//????
void hin(long long a){
  long long i=C++;
  for(N[H[0]=R]=a;hyouka(0,i/2);i/=2)H[i]=H[i/2];
  H[i]=R++;
}
//??????
long long hout(){
  long long rt=H[1],i,j=2,k=H[--C];
  for(i=1;hyouka(i,C);i=j)H[i]=H[j=i*2+1-hyouka(i*2,i*2+1)];
  H[j/2]=k;
  return rt;
}
long long i,id[400010],ta[400010],nt[400010],to[400010],co[400010],f[400010]={0};
void prls(long long v){
  long long i,j;
  for(i=0;i<v;i++){
    printf("%lld:",i);
    for(j=ta[i];j+1;j=nt[j])printf("%lld-%lld ",to[j],co[j]);
    printf("\n");
  }
  printf("\n");
}
void mkls(long long v,long long e,long long *a,long long *b,long long *c){
  long long i;
  for(i=0;i<v;i++)ta[i]=-1;
  for(i=0;i<e;i++){
    nt[i  ]=ta[to[i+e]=a[i]];
    nt[i+e]=ta[to[i  ]=b[i]];
    co[ta[b[i]]=i+e]=co[ta[a[i]]=i]=c[i];
  }
}
void dijk(long long v,long long mi){
  for(i=0;i<v;i++)CO[i]=1000000000;
  CO[mi]=0;
  while(f[mi]-1){
    f[mi]=1;
    for(i=ta[mi];i+1;i=nt[i]){
      if(CO[to[i]]>CO[mi]+co[i])hin(CO[id[R]=to[i]]=CO[mi]+co[i]);
    }
    while(f[mi]&&C-1)mi=id[hout()];
  }
}
int main(){
  long long n,m,i,j,a[200010],b[200010],c[200010];
  scanf("%lld",&n);
  for(i=0;i<n-1;i++){
    scanf("%lld %lld",&a[i],&b[i]);
    c[i]=1;
  }
  scanf("%lld",&m);
  for(i=0;i<m;i++){
    scanf("%lld %lld",&b[i+n-1],&c[i+n-1]);
    a[i+n-1]=0;
  }
  mkls(n+1,n+m-1,a,b,c);
  //prls(n+1);
  dijk(n+1,0);
  //for(i=0;i<n;i++)printf("%lld\n",CO[i+1]);
  for(i=0;i<m;i++){
    if(CO[b[i+n-1]]-c[i+n-1]){
      printf("No\n");
      return 0;
    }
  }
  for(i=1;i<n;i++){
    for(j=ta[i];j+1;j=nt[j]){
      if(to[j]==0)continue;
      if(labs(CO[i]-CO[to[j]])-1){
	printf("No\n");
	return 0;
      }
    }
  }      
  printf("Yes\n");
  for(i=0;i<n;i++)printf("%lld\n",CO[i+1]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:56:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&n);
   ^
./Main.c:58:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld",&a[i],&b[i]);
     ^
./Main.c:61:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&m);
   ^
./Main.c:63:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld",&b[i+n-1],&c[i+n-1]);
     ^