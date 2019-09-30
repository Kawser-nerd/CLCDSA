#include<stdio.h>
long long R=1,C=1,H[2000010],N[2000010];
//????????MAX?
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
int PC[200010],P[5][200010]={0};
int D[5][200010]={0};
int Set(int a,int b){
	int i,j;
	for(i=0;i<a;i++){
		for(j=0;j<=b;j++)P[i][j]=j;
		PC[i]=b;
	}
}
int Find(int a,int b,int i){
	int r,n;
	for(r=a ;P[i][r] -r;r=  P[i][r]);
	for( ;(n=P[i][a])-a;a=n)P[i][a]=r;
	for(r=b ;P[i][r] -r;r=  P[i][r]);
	for( ;(n=P[i][b])-b;b=n)P[i][b]=r;
	return a-b?1:0;
}
void Union(int a,int b,int i){
	if(Find(a,b,i)){
		for(;P[i][a]-a;a=P[i][a]);
		for(;P[i][b]-b;b=P[i][b]);
		D[i][a]<D[i][b]?(P[i][a]=b):(P[i][b]=a);
		if(D[i][a]==D[i][b])D[i][a]++;
		PC[i]--;
	}
}
int lb(int l,int r,long long n,long long *d){
  int m=(l+r)/2;
  if(l==r)return m;
  return n<=d[m]?lb(l,m,n,d):lb(m+1,r,n,d);
}
int ub(int l,int r,long long n,long long *d){
  int m=(l+r)/2;
  if(l==r)return m;
  return n<d[m]?ub(l,m,n,d):ub(m+1,r,n,d);
}
long long c[200010],d[200010];
int main(){
	int n,s,t,i,a,b;
	scanf("%d %d %d",&n,&s,&t);
	Set(2,n);
	for(i=0;i<s;i++){
		scanf("%d %d",&a,&b);
		Union(a-1,b-1,0);
	}
	for(i=0;i<t;i++){
		scanf("%d %d",&a,&b);
		Union(a-1,b-1,1);
	}
	for(i=0;i<n;i++){
		for(a=i;P[0][a]-a;a=P[0][a]);
		for(b=i;P[1][b]-b;b=P[1][b]);//printf("%d %d %d\n",i,a,b);
		hin(d[i]=a*1000000LL+b);
	}
	for(i=0;i<n;i++)c[i]=N[hout()];
	//for(i=0;i<n;i++)printf("%lld\n",c[i]);
	for(i=0;i<n;i++){
		//printf(":%d %d\n",ub(0,n,d[i],c),lb(0,n,d[i],c));
		printf("%d",ub(0,n,d[i],c)-lb(0,n,d[i],c));
		printf("%c",i-n-1?' ':'\n');
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:61:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d",&n,&s,&t);
  ^
./Main.c:64:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&a,&b);
   ^
./Main.c:68:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&a,&b);
   ^