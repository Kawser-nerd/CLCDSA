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

int T, N;
string row[50];
int len[50];

int main() {
	cin >> T;
	FOR(cs, 1, T+1) {
		cin >> N;
		FOR(i, 0, N) cin >> row[i];
		FOR(i, 0, N) {
			len[i] = 0;
			FORD(j, 0, N) {
				if (row[i][j] == '1') {
					len[i] = j+1;
					break;
				}
			}
		}
		int res = 0;
		FOR(i, 0, N) {
			if (len[i] <= i+1) continue;
			int next = -1;
			FOR(j, i+1, N) {
				if (len[j] <= i+1) {
					next = j;
					break;
				}
			}
			FORD(j, i+1, next+1) {
				len[j] = len[j-1];
				res++;
			}
		}
		cout << "Case #" << cs << ": " << res << endl;
	}
	return 0;
}
