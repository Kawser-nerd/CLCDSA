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

string to_bin(int num)
{
    string s;
    for (int i = 31; i >= 0; --i)
        if (num & (1 << i))
            s += "1";
        else
            s += "0";
    return s;
}

LL dp[33][2][2][2];

void solve(int test)
{
    // read
    int a, b, k;
    cin >> a >> b >> k;

    if (!need_to_run(test)) return;
    // solve
    string sa = to_bin(a);
    string sb = to_bin(b);
    string sk = to_bin(k);
    memset(dp, 0, sizeof dp);
    dp[0][0][0][0] = 1;
    for (int pref = 0; pref < sk.size(); ++pref)
        for (int lessa = 0; lessa < 2; ++lessa)
            for (int lessb = 0; lessb < 2; ++lessb)
                for (int lessk = 0; lessk < 2; ++lessk)
                {
                    int up_a = lessa ? 1 : sa[pref] - '0';
                    int up_b = lessb ? 1 : sb[pref] - '0';
                    int up_k = lessk ? 1 : sk[pref] - '0';

                    for (int dig_a = 0; dig_a <= up_a; ++dig_a)
                        for (int dig_b = 0; dig_b <= up_b; ++dig_b)
                        {
                            int dig_k = dig_a & dig_b;
                            if (dig_k > up_k)
                                continue;
                            int now_less_a = lessa || dig_a < sa[pref] - '0';
                            int now_less_b = lessb || dig_b < sb[pref] - '0';
                            int now_less_k = lessk || dig_k < sk[pref] - '0';
                            dp[pref + 1][now_less_a][now_less_b][now_less_k] += dp[pref][lessa][lessb][lessk];
                        }
                }

    // write
    LL res = dp[sk.size()][1][1][1];
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

