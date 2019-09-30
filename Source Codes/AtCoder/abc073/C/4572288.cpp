#include<iostream>
#include<cstdio>
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int main()
{
	long long temp;
	int n;
	scanf("%d", &n);
	map<long long, int>p;
	for (int i = 0; i < n; ++i)
	{
		scanf("%lld", &temp);
		p[temp] += 1;
	}
	int count = 0;
	for (auto it = p.begin(); it != p.end(); ++it)
	{
		if (it->second % 2 == 1)
			count++;
	}
	printf("%d\n", count);
	system("pause");
	return 0;
}