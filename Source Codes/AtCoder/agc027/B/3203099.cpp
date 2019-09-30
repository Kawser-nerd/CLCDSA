// B. 

#include <sstream>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

LL n;
LL x;
vector<LL> a;

LL cost(LL d) {
	LL tot = 0;
	for (LL i = 0; i < d; ++i) {
		LL k = 0, l = 0;
		for (LL j = ((n - 1) / d) * d + i; j >= 0; j -= d) {
			if (j >= n) {
				continue;
			}
			if (!k) {
				tot += a[j];
			}
			else {
				tot += (k + 1) * (k + 1) * (l - a[j]);
			}
			tot += x;
			++k;
			l = a[j];
		}
		if (l) {
			tot += x;
			tot += (k + 1) * (k + 1) * l;
		}
	}
	return tot;
}

int main(int argc, char *argv[])
{
	cin >> n >> x;
	a.resize(n);
	for (LL i = 0; i < n; ++i) {
		cin >> a[i];
	}
	LL left = 1, right = n;
	for (LL t = 0; t < 100; ++t) {
		if (cost((left * 2 + right) / 3) < cost((left + right * 2) / 3)) {
			right = (left + right * 2) / 3;
		} else {
			left = (left * 2 + right) / 3;
		}
	}
	LL ans = 1LL << 60;
	for (LL d = max(1LL, left - 1); d <= min(n, left + 1); ++d) {
		ans = min(ans, cost(d));
	}
	cout << ans << endl;
	return 0;
}