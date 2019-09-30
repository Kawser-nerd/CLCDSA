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

static double dist(const pnt &a, const pnt &b)
{
    return abs(b - a);
}

struct sort_x
{
    bool operator()(const pnt &a, const pnt &b) const
    {
        return a.real() < b.real();
    }
};

struct sort_y
{
    bool operator()(const pnt &a, const pnt &b) const
    {
        return a.imag() < b.imag();
    }
};

static double recurse(const vector<pnt> &pnts, int A, int B)
{
    if (B - A < 3)
        return HUGE_VAL;

    int m = (A + B) / 2;
    double base = min(recurse(pnts, A, m), recurse(pnts, m, B));

    vector<pnt> col;
    for (int i = A; i < B; i++)
        if (fabs(pnts[i].real() - pnts[m].real()) <= base)
            col.push_back(pnts[i]);
    sort(RA(col), sort_y());

    int L = 0;
    double ans = base;
    for (int H = 0; H < SZ(col); H++)
    {
        while (col[H].imag() - col[L].imag() > base)
            L++;
        for (int i = L; i < H; i++)
            for (int j = i + 1; j < H; j++)
                ans = min(ans, dist(col[i], col[j]) + dist(col[j], col[H]) + dist(col[H], col[i]));
    }
    return ans;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        int N;
        cin >> N;
        vector<pnt> pnts(N);
        for (int i = 0; i < N; i++)
            cin >> pnts[i].real() >> pnts[i].imag();
        sort(RA(pnts), sort_x());
        double ans = recurse(pnts, 0, N);

        printf("Case #%d: %.12g\n", cas + 1, ans);
    }
    return 0;
}
