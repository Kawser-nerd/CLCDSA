#include<stdio.h>
int R=1,C=1,H[2000010],N[2000010];
//????????MIN?
int hyouka(int a,int b){
  if(C<b)return 1;
  if(C<a||b==0)return 0;
  return N[H[a]]<N[H[b]]?1:0;
}
//????
void hin(int a){
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
long long mitr(int v,int e,int *a,int *b,int *c){
  long long i,r,n,s=0,mi,d[100010]={0};
  int p[100010]={0};
  for(i=0;i<e;i++)hin(c[i]);
  for(i=0;i<e;i++){
    mi=hout()-1;
    for(r=++a[mi];p[r];r=p[r]);
    for(;n=p[a[mi]];a[mi]=n)p[a[mi]]=r;
    for(r=++b[mi];p[r];r=p[r]);
    for(;n=p[b[mi]];b[mi]=n)p[b[mi]]=r;
    if(a[mi]-b[mi]){
      s+=c[mi];
      d[a[mi]]<d[b[mi]]?(p[a[mi]]=b[mi]):(p[b[mi]]=a[mi]);
      if(d[a[mi]]==d[b[mi]])d[a[mi]]++;
    }
  }
  return s;
}
int main(){
  int n,m,i,a[300010],b[300010],c[300010];
  scanf("%d %d",&n,&m);
  for(i=0;i<n;i++){
    a[i]=0;
    b[i]=i+1;
    scanf("%d",&c[i]);
  }
  for(i=0;i<m;i++)scanf("%d %d %d",&a[i+n],&b[i+n],&c[i+n]);
  printf("%lld\n",mitr(n+1,m+n,a,b,c));
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:42:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&m);
   ^
./Main.c:46:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&c[i]);
     ^
./Main.c:48:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<m;i++)scanf("%d %d %d",&a[i+n],&b[i+n],&c[i+n]);
                   ^