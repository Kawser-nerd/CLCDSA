#include<stdio.h>
int R=1,C=1,H[2000010],N[2000010];
//????????MAX?
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
int lb(int l,int r,long long n,int *d){
  if(n>(1<<29))return r;
  while(l-r){
    int m=(l+r)/2;
    n<=d[m]?(r=m):(l=m+1);
  }
  return l;
}

int n,i,j,k,s=0,c,a[200010],b[200010],d[200010];
int main(){
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%lld",&a[i]);
  for(i=0;i<n;i++)scanf("%d",&b[i]);
  for(i=0;i<30;i++){
    R=C=1;
    k=(1<<i);//printf("%d\n",k);
    for(j=0;j<n;j++)hin((int)(b[j]&((2LL<<i)-1)));
    for(j=0;j<n;j++)d[j]=N[hout()];
    //for(j=0;j<n;j++)printf("%d ",d[j]);printf("\n");
    for(j=c=0;j<n;j++)c+=((lb(0,n,2*k-(a[j]&((2LL<<i)-1)),d)-
			   lb(0,n,1*k-(a[j]&((2LL<<i)-1)),d))%2+
			  (n-
			   lb(0,n,3LL*k-(a[j]&((2LL<<i)-1)),d))%2);
    s+=c%2*k;
    /*or(j=0;j<n;j++)printf("%d %d %d %d\n",s,
			   lb(0,n,2*k-(a[j]&((2<<i)-1)),d),
			   lb(0,n,1*k-(a[j]&((2<<i)-1)),d),
			   lb(0,n,3*k-(a[j]&((2<<i)-1)),d));//*/
  }
  printf("%d\n",s);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:34:25: warning: format ‘%lld’ expects argument of type ‘long long int *’, but argument 2 has type ‘int *’ [-Wformat=]
   for(i=0;i<n;i++)scanf("%lld",&a[i]);
                         ^
./Main.c:33:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:34:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++)scanf("%lld",&a[i]);
                   ^
./Main.c:35:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++)scanf("%d",&b[i]);
                   ^