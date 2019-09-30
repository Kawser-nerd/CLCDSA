#include<cstdio>
#include<cmath>
using namespace std;
#define LL long long
#define pa pair<int,int>
LL read()
{
	LL x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
int main()
{
	int q=read();
	while(q--)
	{
		LL a=read(),b=read(),m=a*b;
		LL M=(LL)sqrt((long double)(m-1LL)),ans=M*2LL;
		LL t;
		if(a!=b)
		{
			if(a<=M)ans--;
			if(b<=M)ans--;
			if(m%M==0)t=m/M-1;
			else t=m/M;
			if(t==M)
			{
				ans--;
				if(a==M&&b==M)ans++;
			}
		}
		printf("%lld\n",ans);
	}
}