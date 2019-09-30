#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

const int maxn = 218 * 1000;

int a[maxn];
int cntE[maxn];
int b[maxn];

bool check(int l) {
	memcpy(b, a, sizeof(a));
	memset(cntE, 0, sizeof(cntE));
	bool was = false;
	for (int i = 0; i < maxn - 10; ++i) {		
		while (b[i]) {
			if (cntE[i] > 0) {
				--b[i];
				--cntE[i];
				++cntE[i + 1];
				continue;
			}
			for (int j = 0; j < l; ++j) {
				if (b[i + j] <= 0) return false;
				--b[i + j];
			}
			++cntE[i + l];
			was = true;
		}
	}
	return was;
}

void solve() {
	memset(a, 0, sizeof(a));
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		++a[x];
	}
	int down = 0, up = n + 1;
	while (up - down > 1) {
		int t = (up + down) / 2;
		if (check(t)) down = t;
		else up = t;
	}
	int res = down;
	if (check(up)) res = up;
	cout << res << "\n";
}

int main()
{
	int nc;
	cin >> nc;
	for (int it = 0; it < nc; ++it) {
		printf("Case #%d: ", it + 1);
		solve();
	}
	return 0;
}
