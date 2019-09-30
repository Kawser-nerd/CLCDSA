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
typedef complex<ll> pnt;
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

static ll dot(const pnt &a, const pnt &b) { return real(conj(a) * b); }
static ll cross(const pnt &a, const pnt &b) { return imag(conj(a) * b); }

static inline bool outside(ll W, ll H, const pnt &p)
{
    return p.real() < 0 || p.real() >= W || p.imag() < 0 || p.imag() >= H;
}

static ll brute(ll W, ll H, pnt v1, pnt v2, pnt s)
{
    if (v1.real() == 0)
    {
        swap(v1.real(), v1.imag());
        swap(v2.real(), v2.imag());
        swap(s.real(), s.imag());
        swap(W, H);
    }
    pnt v[2] = {v1, v2};

    vector<bool> seen(W);
    queue<pnt> q;
    q.push(s);
    seen[s.real()] = true;
    ll ans = 0;
    while (!q.empty())
    {
        pnt c = q.front();
        q.pop();
        ans++;
        for (int d = 0; d < 2; d++)
        {
            pnt n = c + v[d];
            if (!outside(W, H, n) && !seen[n.real()])
            {
                q.push(n);
                seen[n.real()] = true;
            }
        }
    }
    return ans;
}

static ll togo(ll W, ll v, ll s)
{
    if (v == 0) return LONG_LONG_MAX;
    else if (v < 0) return s / -v + 1;
    else return (W - s - 1) / v + 1;
}

static ll togo(ll W, ll H, const pnt &v, const pnt &s)
{
    return min(togo(W, v.real(), s.real()),
               togo(H, v.imag(), s.imag()));
}

int main()
{
    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        ll W, H, ans = 0;
        cin >> W >> H;
        pnt v1, v2, s;
        cin >> v1.real() >> v1.imag() >> v2.real() >> v2.imag();
        cin >> s.real() >> s.imag();
        if (cross(v1, v2) == 0)
        {
            ans = brute(W, H, v1, v2, s);
        }
        else
        {
            ans = togo(W, H, v2, s);
            for (;;)
            {
                while (outside(W, H, s + v1))
                {
                    s += v2;
                    if (outside(W, H, s))
                        goto done;
                }
                s += v1;
                ans += togo(W, H, v2, s);
            }
done:;
        }
        printf("Case #%d: %lld\n", cas + 1, ans);
    }
    return 0;
}
