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

int T, N, C[1100];

int main() {
	cin >> T;
	FOR(cs, 1, T+1) {
		cin >> N;
		FOR(i, 0, N) cin >> C[i];
		cout << "Case #" << cs << ": ";
		int sum = 0;
		FOR(i, 0, N) sum ^= C[i];
		if (sum != 0) {
			cout << "NO" << endl;
		} else {
			sort(C, C + N);
			sum = 0;
			FOR(i, 1, N) sum += C[i];
			cout << sum << endl;
		}
	}
	return 0;
}
