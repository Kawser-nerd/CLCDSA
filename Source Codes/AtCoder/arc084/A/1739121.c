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
int lb(int l,int r,int n,int *d){
  int m=(l+r)/2;
  if(l==r)return m;
  return n<=d[m]?lb(l,m,n,d):lb(m+1,r,n,d);
}
int main(){
  int a[3][100010],n,i,j;
  long long d[3][100010],s=0,b[3][100010]={};
  scanf("%d",&n);
  for(i=0;i<3;i++){
    for(j=0;j<n;j++){
      scanf("%d",&a[i][j]);
      hin(a[i][j]);
    }
    for(j=0;j<n;j++)a[i][j]=N[hout()];
    //for(j=0;j<n;j++)printf("%d ",a[i][j]);printf("\n");
    R=C=1;
  }
  for(i=1;i<3;i++){
    for(j=0;j<n;j++)d[i][j]=lb(0,n,a[i][j],a[i-1]);
    for(j=0;j<n;j++){
      b[i][j]+=d[i][j];
      b[i][j+1]+=b[i][j];
    }
    // for(j=0;j<n;j++)printf("!%lld\n",b[i][j]);
    //for(j=0;j<n;j++)printf("%lld ",d[i][j]);printf("\n");
  }
  for(i=s=0;i<n;i++)s+=b[1][d[2][i]-1];
  printf("%lld\n",s);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:30:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:33:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",&a[i][j]);
       ^