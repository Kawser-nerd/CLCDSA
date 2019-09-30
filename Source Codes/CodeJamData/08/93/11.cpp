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

int dx[] = {0, -1, 1, 0, 0, -1, -1, 1, 1, 1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {0, 0, 0, 1, -1, 1, -1, 1, -1, 2, -2, 2, -2, 1, -1, 1, -1};

#define mp make_pair

int test;

int f[50][50];
int m[50][50];

void solve() {
	cout << "Case #" << test << ": ";
	int ans = 0;
	
	int r, c;
	cin >> r >> c;
	for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) {
		cin >> f[i][j];
	}
	int N = 1 << (r*c);
	for (int i = 0; i < N; i++) {
		for (int x = 0; x < r; x++) for (int y = 0; y < c; y++) {
			int X = x*c + y; 
			if (i & (1 << X)) {
				m[x][y] = 1;
			} else {
				m[x][y] = 0;
			}
		}
		bool ok = true;
		for (int x = 0; x < r && ok; x++) for (int y = 0; y < c; y++) {
			int cnt = 0;
			for (int k = 0; k < 9; k++) {
				int xx = x + dx[k];
				int yy = y + dy[k];
				if (xx >= 0 && xx < r && yy >= 0 && yy < c) {
					cnt += m[xx][yy];
				}
			}
			if (cnt != f[x][y]) ok = false;
		}
		if (ok) {
			int cur = 0;
			for (int y = 0; y < c; y++) cur += m[r/2][y];
			if (cur > ans) ans = cur;
		}
	}
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