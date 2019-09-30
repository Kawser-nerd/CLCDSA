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

struct ship
{
    double xyz[3];
    double p;
};

static bool reached(double q, const vector<ship> &ships)
{
    int delta[3][4] = 
    {
        {1, 1, 1, 1},
        {-1, -1, 1, 1},
        {-1, 1, -1, 1}
    };
    int N = ships.size();
    double range[4][2];
    for (int i = 0; i < 4; i++)
    {
        range[i][0] = -HUGE_VAL;
        range[i][1] = HUGE_VAL;
    }

    for (int i = 0; i < N; i++)
    {
        for (int a = 0; a < 4; a++)
        {
            double m = 
                delta[0][a] * ships[i].xyz[0]
                + delta[1][a] * ships[i].xyz[1]
                + delta[2][a] * ships[i].xyz[2];
            range[a][0] = max(range[a][0], m - q * ships[i].p);
            range[a][1] = min(range[a][1], m + q * ships[i].p);
        }
    }
    for (int a = 0; a < 4; a++)
    {
        if (range[a][0] > range[a][1])
            return false;
    }

    bool low = false, high = false;
    for (int v = 0; v < 8; v++)
    {
        double x_y_z = (v & 1) ? range[0][1] : range[0][0];
        double x_yz  = (v & 2) ? range[1][1] : range[1][0];
        double xy_z  = (v & 4) ? range[2][1] : range[2][0];
        double xyz = x_yz + xy_z - x_y_z;
        if (xyz >= range[3][0] && xyz <= range[3][1])
            return true;
        else if (xyz < range[3][0])
            low = true;
        else
            high = true;
    }
    return low && high;
}

int main()
{
    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        int N;
        cin >> N;
        vector<ship> ships(N);
        for (int i = 0; i < N; i++)
            cin >> ships[i].xyz[0]
                >> ships[i].xyz[1]
                >> ships[i].xyz[2]
                >> ships[i].p;
        double l = 0.0;
        double r = 1e9;
        while (r - l > 1e-8 && r - l > 1e-8 * r)
        {
            double m = (l + r) * 0.5;
            if (reached(m, ships))
                r = m;
            else
                l = m;
        }
        printf("Case #%d: %.9f\n", cas + 1, l);
    }
    return 0;
}
