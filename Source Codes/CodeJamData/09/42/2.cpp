#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>

using namespace std;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)

int N, R, C, F;
string cave[100];
int tab[100][100][100];
int next[100][100];

int rek(int r, int c, int p) {
	if (r == R-1) return 0;
	int &res = tab[r][c][p];
	if (res != -1) return res;
	res = oo;
	int a = min(c, p), b = max(c, p);
	string row = cave[r];
	FOR(i, a, b+1) row[i] = '.';
	a = c, b = c;
	while (a > 0 && row[a-1] == '.' && cave[r+1][a-1] == '#') a--;
	while (b < C-1 && row[b+1] == '.' && cave[r+1][b+1] == '#') b++;
	if (a > 0 && row[a-1] == '.') {
		if (next[r][a-1] - r <= F) res = min(res, rek(next[r][a-1], a-1, a-1));
	}
	if (b < C-1 && row[b+1] == '.') {
		if (next[r][b+1] - r <= F) res = min(res, rek(next[r][b+1], b+1, b+1));
	}
	FOR(i, a, b+1) FOR(j, i, b+1) {
		int d = j - i + 1;
		if (i > a) {
			if (next[r][i] - r <= F) {
				if (next[r][i] - r == 1) {
					res = min(res, rek(next[r][i], i, j) + d);
				} else {
					res = min(res, rek(next[r][i], i, i) + d);
				}
			}
		}
		if (j < b) {
			if (next[r][j] - r <= F) {
				if (next[r][j] - r == 1) {
					res = min(res, rek(next[r][j], j, i) + d);
				} else {
					res = min(res, rek(next[r][j], j, j) + d);
				}
			}
		}
	}
	return res;
}

int main() {
	cin >> N;
	FOR(cs, 1, N+1) {
		cin >> R >> C >> F;
		FOR(i, 0, R) cin >> cave[i];
		cave[R] = "";
		FOR(i, 0, C) cave[R] += '#';
		FOR(r, 0, R-1) FOR(c, 0, C) {
			next[r][c] = r+1;
			while (cave[next[r][c]+1][c] == '.') next[r][c]++;
		}
		memset(tab, -1, sizeof(tab));
		int res = rek(0, 0, 0);
		if (res == oo) {
			cout << "Case #" << cs << ": No" << endl;
		} else {
			cout << "Case #" << cs << ": Yes " << res << endl;
		}
	}
	return 0;
}
