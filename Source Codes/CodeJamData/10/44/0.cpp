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
#include <climits>
#include <fcntl.h>
#include <unistd.h>

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

static double dot(const pnt &a, const pnt &b) { return real(conj(a) * b); }
static double cross(const pnt &a, const pnt &b) { return imag(conj(a) * b); }
static double cross(const pnt &a, const pnt &b, const pnt &c)
{
    return cross(b - a, c - a);
}

static void redirect(int argc, const char **argv)
{
    if (argc > 1)
    {
        int fd = open(argv[1], O_RDONLY);
        if (fd == -1) { perror(argv[1]); exit(1); }
        if (-1 == dup2(fd, 0)) { perror(argv[1]); exit(1); }
        if (-1 == close(fd)) { perror(argv[1]); exit(1); }
    }

    if (argc > 2)
    {
        int fd = open(argv[2], O_WRONLY | O_CREAT, 0666);
        if (fd == -1) { perror(argv[2]); exit(1); }
        if (-1 == dup2(fd, 1)) { perror(argv[2]); exit(1); }
        if (-1 == close(fd)) { perror(argv[2]); exit(1); }
    }
}

static double slice(const pnt &g, const pnt &w, const pnt &r)
{
    double rad = abs(w - g);
    double ang = arg(w - g) - arg(r - g);
    if (ang < 0.0) ang += 2 * M_PI;
    return 0.5 * ang * rad * rad - 0.5 * cross(g, r, w);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        printf("Case #%d:", cas + 1);

        int N, M;
        cin >> N >> M;
        vector<pnt> goats(N);
        vector<pnt> water(M);
        for (int i = 0; i < N; i++)
            cin >> goats[i].real() >> goats[i].imag();
        for (int i = 0; i < M; i++)
            cin >> water[i].real() >> water[i].imag();

        for (int sub = 0; sub < M; sub++)
        {
            double ans = 0.0;
            pnt g0 = goats[0];
            pnt g1 = goats[1];
            pnt w = water[sub];
            if (cross(g0, g1, w) != 0.0)
            {
                if (cross(g0, g1, w) < 0.0)
                    swap(g0, g1);
                pnt r = conj((w - g0) / (g1 - g0)) * (g1 - g0) + g0;
                ans = slice(g0, w, r) + slice(g1, r, w);
            }
            printf(" %.9f", ans);
        }
        printf("\n");
    }
    return 0;
}
