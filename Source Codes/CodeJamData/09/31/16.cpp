#include <algorithm>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int d[256];
string st;
int L, D;

void read_data()
{
	cin >> st;
	L = st.length();
}

void solve()
{
	bool was0 = false;
	int cur = 1;

	memset(d, -1, sizeof(d));
	for (int i = 0; i < L; ++i) {
		int q = (unsigned char)st[i];

		if (d[q] == -1)
			if (i == 0) {
				d[q] = cur++;
			} else {
				if (!was0) { d[q] = 0; was0 = true; } else d[q] = cur++;
			}
	}

	long long int res = 0;
	for (int i = 0; i < L; ++i) {
		int q = (unsigned char)st[i];
		res = res*cur + d[q];
	}

	printf("%lld\n", res);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; ++t) {
		printf("Case #%d: ", t);
		read_data();
		solve();
	}

	return 0;
}
