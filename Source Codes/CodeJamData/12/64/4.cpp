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

typedef complex<double> pnt;

static inline double dot(const pnt &a, const pnt &b)
{
    return real(conj(a) * b);
}

static inline double cross(const pnt &a, const pnt &b)
{
    return imag(conj(a) * b);
}

static inline double cross(const pnt &a, const pnt &b, const pnt &c)
{
    return cross(b - a, c - a);
}

/* Sorts points by the angle they occupy relative to another point, starting at +X
 * and going ccw. Ties are broken by sorting with increasing distance from the base.
 * The base itself sorts to the front.
 */
class CompareAngle
{
private:
    const pnt base;

public:
    explicit CompareAngle(const pnt &base) : base(base) {}

    bool operator()(const pnt &a, const pnt &b) const
    {
        const pnt da = a - base;
        const pnt db = b - base;
        bool fa = da.imag() > 0 || (da.imag() == 0 && da.real() >= 0);
        bool fb = db.imag() > 0 || (db.imag() == 0 && db.real() >= 0);
        if (fa != fb)
            return fa;
        else
        {
            ll c = cross(da, db);
            if (c != 0)
                return c > 0;
            else
                return dot(da, da) < dot(db, db);
        }
    }
};



int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        int N, M;
        cin >> N >> M;
        vector<pnt> stars(N);
        for (int i = 0; i < N; i++)
        {
            cin >> stars[i].imag() >> stars[i].real();
            stars[i] *= pnt(1, -1);
        }
        sort(RA(stars), CompareAngle(pnt(0, 0)));

        pnt I(0, 1);
        pnt rots[4] = {1, I, -1, -I};

        vector<pnt> tdirs;
        for (int i = 0; i < N; i++)
        {
            tdirs.push_back(stars[i]);
            pnt split = (stars[i] + stars[(i + 1) % N]) * 0.5;
            if (split.real() || split.imag())
                tdirs.push_back(split);
        }
        int TD = SZ(tdirs);
        for (int i = 0; i < TD; i++)
        {
            for (int j = 1; j < 4; j++)
                tdirs.push_back(tdirs[i] * rots[j]);
        }
        TD = SZ(tdirs);

        double ans = 0.0;
        for (int ang = 0; ang < TD; ang++)
        {
            pnt tdir = tdirs[ang];
            pnt ssum = 0;
            pnt save[5];
            save[0] = pnt(0, 0);
            for (int steps = 0; steps < min(M, 4); steps++)
            {
                int best = -1;
                double bestalong = -HUGE_VAL;
                double bestacross = -HUGE_VAL;
                pnt mult = rots[steps & 3];
                for (int i = 0; i < N; i++)
                {
                    pnt cur = stars[i] * mult;
                    pnt rel = cur * conj(tdir);
                    double along = rel.real();
                    double across = rel.imag();
                    if (along > bestalong || (along == bestalong && across > bestacross))
                    {
                        bestalong = along;
                        bestacross = across;
                        best = i;
                    }
                }
                ssum += stars[best] * mult;
                save[steps + 1] = ssum;
                double d = abs(ssum);
                if (d > ans)
                {
                    ans = d;
                }
            }
            if (M > 4)
            {
                for (int phase = 0; phase < 4; phase++)
                {
                    double rep = (M - phase) / 4;
                    pnt tot = save[phase] + rep * save[4];
                    double d = abs(tot);
                    if (d > ans)
                        ans = d;
                }
            }
        }
        printf("Case #%d: %.8f\n", cas + 1, ans);
    }
    return 0;
}
