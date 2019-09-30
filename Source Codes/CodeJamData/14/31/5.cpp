#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long LL;
LL gcd(LL a,LL b){ return b?gcd(b,a%b):a; }
int main()
{
	int T;
	LL P,Q;
	scanf("%d\n",&T);
	for(int t=1;t<=T;t++)
	{
		scanf("%I64d/%I64d\n",&P,&Q);
		LL G=gcd(P,Q); P/=G,Q/=G;

		int ans;
		if(Q==1)  ans=1;
		else{
			if((1LL<<40)%Q==0)
			{
				P*=(1LL<<40)/Q;
				int k=0;
				while((1LL<<k+1)<=P) ++k;
				ans=40-k;
			}else ans=-1;
		}
		if(ans==-1) 
			printf("Case #%d: impossible\n",t);
		else printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}
