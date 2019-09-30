#include<stdio.h>
#include<stdlib.h>
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
int g(int a,int b,int c){
  if(b<=a&&a<=c)return a;
  return a<b?b:c;
}
int main(){
  int n,i,j,t=0,nt,f[100010],a[100010],b[100010],d[2][100010],r[2]={};
  long long s[2]={};
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d %d",&a[i],&b[i]);
  for(i=0;i<n;i++)hin(-a[i]);
  for(i=0;i<n;i++)d[0][i]=hout()-1;
  R=C=1;
  for(i=0;i<n;i++)hin(b[i]);
  for(i=0;i<n;i++)d[1][i]=hout()-1;
  for(i=0;i<n;i++)f[i]=0;
  for(j=0;j<2;j++){
    for(i=0;i<n;i++)f[i]=0;
    r[0]=r[1]=t=0;
    for(i=j;i<n+j;i++){
      while(f[d[i%2][r[i%2]]])r[i%2]++;
      //printf("%d %d\n",a[d[i%2][r[i%2]]],b[d[i%2][r[i%2]]]);
      nt=g(t,a[d[i%2][r[i%2]]],b[d[i%2][r[i%2]]]);
      s[j]+=abs(nt-t);
      t=nt;
      f[d[i%2][r[i%2]]]=1;
    }
    s[j]+=abs(t);
  }
  printf("%lld\n",s[0]<s[1]?s[1]:s[0]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:30:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:31:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++)scanf("%d %d",&a[i],&b[i]);
                   ^