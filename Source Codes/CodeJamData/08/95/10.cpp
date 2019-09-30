// Chmel.Tolstiy
// Tolstsikau Aliaksei

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1, 1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1, 2, -2, 2, -2, 1, -1, 1, -1};

#define mp make_pair

int test;

int n, m;
char s[20][20];
int  S[20];

int f[17][16][1 << 16];

int find(int r, int c, int ms) {
	if (r == n + 1) return 0;
	if (c == m) return find(r + 1, 0, ms);
	if (f[r][c][ms] != -1) return f[r][c][ms];
	int & res = f[r][c][ms];
	
	int ns = ms; if (ns & (1 << c)) ns -= 1 << c;

	if (s[r][c] == '.') {
		res = find(r, c + 1, ns); 
	}
	if (s[r][c] == '#') {
		res = find(r, c + 1, ns + (1 << c)) + 4;
		if (ms & (1 << c)) res-=2;
		if (c > 0 && (ms & (1 << (c - 1)))) res-=2;
	}
	
	if (s[r][c] == '?') {
		res = find(r, c + 1, ns + (1 << c)) + 4;
		if (ms & (1 << c)) res-=2;
		if (c > 0 && (ms & (1 << (c - 1)))) res-=2;
		res = max(res, find(r, c + 1, ns));
	}

	return res;
}

void solve() {
	cout << "Case #" << test << ": ";
	int ans = 0;
	cin >> n >> m;
	memset(f, -1, sizeof(f));
	for (int i = 0; i < n; i++) {
		cin >> s[i+1];
	}
	ans = find(1, 0, 0);
	cout << ans << endl;
}

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int tests;
	cin >> tests;
	for (test = 1; test <= tests; test++)
	solve();
	fclose(stdout);
	return 0;
}