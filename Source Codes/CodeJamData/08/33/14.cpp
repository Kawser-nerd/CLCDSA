#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <fstream>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;
#define FOR(i,n) for (int i = 0; i < (int) n; i++)

int a[1000000];
ll dp[1000000];


void remap(int a[], int n)
{
	map<int, int> m;
	FOR(i,n) m[a[i]] = 0;
	int z = 0;
	for (map<int,int>::iterator it = m.begin(); it != m.end(); ++it)
		it->second = z++;
	FOR(i,n) a[i] = m[a[i]];
}

class IndexTree {
	ll * a[21];
public:
	IndexTree()
	{
		int size = 1000000;
		FOR(i,21){
			a[i] = new ll[size];
			memset(a[i], 0, sizeof(ll) * size);
			size = size /2  + 1;
		}
	}
	~IndexTree()
	{
		FOR(i,21) delete [] a[i];
	}
	ll query(int x)
	{
		ll sum = 0;
		int i = 0;
		while (x >= 0) {
			if (x % 2) {
				sum += a[i+1][x/2];
			} else {
				sum += a[i][x];
			}
			sum %= MOD;
			x = x/2-1;
			i++;
		}
		return sum;
	}
	void update(int x, ll howmuch)
	{
		FOR(i,21) {
			a[i][x] = (a[i][x] + howmuch) % MOD;
			x /= 2;
		}
	}
};

int main(void)
{
	//freopen("3.in", "rt", stdin);
	//ifstream fo("3.out");
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		IndexTree t;
		ll all = 0;
		int n, m;
		ll x, y, z;
		cin >> n >> m >> x >> y >> z;
		ll g[128];
		for (int i = 0; i < m; i++) cin >> g[i];
		//
		for (int i = 0; i < n; i++) {
			a[i] = g[i % m];
			g[i % m] = (x * g[i % m] + y * ((ll)i+1)) % z;
		}
		remap(a, n);
		//
		for (int i = 0; i < n; i++) {
			dp[i] = 1;
			if (a[i])
				dp[i] = (dp[i] + t.query(a[i]-1)) % MOD;
			t.update(a[i], dp[i]);
			all = (all + dp[i]) % MOD;
		}
		//
		cout << "Case #" << tc << ": " << all << endl;
	}
	//fo.close();
	//system("diff -s 3.out 3-correct.out");
	return 0;
}
