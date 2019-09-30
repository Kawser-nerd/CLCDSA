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

int char2n(char c)
{
    if (c == 'i') return 1;
    if (c == 'j') return 2;
    if (c == 'k') return 3;

    assert(false);
    return 0;
}

int mult_ijk(int a, int b)
{
    const static int m[8][8] =
    {
        {0,1,2,3,4,5,6,7},
        {1,4,3,6,5,0,7,2},
        {2,7,4,1,6,3,0,5},
        {3,2,5,4,7,6,1,0},
        {4,5,6,7,0,1,2,3},
        {5,0,7,2,1,4,3,6},
        {6,3,0,5,2,7,4,1},
        {7,6,1,0,3,2,5,4}
    };

    assert(0 <= a && a <= 7);
    assert(0 <= b && b <= 7);
    return m[a][b];
}

int div_ijk(int a, int b)
{
    const static int m[8][8] =
            {
                    {0,1,2,3,4,5,6,7},
                    {5,0,7,2,1,4,3,6},
                    {6,3,0,5,2,7,4,1},
                    {7,6,1,0,3,2,5,4},
                    {4,5,6,7,0,1,2,3},
                    {1,4,3,6,5,0,7,2},
                    {2,7,4,1,6,3,0,5},
                    {3,2,5,4,7,6,1,0}
            };

    assert(0 <= a && a <= 7);
    assert(0 <= b && b <= 7);
    return m[a][b];
}

int pow_ijk(int a, ll p)
{
    if ((p % 4) == 0) return 0;
    if ((p % 4) == 1) return a;
    if ((p % 4) == 2) return mult_ijk(a, a);
    if ((p % 4) == 3) return mult_ijk(mult_ijk(a, a), a);

    assert(false);
    return 0;
}

bool possible(const string & ss, ll X)
{
    ll N = ss.length();
    int totalRes = 0;
    REP(i,N)
    {
        totalRes = mult_ijk(totalRes, char2n(ss[i]));
    }
    totalRes = pow_ijk(totalRes, X);
    if (totalRes != 4)
    {
        return false;
    }

    string ss4 = ss + ss + ss + ss;

    vi res(4*N);
    res[0] = char2n(ss4[0]);

    for (int i = 1; i < 4 * N; ++i)
    {
        res[i] = mult_ijk(res[i-1], char2n(ss4[i]));
    }

    int firstIpos = -1, lastKpos = -1;
    REP(i, 4*N)
    {
        if (firstIpos == -1 && res[i] == 1)
        {
            firstIpos = i;
        }

        if (div_ijk(res[i], res[4*N-1]) == 3)
        {
            lastKpos = i;
        }
    }

    if (firstIpos == -1 || lastKpos == -1)
    {
        return false;
    }

    ll totalLength = firstIpos + 1 + (4 * N - lastKpos);
    if (totalLength > N * X)
    {
        return false;
    }

    return true;
}

int main()
{
    int caseCount;
    cin >> caseCount;
    
    for (int csIx = 1; csIx <= caseCount; ++csIx)
    {
        ll L, X;
        cin >> L >> X;
        string ss;
        cin >> ss;

        bool res = possible(ss, X);

        if (res)
        {
            cout << "Case #" << csIx << ": YES" << endl;
        }
        else
        {
            cout << "Case #" << csIx << ": NO" << endl;
        }
    }
    
    return 0;
}
