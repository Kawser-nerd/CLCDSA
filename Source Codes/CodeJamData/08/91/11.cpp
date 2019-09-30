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

const int nn = 10001;

int a[nn];
int b[nn];
int c[nn];

int A[nn];
int B[nn];

int n;

int can[nn];
vector<int> BY[nn];
vector<int> CZ[nn];

void solve() {
	cout << "Case #" << test << ": ";
	int ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i];
		A[i] = a[i];
		B[i] = B[i];
	}
	
	sort(A, A + n); int ac = unique(A, A + n) - A;
	sort(B, B + n); int bc = unique(B, B + n) - B;
	
	for (int i = 0; i < ac; i++) {
		int x = A[i];
		int cur = 0;
		memset(can, 0, sizeof(can));
		for (int k = 0; k <= 10000; k++) BY[k].clear(), CZ[k].clear();
		for (int j = 0; j < n; j++) {
			if (a[j] <= x) {
				BY[b[j]].push_back(j);
				CZ[c[j]].push_back(j);
				if (c[j] <= 10000 - x) can[j]++;
				if (b[j] <= 0) can[j]++;
				if (can[j] == 2) cur++;
			}
		}
		ans = max(ans, cur);
		for (int y = 1; y <= 10000; y++) {
			for (int k = 0; k < BY[y].size(); k++) {
				int j = BY[y][k];
				can[j]++; if (can[j] == 2) cur++;
			}
			for (int k = 0; 10000 - x - y + 1 >= 0 && k < CZ[10000 - x - y + 1].size(); k++) {
				int j =  CZ[10000 - x - y + 1][k];
				can[j]--; if (can[j] == 1) cur--;
			}
			ans = max(ans, cur);
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