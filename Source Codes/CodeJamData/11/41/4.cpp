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

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        int X, S, R, N;
        double t;
        cin >> X >> S >> R >> t >> N;
        int X0 = X;
        vector<pii> ways(N + 1);
        for (int i = 0; i < N; i++)
        {
            int b, e, w;
            cin >> b >> e >> w;
            ways[i] = pii(w, e - b);
            X0 -= e - b;
        }
        ways[N] = pii(0, X0);
        N++;
        sort(RA(ways));

        double ans = 0.0;
        for (int i = 0; i < N; i++)
        {
            double w = ways[i].first;
            double d = ways[i].second;
            double full = (w + R) * t;
            if (full >= d)
            {
                double tm = d / (w + R);
                ans += tm;
                t -= tm;
            }
            else if (full > 0.0)
            {
                ans += t;
                double rem = d - t * (w + R);
                ans += rem / (w + S);
                t = 0.0;
            }
            else
                ans += d / (w + S);
        }
        printf("Case #%d: %.9f\n", cas + 1, ans);
    }
    return 0;
}
