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
#include <numeric>

using namespace std;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)

int T, C, D, N;
bool opp[26][26];
int comb[26][26];
string invoke, cur;

int main() {
	cin >> T;
	FOR(cs, 1, T+1) {
		memset(opp, 0, sizeof(opp));
		memset(comb, -1, sizeof(comb));
		cin >> C;
		while (C--) {
			string s;
			cin >> s;
			int a = s[0] - 'A', b = s[1] - 'A', c = s[2] - 'A';
			comb[a][b] = comb[b][a] = c;
		}
		cin >> D;
		while (D--) {
			string s;
			cin >> s;
			int a = s[0] - 'A', b = s[1] - 'A';
			opp[a][b] = opp[b][a] = true;
		}
		cin >> N >> invoke;
		cur = "";
		FOR(i, 0, N) {
			cur += invoke[i];
			while (sz(cur) >= 2) {
				int a = cur[sz(cur)-2] - 'A', b = cur[sz(cur)-1] - 'A';
				if (comb[a][b] != -1) {
					cur = cur.substr(0, sz(cur)-2);
					cur += char(comb[a][b] + 'A');
				} else break;
			}
			bool clear = false;
			FOR(j, 0, sz(cur)) FOR(k, j+1, sz(cur)) if (opp[cur[j]-'A'][cur[k]-'A']) clear = true;
			if (clear) cur = "";
		}
		cout << "Case #" << cs << ": [";
		FOR(i, 0, sz(cur)) {
			cout << cur[i];
			if (i < sz(cur)-1) cout << ", ";
		}
		cout << ']' << endl;
	}
	return 0;
}
