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

static map<string, int> cid;
static int cid_pool = 0;

static int get_cid(const string &name)
{
    if (cid.count(name))
        return cid[name];
    else
        return cid[name] = cid_pool++;
}

struct paint
{
    int A;
    int B;
    int C;

    paint() {}
    paint(int A, int B, int C) : A(A), B(B), C(C) {}

    bool operator <(const paint &b) const
    {
        return B < b.B;
    }
};

static int minimum(int N, paint *P, int I, int J, int K)
{
    vector<paint> sub;
    vector<pii> up;

    for (int i = 0; i < N; i++)
        if (P[i].C == I || P[i].C == J || P[i].C == K)
            sub.push_back(P[i]);

    N = sub.size();

    int ans = INT_MAX;
    up.push_back(pii(0, 0));
    for (int i = 0; i < N; i++)
    {
        const paint &x = sub[i];
        vector<pii>::const_iterator pos = lower_bound(RA(up), pii(x.A, -1));
        if (pos == up.end()) continue;
        int a = pos->second + 1;
        if (x.B == 10000)
            ans = min(ans, a);
        while (up.back().second >= a)
            up.pop_back();
        up.push_back(pii(x.B, a));
    }
    return ans;
}

int main()
{
    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        cid.clear();
        cid_pool = 0;
        printf("Case #%d: ", cas + 1);

        int N;
        cin >> N;
        paint paints[N];
        for (int i = 0; i < N; i++)
        {
            string name;
            int A, B;
            cin >> name >> A >> B;
            A--;
            paints[i] = paint(A, B, get_cid(name));
        }
        sort(paints, paints + N);

        int nC = max(cid_pool, 3);
        int ans = INT_MAX;
        for (int i = 0; i < nC; i++)
            for (int j = i + 1; j < nC; j++)
                for (int k = j + 1; k < nC; k++)
                    ans = min(ans, minimum(N, paints, i, j, k));

        if (ans == INT_MAX)
            cout << "IMPOSSIBLE\n";
        else
            cout << ans << "\n";
    }
    return 0;
}
