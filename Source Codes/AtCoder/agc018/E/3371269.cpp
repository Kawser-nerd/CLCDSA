#include<cstdio>
#include<algorithm>
#define MOD 1000000007
#define MAXN 2000006
using namespace std;
long long fac[MAXN],inv[MAXN],ans;
int x1,x2,x3,x4,x5,x6,y1,y2,y3,y4,y5,y6;
long long C(int m,int n)
{
	return (fac[n]*inv[m]%MOD)*inv[n-m]%MOD;
}
long long ksm(long long a,long long b)
{
	if(!b) return 1;
	long long nex=ksm(a,b/2);
	nex=nex*nex%MOD;
	if(b%2) nex=nex*a%MOD;
	return nex;
}
long long sum(int x1,int y1,int x2,int y2,int x3,int y3)
{
	long long re=0;
	for(int i=y1;i<=y2;i++)
		re=((C(x3-x2-1,x3-x2-1+y3-i)*C(x2-x1,x2-x1+i-y1)%MOD)*(x2-x1+1+i-y1)+re)%MOD;
	for(int i=x1;i<=x2;i++)
		re=(re+(C(y3-y2-1,y3-y2-1+x3-i)*C(y2-y1,y2-y1+i-x1)%MOD)*(y2-y1+1+i-x1))%MOD;
	return re;
}
long long cont(int a1,int b1,int a2,int b2)
{
	long long re=0;
	re+=sum(a1,b1,x4,y4,a2,b2);
	re+=sum(a1,b1,x3-1,y3-1,a2,b2);
	re-=sum(a1,b1,x3-1,y4,a2,b2);
	re-=sum(a1,b1,x4,y3-1,a2,b2);
	return re;
}
long long work(int x,int y)
{
	long long re=0;
	re+=cont(x,y,x6+1,y6+1);
	re+=cont(x,y,x5,y5);
	re-=cont(x,y,x6+1,y5);
	re-=cont(x,y,x5,y6+1);
	return (re%MOD+MOD)%MOD;
}
int main()
{
	scanf("%d%d%d%d%d%d",&x1,&x2,&x3,&x4,&x5,&x6);
	scanf("%d%d%d%d%d%d",&y1,&y2,&y3,&y4,&y5,&y6);
	fac[0]=1;
	for(int i=1;i<MAXN;i++)
		fac[i]=fac[i-1]*i%MOD;
	inv[MAXN-1]=ksm(fac[MAXN-1],MOD-2);
	for(int i=MAXN-2;i>=0;i--)
		inv[i]=inv[i+1]*(i+1)%MOD;
	ans+=work(x1-1,y1-1);
	ans+=work(x2,y2);
	ans-=work(x1-1,y2);
	ans-=work(x2,y1-1);
	ans=(ans%MOD+MOD)%MOD;
	printf("%lld\n",ans);
}