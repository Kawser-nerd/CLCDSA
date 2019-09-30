#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FORE(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SZ(x) (int)(x).size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

bool alg() {
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int> > v(rows, vector<int>(cols, 0));
    vector<int> rowmax(rows, (int) -1e9);
    vector<int> colmax(cols, (int) -1e9);
    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < cols; ++x) {
            cin >> v[y][x];
            rowmax[y] = max(rowmax[y], v[y][x]);
            colmax[x] = max(colmax[x], v[y][x]);
        }
    }
    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < cols; ++x) {
            if (v[y][x] != min(rowmax[y], colmax[x])) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n_cases;
    cin >> n_cases;
    for (int test_case = 1; test_case <= n_cases; ++test_case) {
        cout << "Case #" << test_case << ": " << (alg() ? "YES" : "NO") << endl;
    }
}
