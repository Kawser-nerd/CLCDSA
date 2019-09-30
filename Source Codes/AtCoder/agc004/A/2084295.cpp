#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long LL;
LL d;
LL a[5];
int main()
{
	scanf("%lld %lld %lld",&a[1],&a[2],&a[3]);
	if(a[1] % 2 == 0 || a[2] % 2 == 0 || a[3] % 2 == 0)
	{
		printf("0\n");
		return 0;
	}
	else 
	{
		sort(a + 1,a + 1 + 3);
		printf("%lld\n", a[1] * a[2]);
		return 0;
	}
}