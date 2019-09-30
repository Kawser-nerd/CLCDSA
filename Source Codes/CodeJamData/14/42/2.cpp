#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef double du;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)

const int MAXN = 11234;

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	int i0 = 1;
	int T;
	scanf("%d", &T);
	for (i0 = 1; i0 <= T; i0++) {
		int n;
		int i, j, k;
		vector<int> a;
		scanf("%d", &n);
		a.resize(n);
		for(i = 0; i < n; i++)
			scanf("%d", &a[i]);
		int ans = 0;
		while(n > 0){
			int x = a[0];
			for(i = 0; i < n; i++)
				x = min(x, a[i]);
			for(i = 0; i < n; i++)
				if(a[i] == x)
					break;
			ans += min(i, n-1-i);
			a.erase(a.begin() + i);
			n--;
		}
		printf("Case #%d: %d\n", i0, ans);
	}
	return 0;
}
