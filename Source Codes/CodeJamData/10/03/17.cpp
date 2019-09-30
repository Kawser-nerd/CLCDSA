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
ll R, K, G[2000];
pair<int, ll> trans[2000];
int pos[2000];
ll euro[2000];

int main() {
	cin >> T;
	FOR(cs, 1, T+1) {
		cin >> R >> K >> N;
		FOR(i, 0, N) cin >> G[i];
		FOR(i, 0, N) {
			ll rem = K - G[i];
			int j;
			for (j = (i+1)%N; j != i; j = (j+1)%N) {
				if (rem >= G[j]) {
					rem -= G[j];
				} else break;
			}
			trans[i] = make_pair(j, K - rem);
		}
		memset(pos, -1, sizeof(pos));
		pos[0] = euro[0] = 0;
		int p = 0;
		ll res = 0;
		FOR(i, 1, R+1) {
			res = euro[i] = euro[i-1] + trans[p].second;
			p = trans[p].first;
			if (pos[p] != -1) {
				res = euro[pos[p]] + ((R - pos[p]) / (i - pos[p])) * (euro[i] - euro[pos[p]]) 
					+ euro[pos[p] + (R - pos[p]) % (i - pos[p])] - euro[pos[p]];
				break;
			} else pos[p] = i;
		}
		cout << "Case #" << cs << ": " << res << endl;
	}
	return 0;
}
