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

static double cross(const pnt &a, const pnt &b)
{ return imag(conj(a) * b); }

int main()
{
    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        printf("Case #%d: ", cas + 1);

        pnt ta[3], tb[3];
        for (int i = 0; i < 3; i++)
            cin >> ta[i].real() >> ta[i].imag();
        for (int i = 0; i < 3; i++)
            cin >> tb[i].real() >> tb[i].imag();

        pnt ea = ta[1] - ta[0];
        pnt eb = tb[1] - tb[0];
        pnt s = eb / ea;
        pnt t = tb[0] - s * ta[0];

        pnt ans = t / (1.0 - s);
        printf("%.7f %.7f\n", ans.real(), ans.imag());
    }
    return 0;
}
