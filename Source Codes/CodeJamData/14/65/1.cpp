#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
#include <numeric>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define INF 1000000007

ll f[6000];

int main()
{
	int _; cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		ll n;
		int A, B;
		cin >> n >> A >> B;
		memset(f,0,sizeof f);
		f[0] = 1;
		int S = 0;
		while (f[S] < n) {
			S ++;
			f[S] = max(f[S], f[S-1]);
			if (S >= A) {
				f[S] = max(f[S], f[S-A]+1);
			}
			if (S >= B) {
				f[S] = max(f[S], f[S-A]+f[S-B]);
			}
		}
		printf ("Case #%d: %d\n", __, S);
	}
	return 0;
}
