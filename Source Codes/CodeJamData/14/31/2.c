#include<stdio.h>
typedef long long unsigned llu;
typedef unsigned u;
llu G(llu x,llu y){return y?G(y,x%y):x;}
int main()
{
	u t=0,T,r;llu x,y,z;
	for(scanf("%u",&T);t++<T;)
	{
		scanf("%llu/%llu",&x,&y);
		z=G(x,y);
		x/=z;y/=z;
		printf("Case #%u: ",t);
		if(y^(y&-y))printf("impossible\n");
		else
		{
			for(r=0;x<y;r++)x<<=1;
			printf("%u\n",r);
		}
	}
	return 0;
}
