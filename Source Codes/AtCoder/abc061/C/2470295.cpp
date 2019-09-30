#include<iostream>
using namespace std;

int main()
{
	int n;
	long long k;
	cin >> n >> k;
	long cnt[100001];
	for (size_t i = 0; i < 100001; i++)
	{
		cnt[i] = 0;
	}
	for (size_t i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		cnt[a] += b;
	}
	long c = 0;
	for (size_t i = 0; i < 100001; i++)
	{
		c += cnt[i];
		if (c >= k)
		{
			cout << i << endl;
			break;
		}
	}
    return 0;
}