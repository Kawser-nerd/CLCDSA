#include<stdio.h>
int mbk(long long a,int n,int m){return n?(mbk((a*a)%m,n/2,m)*(n%2?a:1))%m:1;}
int inv(int a,int m){return mbk((long long)a,m-2,m);}
int aCb(int a,int b,int m){
  long long s=1,i;
  if(b>a-b)b=a-b;
  for(i=0;i<b;i++)s=(((s*(a-i))%m)*inv(i+1,m))%m;  
  return (int)s;
}
int main(){
	long long n,m,i,j,s=1,M=1e9+7;
	scanf("%lld %lld",&n,&m);
	m--;
	if(n<0)n=-n;
	for(i=2;i*i<=n;i++){
		for(j=0;n%i==0;j++)n/=i;
		s=s*aCb(j+m,m,M)%M;
	}
	if(n-1)s=s*(m+1)%M;
	printf("%lld\n",(s*mbk(2,m,M))%M);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld",&n,&m);
  ^