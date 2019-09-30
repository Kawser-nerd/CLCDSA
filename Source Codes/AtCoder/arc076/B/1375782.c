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
int mitr(int v,int e,int *a,int *b,int *c){
  int i,r,n,s=0,mi,d[100010]={0};
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
  int n,i,j,k,l,a[400010],b[400010],c[400010],r=0,x[100010],y[100010];
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d %d",&x[i],&y[i]);
  for(k=0;k<2;k++){
    for(i=0;i<n;i++)hin(k==0?x[i]:y[i]);
    l=hout()-1;
    for(i=1;i<n;i++){
      j=hout()-1;
      a[r]=b[r+1]=j;
      b[r]=a[r+1]=l;//printf("%d %d %d\n",x[j]-x[l],j,l);
      c[r]=c[r+1]=(k==0?x[j]-x[l]:y[j]-y[l]);
      r+=2;
      l=j;
    }
    R=C=1;
  }
  //for(i=0;i<r;i++)printf("%d %d %d\n",a[i],b[i],c[i]);
  printf("%d\n",mitr(n,r,a,b,c));
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:42:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:43:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++)scanf("%d %d",&x[i],&y[i]);
                   ^