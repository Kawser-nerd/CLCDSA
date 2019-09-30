#include<iostream>
#include<string>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<random>
#include<iomanip>
#include<vector>
#include<functional>
#include<algorithm>
#include<cstdio>
#include<stdlib.h>
#include<unordered_map>
#include<time.h>
#define rep(i,a,n) for (int (i)=(a);(i)<(n);(i)++)
#define int long long
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 999999999999999999;
using namespace std;
int gcm(int a, int b) {
	if (a > b) swap(a, b);
	if (a == 0) return b;
	return gcm(b%a, a);
}
int n, a[100000], k, ma = 0, g;
signed main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ma = max(a[i], ma);
		if (i == 0) g = a[i];
		else g=gcm(g, a[i]);
	}
	if (k%g == 0 && ma >= k) cout << "POSSIBLE\n";
	else cout << "IMPOSSIBLE\n";
	getchar(); getchar();
}