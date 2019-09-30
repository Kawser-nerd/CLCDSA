#include<iostream>
using namespace std;

int main()
{
	int n = 0, q = 0;
	int l, r, t;
	int num[110] = { 0 };
	cin >> n >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> l >> r >> t;
		for (int i = l - 1; i < r; i++)
		{
			num[i] = t;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << num[i] << endl;
	}
	return 0;
}