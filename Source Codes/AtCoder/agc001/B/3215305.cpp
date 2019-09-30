#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
long long a,b;
int main()
{
	//freopen("light.in","r",stdin);
	//freopen("light.out","w",stdout);
	scanf("%lld %lld",&a,&b);
	long long ans=a;
	a=a-b;
	long long jl=0;
	while(b&&a)
	{
		if(a<b)
			swap(a,b);
		long long t=(a-1)/b;
		ans+=2*t*b;
		long long o=t*b;
		a=a-o;
		if(a==b)
		{
			ans+=a;
			break;
		}
	}
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
}