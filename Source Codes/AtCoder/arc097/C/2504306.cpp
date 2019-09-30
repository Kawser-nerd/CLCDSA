/*
 NOTE:
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <queue>
#include <vector>
#include <map>
#include <stack>
#include <set>
#define MP make_pair
#define F first
#define S second
#define TIME (double)clock()/CLOCKS_PER_SEC
using namespace std;
typedef long long ll;

int n;
int c[4040], a[4040];
int mp[2][4040];

int dp[2020][2020];

typedef struct node {
	int v, st, ed;
	node *l, *r;
	node (int stt, int edd, node *ll, node *rr) {
		st = stt, ed = edd, l = ll, r = rr; v = 0;
	}
} *pnode;
pnode build(int st, int ed)
{
	if (st == ed) {
		pnode ne = new node(st, ed, 0, 0);
		return ne;
	}
	int mid = (st + ed) >> 1;
	pnode ne = new node(st, ed, build(st, mid), build(mid + 1, ed));
	return ne;
}

void add (pnode r, int p, int v)
{
	if (r->st == r->ed) {
		r->v = v;
		return ;
	}
	if (p <= r->l->ed)
		add (r->l, p, v);
	else
		add (r->r, p, v);
	r->v = r->l->v + r->r->v;
}

int find(pnode r, int x)
{
	if (r->st == r->ed)
		return r->v;
	
	if (r->l->ed >= x)
		return find(r->l, x);
	return r->l->v + find(r->r, x);
}

int main()
{
//	freopen("test.in", "r", stdin);
//	freopen("test.out", "w", stdout);
 	ios::sync_with_stdio(false);
	cin >> n;
	char ins;
	for (int i = 1; i <= 2 * n; i ++) {
		cin >> ins >> a[i], c[i] = (ins == 'W' ? 0 : 1);
		mp[c[i]][a[i]] = i;
	}
	
	int ans = 0;
	for (int i = 1; i <= 2 * n; i ++)
		for (int j = i + 1; j <= 2 * n; j ++)
			ans += (c[i] == c[j] && a[i] > a[j]);
	int bar[4040], bar2[4040];
	for (int i = 0; i <= n; i ++)
		for (int j = 0; j <= n; j ++)
			dp[i][j] = 1e9;
	dp[0][0] = 0;
	for (int i = 0; i <= n; i ++) {
		memset(bar, 0, sizeof bar);
		for (int j = 1; j <= 2 * n; j ++)
			bar[j] = bar[j - 1] + (c[j] == 0 && a[j] > i);
		pnode root = build(1, 2 * n);
		for (int j = 1; j <= n; j ++)
			add (root, mp[1][j], 1);
		for (int j = 0; j <= n; j ++) {
//			cerr << "dp" << i << " " << j << " = " << dp[i][j] << endl;
			if (i == n && j == n) {
				cout << ans + dp[i][j] << endl;
				return 0;
			}
			dp[i][j + 1] = min(dp[i][j + 1], bar[mp[1][j + 1]] + dp[i][j]);
			dp[i + 1][j] = min(dp[i + 1][j], find(root, mp[0][i + 1]) + dp[i][j]);
//			cerr << "cmp " <<  bar[mp[0][i + 1]] << " " << find(root, mp[0][i + 1]) << endl;
			if (j != n)
				add (root, mp[1][j + 1], 0);
		}
	}
			
	/*
	
	for (int st = 0, i = 1; i <= 2 * n; i ++) {
		if (c[i])
			continue ;
		num[i] = ++ st;
		int ii = i;
		while (ii + 1 <= 2 * n && c[ii + 1])
			ii ++;
		if (ii == 2 * n)
			break ;
		gap[st] = ii - i;
	}
	for (int i = 1; i <= n; i ++)
		s[i] = s[i - 1] + gap[i];
	for (int i = 1; i <= n; i ++) {
		int p = mp[0][i];
		int pos = num[p];
		for (int j = 1; j <= n; j ++)
			dp[i][j] = dp[i - 1][j] + abs(s[pos - 1] - s[j - 1]);
		for (int j = 2; j <= n; j ++)
			dp[i][j] = min(dp[i][j], dp[i][j - 1]);
	}
	ans += dp[n][n];
	
	memset(dp, 0, sizeof dp);
	memset(gap, 0, sizeof gap);
	memset(s, 0, sizeof s);
	memset(num, 0, sizeof num);
	for (int st = 0, i = 1; i <= 2 * n; i ++) {
		if (!c[i])
			continue ;
		num[i] = ++ st;
		int ii = i;
		while (ii + 1 <= 2 * n && !c[ii + 1])
			ii ++;
		if (ii == 2 * n)
			break ;
		gap[st] = ii - i;
	}
	for (int i = 1; i <= n; i ++)
		s[i] = s[i - 1] + gap[i];
	for (int i = 1; i <= n; i ++) {
		int p = mp[0][i];
		int pos = num[p];
		for (int j = 1; j <= n; j ++)
			dp[i][j] = dp[i - 1][j] + abs(s[pos - 1] - s[j - 1]);
		for (int j = 2; j <= n; j ++)
			dp[i][j] = min(dp[i][j], dp[i][j - 1]);
	}
	ans += dp[n][n];
	
	
	for (int i = 1; i <= 2 * n; i ++)
		for (int j = i + 1; j <= 2 * n; j ++)
			ans += (c[i] == c[j] && a[i] > a[j]);
	
	cout << ans << endl;
	*/
	return 0;
}
/*
3
W 3
B 1
W 2
B 2
W 1
B 3
*/