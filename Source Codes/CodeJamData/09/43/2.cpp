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

int T, N, K;
int adj_list[200][200];
int adj_size[200];
int  prev[200];
bool mark[200];

bool find_match(int node) {
    if (node == -1) return true;
    for (int i = 0; i < adj_size[node]; i++) {
        int match = adj_list[node][i];
        if (mark[match]) continue;
        mark[match] = true;
        if (find_match(prev[match])) {
            prev[match] = node;
            return true;
        }
    }
    return false;
}

int max_matching() {
    memset(prev, -1, sizeof(prev));
    int matching = 0;
    for (int i = 0; i < N; i++) {
        memset(mark, 0, sizeof(mark));
        if (find_match(i)) matching++;
    }
    return matching;
}

int value[200][100];

int main() {
	cin >> T;
	FOR(cs, 1, T+1) {
		cin >> N >> K;
		FOR(i, 0, N) FOR(j, 0, K) cin >> value[i][j];
		memset(adj_size, 0, sizeof(adj_size));
		FOR(i, 0, N) FOR(j, 0, N) {
			bool edge = true;
			FOR(k, 0, K) if (value[i][k] >= value[j][k]) edge = false;
			if (edge) adj_list[i][adj_size[i]++] = j;
		}
		int res = N - max_matching();
		cout << "Case #" << cs << ": " << res << endl;
	}
	return 0;
}
