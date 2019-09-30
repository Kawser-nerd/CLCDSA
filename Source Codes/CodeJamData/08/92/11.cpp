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

int f[101][101];

int x[2], y[2];
int w, h;
int X, Y;

void go(int X, int Y) {
	if (X < 0 || X >= w) return;
	if (Y < 0 || Y >= h) return;
	if (f[X][Y]) return;
	f[X][Y] = 1;
	for (int i = 0; i < 2; i++)
		go(X + x[i], Y + y[i]);
}

void solve() {
	cout << "Case #" << test << ": ";
	int ans = 0;
	memset(f, 0, sizeof(f));
	
	cin >> w >> h;
	for (int i = 0; i < 2; i++) cin >> x[i] >> y[i];
	cin >> X >> Y;
	go(X, Y);

	for (int i = 0; i < w; i++) for (int j = 0; j < h; j++) if (f[i][j]) ans++;
 
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