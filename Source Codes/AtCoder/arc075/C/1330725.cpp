//I Guds namespace
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 2 * 100 * 1000 + 13;

int BIT[MAXN], n;

ll preS[MAXN], a, ans, k;

vector<ll> v;

ll bitC(int x)
{
	ll ret = 0;
	for(;x > 0;x -= x & (-x))
		ret += BIT[x];
	return ret;
}

void bitUpd(int x)
{
	for(;x < MAXN;x += x & (-x))
		BIT[x]++;
	return;
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> k >> a; a -= k;
	if((preS[0] = a) > -1)
		ans++;
	v.push_back(preS[0]);
	for(int i = 1;i < n;i++)
	{
	cin >> a; a -= k;
		if((preS[i] = preS[i - 1] + a) > -1)
			ans++;
		v.push_back(preS[i]);
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	for(int i = 0;i < n;i++)
		preS[i] = upper_bound(v.begin(), v.end(), preS[i]) - v.begin();
	for(int i = 0;i < n;i++)
	{
		ans += bitC(preS[i]);
		bitUpd(preS[i]);
	}
	cout << ans << endl;
	return 0;
}