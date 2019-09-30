#include <array>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <deque>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <iterator>
#include <bitset>
#include <numeric>
#include <list>
#include <iomanip>
#include <tuple>
using namespace std;


typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

#define VV(T) vector<vector< T > >

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
	v.assign(a, vector<T>(b, t));
}

template <class F, class T>
void convert(const F &f, T &t){
	stringstream ss;
	ss << f;
	ss >> t;
}

template <class T>
T clampMax(const T& a, const T& b) { return min(a, b); }

template <class T>
T clampMin(const T& a, const T& b) { return max(a, b); }

template <class T>
bool updateMax(T& a, const T& b) { if (a < b) { a = b; return true; } return false; }

template <class T>
bool updateMin(T& a, const T& b) { if (a > b) { a = b; return true; } return false; }

#define REP(i,n) for(int i=0;i<int(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define PB push


#define MOD 1000000007LL
#define EPS 1e-10

LL dp[110][64];

int F(const string& str)
{
    auto f = [](char c)
    {
        switch (c)
        {
            case 'A': return 0;
            case 'C': return 1;
            case 'G': return 2;
            case 'T': return 3;
        }
        return 0;
    };
    return f(str[0]) * 16 + f(str[1]) * 4 + f(str[2]) * 1;
}

string G(int i)
{
    auto f = [](int i)
    {
        switch (i)
        {
            case 0: return 'A';
            case 1: return 'C';
            case 2: return 'G';
            case 3: return 'T';
        }
        return 'A';
    };
    string res;
    res += f(i / 16);
    res += f((i % 16) / 4);
    res += f((i % 16) % 4);
    return res;
}

int main()
{
    int N;
    cin >> N;
    REP(i, 64) dp[3][i] = 1;
    dp[3][F("AGC")] = 0;
    dp[3][F("ACG")] = 0;
    dp[3][F("GAC")] = 0;
    for (int i = 3; i < N; ++i)
    {
        REP(j, 64)
        {
            string s = G(j);
//            assert(s.size() == 3);
            switch (s[2])
            {
                case 'A':
                {
                    REP(k, 64)
                    {
                        string t = G(k);
                        if (s[0] == t[1] && s[1] == t[2])
                        {
                            dp[i + 1][j] += dp[i][k];
                            dp[i + 1][j] %= MOD;
                        }
                    }
                }
                break;

                case 'C':
                {
                    REP(k, 64)
                    {
                        string t = G(k);
                        if (s[0] == t[1] && s[1] == t[2])
                        {
                            if ((t[1] == 'A' && t[2] == 'G') || (t[1] == 'G' && t[2] == 'A') || (t[0] == 'A' && t[2] == 'G') || (t[0] == 'A' && t[1] == 'G'))
                            {
                            }
                            else
                            {
                                dp[i + 1][j] += dp[i][k];
                                dp[i + 1][j] %= MOD;
                            }
                        }
                    }
                }
                break;

                case 'G':
                {
                    REP(k, 64)
                    {
                        string t = G(k);
                        if (s[0] == t[1] && s[1] == t[2])
                        {
                            if (t[1] == 'A' && t[2] == 'C')
                            {

                            }
                            else
                            {
                                dp[i + 1][j] += dp[i][k];
                                dp[i + 1][j] %= MOD;
                            }
                        }
                    }
                }
                break;

                case 'T':
                {
                    REP(k, 64)
                    {
                        string t = G(k);
                        if (s[0] == t[1] && s[1] == t[2])
                        {
                            dp[i + 1][j] += dp[i][k];
                            dp[i + 1][j] %= MOD;
                        }
                    }
                }
                break;
            }
        }
    }
    LL ans = 0;
    REP(i, 64) { ans += dp[N][i]; ans %= MOD; }
    cout << ans << endl;
    return 0;
}