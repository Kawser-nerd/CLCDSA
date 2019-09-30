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

struct person
{
    int abc[3];
};

struct compare
{
    int axis;

    bool operator()(const person &a, const person &b) const
    {
        return a.abc[axis] < b.abc[axis];
    }

    explicit compare(int ax) : axis(ax) {}
};

#define SIZE 10005
static int bit[SIZE];

static void bit_add(int p, int x)
{
    while (p < SIZE)
    {
        bit[p] += x;
        p += p & -p;
    }
}

static int bit_get(int p)
{
    int ans = 0;
    while (p)
    {
        ans += bit[p];
        p &= p - 1;
    }
    return ans;
}

int main()
{
    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        int N;
        cin >> N;
        vector<person> P(N);

        int ans = 0;

        for (int i = 0; i < N; i++)
            cin >> P[i].abc[0] >> P[i].abc[1] >> P[i].abc[2];
        for (int i = 0; i <= 10000; i++)
        {
            vector<person> Q;
            for (int j = 0; j < N; j++)
                if (P[j].abc[0] <= i)
                    Q.push_back(P[j]);
            sort(RA(Q), compare(1));

            int ptr = 0;
            memset(bit, 0, sizeof(bit));
            for (int j = 0; i + j <= 10000; j++)
            {
                while (ptr < SZ(Q) && Q[ptr].abc[1] == j)
                {
                    bit_add(Q[ptr].abc[2] + 1, 1);
                    ptr++;
                }
                ans = max(ans, bit_get(10000 - i - j + 1));
            }
        }
        printf("Case #%d: %d\n", cas + 1, ans);
    }
    return 0;
}
