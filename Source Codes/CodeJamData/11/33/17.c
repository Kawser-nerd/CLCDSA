#include<stdio.h>
#define DIVIDES(a,b) (((a)%(b))&&((b)%(a)))
int main()
{
	int t,n,l,h,i,a[101],j,flag,m;
	scanf("%d",&t);
	m=0;
	while(m<t)
	{
		scanf("%d%d%d",&n,&l,&h);
		for(i=0;i<n;++i)
			scanf("%d",&a[i]);
		for(i=l;i<=h;++i)
		{
			flag=0;
			for(j=0;j<n;++j)
				if(DIVIDES(i,a[j]))
					flag=1;
			if(!flag)
				break;
		}
		printf("Case #%d: ",++m);
		if(!flag)
			printf("%d\n",i);
		else
			printf("NO\n");
	}
	return 0;
}
