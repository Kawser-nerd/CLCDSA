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

int T, N, P[110];
char R[110];

int main() {
	cin >> T;
	FOR(cs, 1, T+1) {
		cin >> N;
		FOR(i, 0, N) {
			string s;
			cin >> s >> P[i];
			R[i] = s[0];
		}
		int posO = 1, posB = 1, nxt = 0;
		int res = 0;
		while (nxt < N) {
			res++;
			int nxtO = -1, nxtB = -1;
			FORD(i, nxt, N) {
				if (R[i] == 'O') nxtO = P[i];
				if (R[i] == 'B') nxtB = P[i];
			}
			if ((R[nxt] == 'O' && nxtO == posO) || (R[nxt] == 'B' && nxtB == posB)) nxt++;
			if (nxtO != -1) {
				if (nxtO > posO) {
					posO++;
				} else if (nxtO < posO) {
					posO--;
				}
			}
			if (nxtB != -1) {
				if (nxtB > posB) {
					posB++;
				} else if (nxtB < posB) {
					posB--;
				}
			}
		}
		cout << "Case #" << cs << ": " << res << endl;
	}
	return 0;
}
