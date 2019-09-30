#include <stdio.h> 

int main()
{
	int m,n,c,l,p;
	int cnt,ans;
	long long tmp;
	int test,t;
	scanf("%d",&test);
	for (t=1;t<=test;++t)
	{
		scanf("%d%d%d",&l,&p,&c);
		tmp=1;cnt=0;ans=0;
		while (tmp*c*l<p)
		{
			tmp*=c;
			++cnt;
		}
		tmp=1;
		while (tmp<=cnt)
		{
			tmp<<=1;
			++ans;
		}
		printf("Case #%d: %d\n",t,ans);
	}

}
