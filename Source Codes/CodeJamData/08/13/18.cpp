#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int m[10000000];

//int u[1000][1000];


int main()
{
	//memset(u,0,sizeof(u));

	m[0] = 1;
	m[1] = 5;
	//u[1][5]=1;

	for (int i = 2; i <= 105; i++)
	{
		m[i] = (6*m[i-1] - 4*m[i-2] + 1 + 100000) % 1000;
	}

	freopen("c:\\3.txt", "r", stdin);
	freopen("c:\\3_out.txt", "w", stdout);

	int t;
	scanf("%d", &t);

	for (int te = 1; te <= t; te++)
	{
		int n;
		scanf("%d\n", &n);

		if (n < 103)
		{
			printf("Case #%d: %03d\n", te, m[n]);
		}
		else
		{
			n = n % 100;
			if (n < 3) n += 100;
			printf("Case #%d: %03d\n", te, m[n]);
		}
	}




	return 0;
}