#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define fo(i,a,b) for(int i=a,_b=b;i<=_b;i++)
int n,m,k;
int g(int n){ return n*(n+1)/2;}
int main()
{
	int T;
	scanf("%d",&T);
	fo(t,1,T)
	{
		scanf("%d%d%d",&n,&m,&k);
		int ans=k;
		if(k>4)
		fo(a,1,n) fo(b,1,m)
		{
			fo(c,0,b) fo(d,c,b-c-1) fo(e,0,b) 
			{
				if(c+e>=a)  break;
				fo(f,e,b-e-1)
				{
					if(d+f>=a)  break;
					if(a*b-g(c)-g(d)-g(e)-g(f)<k)  continue;
					ans=min(ans,b*2+a*2-(c+d+e+f)-4);
				}
			}
		}
		printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}
