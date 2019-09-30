#include <cstdio>
#include <cstring>
#include <cmath>

int main()
{
	freopen("C_large.in","r",stdin);
	freopen("C_large.out","w",stdout);
	
	int T,test=1;
	double k1=(1+sqrt(5.0))/2,k2=(sqrt(5.0)-1)/2;
	for (scanf("%d",&T);test<=T;++test)
	{
		int A1,A2,B1,B2;
		scanf("%d%d%d%d",&A1,&A2,&B1,&B2);
		long long Ans=(long long)(B2-B1+1)*(long long)(A2-A1+1);
		for (int x=A1;x<=A2;++x)
		{
			int r=(int)floor(x*k1);
			int l=(int)floor(x*k2)+1;
//			printf("%d %d %d\n",x,l,r);
			if (B1>l) l=B1;
			if (B2<r) r=B2;
			if (l<=r) Ans-=(r-l+1);
		}
		printf("Case #%d: %I64d\n",test,Ans);
	}
	return 0;
}
