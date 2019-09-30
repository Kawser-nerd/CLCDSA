#include <stdio.h>
#include <iostream>
using namespace std;

long long gcd(long long a, long long b)
{
	if (a == 0) return b;
	return gcd(b%a, a);
}

int main()
{
	int cc,ca;
	cin >> ca;
	for(cc=1; cc<=ca; cc++)
	{
		long long P,Q;
		char c;
		cin >> P >> c >> Q;
		long long g = gcd(P, Q);
		P/=g; Q/=g;
		int a = 0;
		while(Q != 1)
		{
			if (Q%2 == 1)
				break;
			Q/=2; a++;
		}
		if (Q != 1)
		{
			printf("Case #%d: impossible\n", cc);
			continue;
		}
		int b = 0;
		while(P != 1)
		{
			P/=2; b++;
		}
		printf("Case #%d: %d\n", cc, a-b);
	}
}
