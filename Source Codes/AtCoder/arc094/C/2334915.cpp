#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define INF 0x7fffffff
#define N 200005
int n;
long long cnt,a,b,minb=INF;
bool f=0;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld %lld",&a,&b);
		cnt+=b;
		if(b<a&&minb>b)
		minb=b;
		if(b!=a) f=1; 
	}
	if(f)printf("%lld\n",cnt-minb);
	else printf("0\n");
}