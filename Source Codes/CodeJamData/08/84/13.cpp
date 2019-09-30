#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <sstream>
#include <map>
#include <queue>

using namespace std;

const int INF = 1e9;
const double eps = 1e-9;
const int NN = 1 << 20;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

int test = 1;

int n;
int k;
int p;

int F[1 << 10][1 << 10];
int MOD = 30031;

int find(int x, int m) {
	if (F[x][m] >= 0) return F[x][m];
	int & res = F[x][m]; res = 0;
	
	if (x == n) return res = 1;
	int K = n - x;
	if (K < k && (1 << K) - 1 == m) return res = 1;

	if ((m & 1) == 0) {
		res = find(x + 1, m / 2);
	} else {
		for (int i = 0; i < p; i++) {
			if (m & (1 << i)) continue;
			if (x + i + 1 > n) continue;
			res += find(x + 1, (m + (1 << i)) / 2);
		}
	}
	
	return res % MOD;
}

void solve() {
	memset(F, 0xff, sizeof(F));
	int res = 0;
	cin >> n >> k >> p;
	res = find(1, (1 << (k-1)) - 1);
	cout << "Case #" << test << ": " << res << endl;
}

int main() {
	freopen("D-small-attempt0.in","r",stdin);
	freopen("D-small-attempt0.out","w",stdout);
	int T = 1;
	cin >> T;
	for (; test <= T; test++)
	solve();
	return 0;
}