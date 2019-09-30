#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <sstream>
#include <cstddef>
#include <algorithm>
#include <utility>
#include <iterator>
#include <numeric>
#include <list>
#include <complex>
#include <cstdio>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int, int> pii;

#define RA(x) (x).begin(), (x).end()
#define FE(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())

template<class T>
void splitstr(const string &s, vector<T> &out)
{
    istringstream in(s);
    out.clear();
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

int main()
{
    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        int R, C;
        cin >> R >> C;
        int grid[50][50];
        int nums[2500];
        int bits[2500];
        int T = R * C;
        int mid = (1 << C) - 1;
        mid <<= C * (R / 2);
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
            {
                cin >> grid[i][j];
                nums[i * C + j] = grid[i][j];

                bits[i * C + j] = 0;
                for (int i2 = max(i - 1, 0); i2 <= min(i + 1, R - 1); i2++)
                     for (int j2 = max(j - 1, 0); j2 <= min(j + 1, C - 1); j2++)
                          bits[i * C + j] |= 1 << (i2 * C + j2);
            }

        int ans = 0;
        for (int i = 0; i < (1 << T); i++)
        {
            for (int j = 0; j < T; j++)
                if (__builtin_popcount(i & bits[j]) != nums[j]) goto bad;
            ans = max(ans, __builtin_popcount(i & mid));
bad:;
        }

        printf("Case #%d: %d\n", cas + 1, ans);
    }
    return 0;
}
