#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>

static const int INF = 1001001001;

using namespace std;

typedef long long ll;

ll func(ll t, ll k)
{
	return 1 + k*t;
}

int main()
{
	ll a, k, ans;
	ll i = 0;
	cin >> a >> k;
	if (k != 0) {
		ans = a;
		while (ans < 2000000000000) {
			i++;
			ans = func(ans, k) + ans;
		}
		cout << i << endl;
	} else {
		cout << 2000000000000 - a << endl;
	}
	return 0;
}