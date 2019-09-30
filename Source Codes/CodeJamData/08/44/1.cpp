#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <set>
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

static int normal[16][16] = {{0}};
static int cross[16][16] = {{0}};
static char S[60000];
static int memo[16][16][1 << 16];
static int K;

static int travel(int x, int y, int mask)
{
    int &ans = memo[x][y][mask];

    if (ans != -1)
        return ans;

    if (mask == 0)
        return ans = normal[x][y];

    ans = INT_MAX;
    for (int i = 0; i < K; i++)
    {
        int sub = 1 << i;
        if (mask & sub)
            ans = min(ans, normal[x][i] + travel(i, y, mask ^ sub));
    }
    return ans;
}

int main()
{
    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        memset(memo, -1, sizeof(memo));
        memset(normal, 0, sizeof(normal));
        memset(cross, 0, sizeof(cross));

        cin >> K >> S;
        int L = strlen(S);
        assert(K <= 16 && L <= 50000);

        for (int i = 0; i < L; i += K)
        {
            for (int j = 0; j < K; j++)
                for (int k = 0; k < K; k++)
                {
                    normal[j][k] += (S[i + j] != S[i + k]) ? 1 : 0;
                    if (i >= K)
                        cross[j][k] += S[i - K + j] != S[i + k];
                }
        }

        int best = INT_MAX;
        for (int i = 0; i < K; i++)
            for (int j = 0; j < K; j++)
                if (i != j)
                {
                    int mask = (1 << K) - 1;
                    mask &= ~(1 << i);
                    mask &= ~(1 << j);
                    best = min(best, travel(i, j, mask) + cross[j][i]);
                }
        printf("Case #%d: %d\n", cas + 1, best + 1);
    }
    return 0;
}
