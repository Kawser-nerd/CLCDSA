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

static vector<vector<int> > edges;

#define MOD 1000000009

static int cache[1000][1000];

static int color(int e, int k, int r)
{
    if (cache[e][r] == -1)
    {
        if (e > k - r)
            cache[e][r] = 0;
        else
        {
            ll ans = 1;
            for (int i = 0; i < e; i++)
                ans = (ans * (k - r - i)) % MOD;
            cache[e][r] = ans;
        }
    }
    return cache[e][r];
}

static ll recurse(int x, int p, int k)
{
    int r = p == -1 ? 0 : edges[p].size();
    ll ans = color(edges[x].size() - (p == -1 ? 0 : 1), k, r);

    for (size_t i = 0; i < edges[x].size(); i++)
        if (edges[x][i] != p)
        {
            ans = (ans * recurse(edges[x][i], x, k)) % MOD;
        }
    return ans;
}

int main()
{

    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        printf("Case #%d: ", cas + 1);

        int n, k;
        cin >> n >> k;
        memset(cache, -1, sizeof(cache));
        edges.clear();
        edges.resize(n);
        for (int i = 1; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        printf("%d\n", (int) recurse(0, -1, k));
    }
    return 0;
}
