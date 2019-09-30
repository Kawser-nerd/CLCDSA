#include<stdio.h>
typedef long long ll;

int main()
{
	int T,S;
	scanf("%d",&T);
	for(S=1;S<=T;S++)
	{
		ll r,p,_l=1,_r=1,_m;
		scanf("%lld%lld",&r,&p);
		r=((r<<1)|1);
		while(r*_r+2*_r*(_r-1)<=p)_r<<=1;
		_r--;
		for(;;)
		{
			_m=((_l+_r+1)>>1);
			if(_l==_r)break;
			if(r*_m+2*_m*(_m-1)<=p)_l=_m;else _r=_m-1;
		}
		printf("Case #%d: %lld\n",S,_m);
	}	
	return 0;
}
