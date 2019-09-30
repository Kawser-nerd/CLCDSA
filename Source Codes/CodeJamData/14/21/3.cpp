#if 1
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int , int> pii;
typedef vector <int> veci;
typedef vector <veci> graph;
const LD eps = 1e-9;
const LD pi = acos(-1.0);
const int inf = 1000 * 1000 * 1000;
const LL inf64 = LL(inf) * inf;

#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define iss istringstream
#define oss ostringstream
#define dbg(x) {cerr << #x << " = " << x << endl;}
#define dbgv(x) {cerr << #x << " ={"; for (int _i = 0; _i < x.size(); _i++) {if (_i) cerr << ", "; cerr << x[_i];} cerr << "}" << endl;}
#define NAME "problem"

template<class T> string to_str(const T &a) { oss os; os << a; return os.str(); }
template<> string to_str<LD>(const LD& a) { oss os; os.precision(10); os.setf(ios::fixed); os << a; return os.str(); }
template<class T> T from_str(const string &s) { iss is; T val; is >> val; return val; }
string T(int test) { ostringstream os; os << "Case #" << test << ":"; return os.str(); }
int _test_start = -1, _test_end = -1;
bool need_to_run(int test) { return _test_start == -1 || _test_start <= test && test <= _test_end; }

int get(const vector<int> &p)
{
    int r = *max_element(p.begin(), p.end());
    int best = inf;
    for (int rem = 1; rem <= r + 1; ++rem)
    {
        int cur = 0;
        for (int i = 0; i < p.size(); ++i)
            if (p[i] < rem)
                cur += rem - p[i];
            else
                cur += p[i] - rem;
        best = min(best, cur);
    }
    return best;
}

void solve(int test)
{
    // read
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    if (!need_to_run(test)) return;
    // solve
    vector< vector< pii > > b(n);
    for (int i = 0; i < n; ++i)
    {
        b[i].push_back(mp(a[i][0], 1));
        for (int j = 1; j < a[i].size(); ++j)
            if (a[i][j] == a[i][j - 1])
                b[i].back().Y++;
            else
                b[i].push_back(mp(a[i][j], 1));
    }

    for (int i = 1; i < n; ++i)
    {
        bool ok = true;
        if (b[i].size() != b[0].size())
            ok = false;
        if (ok)
        {
            for (int j = 0; j < b[i].size(); ++j)
                if (b[i][j].X != b[0][j].X)
                    ok = false;
        }

        if (!ok)
        {
            cout << T(test) << " " << "Fegla Won" << endl;
            return;
        }
    }

    int res = 0;

    for (int i = 0; i < b[0].size(); ++i)
    {
        vector<int> p;
        for (int j = 0; j < n; ++j)
            p.push_back(b[j][i].Y);
        res += get(p);
    }

    // write
    cout << T(test) << " " << res << endl;
}

int main(int argc, char *argv[])
{
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    //freopen(NAME ".in","r",stdin); freopen(NAME ".out","w",stdout);
    if (argc == 2) { _test_start = _test_end = from_str<int>(argv[1]); }
    if (argc == 3) { _test_start = from_str<int>(argv[1]); _test_end = from_str<int>(argv[2]); }

    clock_t tstart = clock();

    int tests;
    scanf("%d", &tests);
    for(int test = 1; test <= tests; ++test)
    {
        clock_t tprev = clock();
        solve(test);
        if (need_to_run(test))
            dbg("elapsed for #" << test << ": " << (clock() - tprev) / LD(CLOCKS_PER_SEC));
    }

    dbg("elapsed: " << (clock() - tstart) / LD(CLOCKS_PER_SEC));
    return 0;
}
/*************************
*************************/
#endif

