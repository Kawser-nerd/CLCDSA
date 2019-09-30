#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int> k;
	int n, a;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		k.push_back(a);
		sum += a;
	}
	int e, el, ell;
	int p = 0, pl = 0, pll = 0;
	int kkk = 1 << 30;
	if (sum % n != 0)
	{
		e = sum / n;
		for (int i = 0; i < k.size(); i++)
			p = p + (k[i] - e) * (k[i] - e);
		kkk = min(p, kkk);
		el = e + 1;
		for (int i = 0; i < k.size(); i++)
			pl = pl + (k[i] - el) * (k[i] - el);
		kkk = min(pl, kkk);
		ell = e - 1;
		for (int i = 0; i < k.size(); i++)
			pll = pll + (k[i] - ell) * (k[i] - ell);
		kkk = min(pll, kkk);
		cout << kkk << endl;
		return 0;
	}
	sum = sum / n;
	int ans = 0;
	for (int i = 0; i < k.size(); i++)
		ans = ans + (k[i] - sum) * (k[i] - sum);
	cout << ans << endl;
	return 0;
}