#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>
#include <string.h>
#include <stdio.h>
#include <iomanip>
#include <assert.h>
using namespace std;

//cout.precision(6);
//cout.setf( std::ios::fixed, std:: ios::floatfield ); // floatfield set to fixed

const long long MOD = 1000000007LL;

#define REP(i,N) for (int i = 0; i < (N); ++i)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef unsigned int ui;
typedef long long ll;
typedef vector<ll> vll;

template<class T> void printImpl(const vector<T> & coll) { copy(coll.begin(), coll.end(), ostream_iterator<T>(cout, " ")); cout << endl; }
template<class T, int N> void printImpl(T (&coll)[N]) { copy(coll, coll + N, ostream_iterator<T>(cout, " ")); cout << endl; }
template<class Key, class Value> void printImpl(const map<Key, Value> & data) { typename map<Key, Value>::const_iterator it; for (it = data.begin(); it != data.end(); ++it) { cout << it->first << ":" << it->second << endl; } }
template <class T> void printImpl(const T & data) { cout << data << endl; }

#define DEBUGPRINT
#ifdef DEBUGPRINT
#define print(x) cout << #x" = "; printImpl(x);
#else
#define print(x) ;
#endif

int stepsToAchieve( const vi & a, int minMax )
{
    int res = 0;
    REP(i, a.size())
    {
        res += (a[i] - 1) / minMax;
    }

    return res;
}

int getMinMaxAfterSmall( const vi & a, int steps )
{
    for (int res = 1; res <= 1000; ++res)
    {
        if (stepsToAchieve(a, res) <= steps)
        {
            return res;
        }
    }

    return 1000;
}

int getMinMaxAfter( int steps, const vi & sta )
{
    if (sta[1] <= steps)
    {
        return 1;
    }

    int l = 1, r = 1000;
    assert(sta[r] <= steps);

    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if (sta[m] > steps)
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }

    return r;
}

int main()
{
    int caseCount;
    cin >> caseCount;
    
    for (int csIx = 1; csIx <= caseCount; ++csIx)
    {
        int N;
        cin >> N;
        vi a(N);
        int total = 0;
        REP(i,N)
        {
            cin >> a[i];
            total += a[i];
        }

        vi sta(1001);
        for (int t = 1; t <= 1000; ++t)
        {
            sta[t] = stepsToAchieve(a, t);
        }

        int res = 1000;

        for (int t = 0; t <= 1000; ++t)
        {
            int willNeedSteps = getMinMaxAfter(t, sta);
            res = min(res, t + willNeedSteps);
        }

        cout << "Case #" << csIx << ": " << res << endl;
    }
    
    return 0;
}
