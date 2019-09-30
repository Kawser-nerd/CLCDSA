#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;


int calc(int a, int b)
{
	int i,j,k;
	if (a > b)
	{
		k = a; a = b; b = k;
	}
	if (a == 0 || b == 0) return 1;
	if (b%a == 0 && b != a) return 1;
	if (calc(b%a, a) == 0) return 1;
	if (calc(b%a, a) == 1 && b/a != 1) return 1;
	return 0;
}

void egcd(long long a, long long b, long long& x, long long &y)
{
	long long rx,ry;
	if(a%b == 0) {x=0; y=1; return;}
	egcd(b, a%b, rx, ry);
	x=ry;
	y=rx-ry*(a/b);
	return;
}

int main()
{
	int cc,ca;
	cin >> ca;
	for(cc=1;cc<=ca;cc++)
	{
		int A1,A2,B1,B2;
		int i,j,k;
		cin >> A1 >> A2 >> B1 >> B2;
		int r = 0;
		for(i=A1; i<=A2; i++) for(j=B1; j<=B2; j++)
		{
			int p = calc(i,j);
//			long long x,y;
//			egcd(i,j,x,y);
//			printf("%d %d %d %lld %lld\n", i,j,p, x, y);
			if (p) r++;
		}
		printf("Case #%d: %d\n", cc, r);
	}
}
