#include <stdio.h>
int main()
{
	long long a,b;
	char c;
		scanf("%lld",&a);
		scanf(" %c ",&c);
		scanf("%lld",&b);
		if(c=='-')
		{
			printf("%lld\n",a-b);
		}
		else
		{
			printf("%lld\n",a+b);
		}
	return 0;
}