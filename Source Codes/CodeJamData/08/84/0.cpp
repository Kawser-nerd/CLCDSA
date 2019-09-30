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
#include <ext/numeric>

using namespace std;
using namespace __gnu_cxx;

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

#define MOD 30031

static int N;

struct Matrix
{
    int v[256][256];

    Matrix operator *(const Matrix &b) const
    {
        Matrix out;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
            {
                ll a = 0;
                for (int k = 0; k < N; k++)
                    a += v[i][k] * b.v[k][j];
                out.v[i][j] = a % MOD;
            }
        return out;
    }

    Matrix(int s = 1)
    {
        memset(v, 0, sizeof(v));
        for (int i = 0; i < N; i++)
            v[i][i] = s;
    }
};

int main()
{
    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        printf("Case #%d: ", cas + 1);

        int n, K, P;
        cin >> n >> K >> P;

        int remap[1024];
        int revmap[256];
        memset(remap, -1, sizeof(remap));
        N = 0;
        for (int i = 0; i < (1 << P); i++)
            if (__builtin_popcount(i) == K)
            {
                remap[i] = N;
                revmap[N] = i;
                N++;
            }

        Matrix step(0);
        const int high = 1 << (P - 1);
        for (int i = 0; i < N; i++)
        {
            int bits = revmap[i];
            if (!(bits & high))
            {
                int bits2 = (bits << 1) | 1;
                for (int j = 1; j < P; j++)
                    if (bits2 & (1 << j))
                        step.v[i][remap[bits2 ^ (1 << j)]] = 1;
            }
            else
            {
                int bits2 = bits ^ high;
                bits2 <<= 1;
                bits2 |= 1;
                step.v[i][remap[bits2]] = 1;
            }
        }

        const int start = (1 << K) - 1;
        Matrix stepn(power(step, n - K));
        printf("%d\n", stepn.v[remap[start]][remap[start]]);
    }
    return 0;
}
