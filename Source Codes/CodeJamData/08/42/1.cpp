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

int main()
{
    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        int X, Y, A;
        cin >> X >> Y >> A;
        printf("Case #%d: ", cas + 1);
        if (A > X * Y)
            printf("IMPOSSIBLE\n");
        else
        {
            int x1, y1, x2, y2;
            y1 = 1;
            x2 = -(A % X);
            while (x2 < 0) x2 += X;
            x1 = X;
            y2 = (A + x2) / X;
            printf("0 0 %d %d %d %d\n", x1, y1, x2, y2);
        }
    }
    return 0;
}
