#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
ll made()
{
	char s0;
	ll ans=0;
	s0=getchar();
	while(s0>='0'&&s0<='9')
	{
		ans=ans*10;
		ans+=s0-'0';
		s0=getchar();
	}
	return ans;
}
int main()
{
	ll a1=made();
	ll a2=made();
	int count=1;
	while(2*a1<=a2)
	{
		count++;
		a1=a1*2;
	}
	printf("%d\n",count);
}