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
        int N, K;
        cin >> N >> K;
        vector<double> P;
        for (int i = 0; i < N; i++)
        {
            int a, b, c;
            scanf("%d/%d %d", &a, &b, &c);
            double p = (double) a / b;
            for (int j = 0; j < c; j++)
                P.push_back(p);
        }
        N = SZ(P);

        sort(RA(P), greater<double>());
        double ans = 0.0;
        vector<double> d(N + 1), q(N + 1), e(N + 1), r(N + 1);
        d[0] = 1.0;
        q[0] = 1.0;
        e[N] = 1.0;
        r[N] = 1.0;
        for (int i = 0; i < N; i++)
        {
            q[i + 1] = q[i] * P[i];
            d[i + 1] = d[i] * (1.0 - P[i]) + q[i + 1];
        }
        for (int i = N; i > 0; i--)
        {
            r[i - 1] = r[i] * (1.0 - P[i - 1]);
            e[i - 1] = e[i] * P[i - 1] + r[i - 1];
        }
        for (int f = 0; f <= N; f++)
        {
            int g = K - f;
            if (g >= 0 && g <= N)
            {
                double t = d[f] * r[N - g] + q[f] * e[N - g] - q[f] * r[N - g];
                ans = max(ans, t);
            }
        }
        printf("Case #%d: %.9f\n", cas + 1, 1.0 - ans);
    }
    return 0;
}
