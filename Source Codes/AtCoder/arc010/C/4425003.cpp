#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <limits>
#include <random>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <assert.h>
using namespace std;

typedef long long ll;
#define REP(i,n) for (ll i = 0; i < n; i++)
template <class T> using reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;

int n,m,Y,Z;
char c[10];
int p[10];
string b;
int col[26];

vector<vector<vector<int>>> memo;

int dfs (int i, int j, int mask)
{
    if (i == n) return 0;
    if (j >= 0) {
        if (memo[i][mask][j] != -1e9) {
            return memo[i][mask][j];
        }
    }
    int ct = col[b[i] - 'A'];
    int ret1 = p[ct];
    int ret2 = 0;
    if (j == ct) ret1 += Y;
    if (mask != ((1 << m) - 1) && (mask | (1 << ct)) == ((1 << m) - 1)) {
        ret1 += Z;
    }
    ret1 += dfs(i + 1, ct, mask | (1 << ct));
    ret2 += dfs(i + 1, j, mask);
    if (j == -1) return max(ret1, ret2);
    memo[i][mask][j] = max(ret1, ret2);
    return memo[i][mask][j];
}

int main ()
{
    cin >> n >> m >> Y >> Z;
    REP(i,m) cin >> c[i] >> p[i];
    cin >> b;

    memo = vector < vector < vector < int > > > (n+1, vector<vector<int>>(1<<m, vector<int>(m+1, 0)));

    REP(i,m) col[c[i] - 'A'] = i;
    REP(i,n + 1)REP(j, m + 1)REP(k,(1 << m)) memo[i][k][j] = -1e9;

    cout << dfs (0, -1, 0) << endl;

    return 0;
}