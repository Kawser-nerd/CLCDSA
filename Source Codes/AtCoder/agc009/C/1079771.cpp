#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <tuple>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#define int long long
using namespace std;
 
int mod = 1000000007;
int n, a[2];
int INF = 2000000000000000000;
int s[100010];
 
void input() {
	cin >> n >> a[0] >> a[1];
	if (a[0] > a[1]) swap(a[0], a[1]);
	s[0] = -INF;
	s[1] = -INF;
	n += 2;
	for (int i = 2; i < n; i++) {
		cin >> s[i];
	}
	s[n] = INF;
}
 
int l[2][100010];	//l[i][j] = s[p] - s[j - 1] >= a[(i+1)%2]???p????(p > j)
int r[2][100010];	//r[i][j] = s[p] - s[p - 1] <  a[i]???p???? (p > j)
 
void to_seg() {
	int i, j;
	
	static bool is_near[2][100010];	//is_near[i][j] = s[j] - s[j - 1] < a[i]???????? (1 <= j < n)
	for (j = 1; j < n; j++) {
		is_near[0][j] = (s[j] - s[j - 1] < a[0]);
		is_near[1][j] = (s[j] - s[j - 1] < a[1]);
	}
	
	//l
	for (i = 0; i < 2; i++) {
		for (j = 1; j < n; j++) {
			l[i][j] = lower_bound(s, s + n, s[j - 1] + a[!i]) - s;
			l[i][j] = max(l[i][j], j + 1);
		}
	}
	
	//r
	for (i = 0; i < 2; i++) {
		int p = n;
		for (j = n - 1; j >= 0; j--) {
			r[i][j] = p;
			if (is_near[i][j]) p = j;
		}
	}
}

const int depth = 17;	//??, ??(1 << depth)???????
class SegTree {
	int data[1 << (depth + 1)];	//data[i]?, ???????????(%mod)???
public:
	SegTree() { for (int i = 0; i < (1 << (depth + 1)); i++) data[i] = 0; }
	
	//??[l, r)?v(>=-mod)???. data[id]???[a, b)????????????
	void add(int l, int r, int v, int a = 0, int b = (1 << depth), int id = 0) {
		if (b <= l || a >= r) return;
		if (l <= a && b <= r) { data[id] = (data[id] + v + mod) % mod; return; }
		add(l, r, v, a, a + (b - a) / 2, 2 * id + 1);
		add(l, r, v, a + (b - a) / 2, b, 2 * id + 2);
	}
	
	//??pos(>=0)??(%mod)????
	int value(int pos) {
		pos = (1 << depth) - 1 + pos;
		int ret = data[pos];
		while (pos > 0) {
			pos = (pos - 1) / 2;
			ret += data[pos];
			ret %= mod;
		}
		return ret;
	}
	
	//??pos???x???
	void update(int pos, int x) {
		add(pos, pos + 1, x - value(pos));
	}
};
SegTree dp[2];

void to_dp() {
	int pos, i;
	
	dp[0].update(1, 1);
	for (pos = 1; pos < n; pos++) {
		for (i = 0; i < 2; i++) {
			dp[!i].add(l[i][pos], r[i][pos] + 1, dp[i].value(pos));
		}
	}
}
 
signed main() {
	input();
	to_seg();
	to_dp();
	
	int ans = dp[0].value(n) + dp[1].value(n);
	ans %= mod;
	cout << ans << endl;
	return 0;
}