//By Lin
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#include <string>
#include <cstdlib>
#include <vector>

#define X first
#define Y second
#define mp make_pair
#define sqr(x) ((x) * (x))
#define Rep(i, n) for(int i = 0; i<(n); i++)
#define foreach(it, n) for(__typeof(n.begin()) it = n.begin(); it != n.end(); it++)

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

#define esp 1e-8
#define N 1010

int n;
pii	data[N];
int dp[N][N];
int tree[N];
void insert(int w, int key) {
	w ++;
	for (int i = w; i<=n; i += i&(-i)) 
		tree[i] += key;
}
int ask(int w) {
	w ++;
	int ret = 0;
	for (int i = w; i >= 1; i-= i&(-i)) 
		ret += tree[i];
	return ret;
}

void check(int &x, int y) {
	if (x == -1 || x > y) x = y;
}

int main() {
	int cas, tt = 0;
	scanf("%d", &cas);
	while (cas --) {
		scanf("%d", &n);
		Rep(i, n) scanf("%d", &data[i].X);
		Rep(i, n) data[i].Y = i;
		sort(data, data + n);
		memset(tree, 0, sizeof tree);
		Rep(i, n) insert(i, 1);
		dp[0][0] = 0;
		for (int L = 1; L<=n; L++) {
			insert(data[L - 1].Y, -1);
			for (int i = 0; i<=L; i++) {
				int j = L - i;
				dp[i][j] = -1;
				if (i) 
					check(dp[i][j], dp[i - 1][j] + ask(data[L - 1].Y));
				if (j) 
					check(dp[i][j], dp[i][j - 1] + (n - L - ask(data[L - 1].Y)));
			}
		}
		int ans = -1;
		for (int i = 0; i<=n; i++) check(ans, dp[i][n - i]);
		printf("Case #%d: %d\n", ++tt, ans);
	}
	return 0;
}
