#include<stdio.h>
int lb(int l,int r,int n,int *d){
  int m=(l+r)/2;
  if(l==r)return m;
  return n<=d[m]?lb(l,m,n,d):lb(m+1,r,n,d);
}
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
int main(){
	int n,m,i,a,s=0,d[100010];
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&a);
		hin(a);
	}
	for(i=0;i<n;i++)d[i]=N[hout()];
	for(i=0;i<m;i++){
		scanf("%d",&a);
		if(d[lb(0,n-1,a,d)]==a)s++;
	}
	printf("%f\n",1.0*s/(n+m-s));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:29:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&m);
  ^
./Main.c:31:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^
./Main.c:36:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^