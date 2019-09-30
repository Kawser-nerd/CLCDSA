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


#define REP(i,n) for(int i=0;i<int(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define PB push


#define MOD 1000000007LL
#define EPS 1e-10

bool Check(int K, const string& S, vector<int> cnts, int si_)
{
    for (int si = si_; si < S.size(); ++si)
    {
        if (cnts[S[si] - 'a'] > 0)
        {
            --cnts[S[si] - 'a'];
        }
        else if (K > 0)
        {
            --K;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int N, K;
    string S;
    cin >> N >> K >> S;

    vector<int> cnts(26);
    cnts.assign(26, 0);
    for (char c : S)
    {
        ++cnts[c - 'a'];
    }

    REP(si, N)
    {
        REP(ci, 26)
        {
            char c = static_cast<char>('a' + ci);

            if (cnts[ci] > 0)
            {
                if (S[si] != c)
                {
                    if (K <= 0) continue;
                }

                --cnts[ci];
                if (S[si] != c)
                {
                    --K;
                }

                if (Check(K, S, cnts, si + 1))
                {
                    cout << c;
                    break;
                }
                else
                {
                    ++cnts[ci];
                    if (S[si] != c)
                    {
                        ++K;
                    }
                }
            }
        }
    }
    cout << endl;
    return 0;
}