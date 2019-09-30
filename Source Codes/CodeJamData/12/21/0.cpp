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
        int N;
        cin >> N;
        vector<int> J(N);
        for (int i = 0; i < N; i++)
            cin >> J[i];
        int X = accumulate(RA(J), 0);
        printf("Case #%d:", cas + 1);
        for (int i = 0; i < N; i++)
        {
            double L = 0.0;
            double R = 1.0;
            while (R - L > 1e-9)
            {
                double Yi = (L + R) / 2.0;
                double M = Yi;
                double score = J[i] + X * Yi;
                double Yt = Yi;
                for (int j = 0; j < N; j++)
                    if (j != i)
                    {
                        double y = (score - J[j]) / X;
                        if (y > 1.0)
                            goto safe;
                        if (y < 0.0)
                            y = 0.0;
                        Yt += y;
                    }
                if (Yt > 1.0)
                    goto safe;
                L = M;
                continue;
safe:
                R = M;
            }
            printf(" %.6f", L * 100);
        }
        printf("\n");
    }
    return 0;
}
