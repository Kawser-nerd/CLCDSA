#include <stdio.h>

int main()
{
	//freopen("input","r",stdin);
	int t,T,ip,iq,r;
	long long p,q;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%lld/%lld",&p,&q);
		ip=0;iq=0;
		while(p%2==0)
		{p/=2;ip++;}
		while(q%2==0)
		{q/=2;iq++;}
		if(q!=1 && p%q!=0)
			r=-1;
		else
		{
			p /= q;
			iq -= ip;
			ip = 0;
			while(p) {p/=2;ip++;}
			r = iq - ip;
		}
		if(r<0)
		printf("Case #%d: impossible\n",t);
		else
		printf("Case #%d: %d\n",t,r+1);
	}
	return 0;
}
