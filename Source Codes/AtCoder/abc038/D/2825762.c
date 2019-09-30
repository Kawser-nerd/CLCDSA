#include<stdio.h>
int R=1,C=1,H[2000010],N[2000010],B[100010];
//????????MIN?
int hyouka(int a,int b){
  if(C<b)return 1;
  if(C<a||b==0)return 0;
  return N[H[a]]<N[H[b]]||(N[H[a]]==N[H[b]]&&B[H[a]]>B[H[b]])?1:0;
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
int lb(int l,int r,int n,int *d){
  int m=(l+r)/2;
  if(l==r)return m;
  return n<=d[m]?lb(l,m,n,d):lb(m+1,r,n,d);
}
int lis(int n,int *d){
  int r=0,i,s[100010]={d[0]};
  for(i=1;i<n;i++)s[r]<d[i]?(s[++r]=d[i]):(s[lb(0,r,d[i],s)]=d[i]);
  return r+1;
}
int main(){
  int n,a,i,d[100010];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d %d",&a,&B[R]);
    hin(a);
  }
  for(i=0;i<n;i++)d[i]=B[hout()];
  printf("%d\n",lis(n,d));
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:34:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:36:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&a,&B[R]);
     ^