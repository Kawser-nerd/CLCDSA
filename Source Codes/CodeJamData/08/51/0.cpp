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
typedef complex<int> pnt;
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

static pii row_rng_s[7100];
static pii * const row_rng = row_rng_s + 3050;
static pii col_rng_s[7100];
static pii * const col_rng = col_rng_s + 3050;

static const pnt del[4] = 
{
    pnt(1, 0),
    pnt(0, 1),
    pnt(-1, 0),
    pnt(0, -1)
};

int main()
{
    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        int L;
        cin >> L;
        char s[64];
        int T;

        pnt cur(0, 0);
        int head = 0;
        ll area = 0;
        for (int i = -3001; i <= 3001; i++)
        {
            col_rng[i] = pii(INT_MAX, INT_MIN);
            row_rng[i] = pii(INT_MAX, INT_MIN);
        }
        for (int i = 0; i < L; i++)
        {
            cin >> s >> T;
            int len = strlen(s);
            for (int rep = 0; rep < T; rep++)
                for (int j = 0; j < len; j++)
                {
                    switch (s[j])
                    {
                    case 'L':
                        head = (head + 1) & 3;
                        break;
                    case 'R':
                        head = (head - 1) & 3;
                        break;
                    case 'F':
                        {
                            pnt nxt = cur + del[head];
                            int idx;
                            switch (head)
                            {
                            case 0:
                            case 2:
                                idx = min(cur.real(), nxt.real());
                                col_rng[idx].first = min(col_rng[idx].first, cur.imag());
                                col_rng[idx].second = max(col_rng[idx].second, cur.imag());
                                break;
                            case 1:
                            case 3:
                                idx = min(cur.imag(), nxt.imag());
                                row_rng[idx].first = min(row_rng[idx].first, cur.real());
                                row_rng[idx].second = max(row_rng[idx].second, cur.real());
                                break;
                            }
                            area += imag(conj(cur) * nxt);
                            cur = nxt;
                        }
                    }
                }
        }
        assert(cur == pnt(0, 0));

        int ans = 0;
        for (int i = -3001; i <= 3001; i++)
            for (int j = -3001; j <= 3001; j++)
                if ((j >= row_rng[i].first && j < row_rng[i].second)
                    || (i >= col_rng[j].first && i < col_rng[j].second))
                    ans++;
        ans -= llabs(area / 2);
        printf("Case #%d: %d\n", cas + 1, ans);
    }
    return 0;
}
