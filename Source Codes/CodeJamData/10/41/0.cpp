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

static inline int sqr(int x) { return x * x; }

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int cases;
    cin >> cases >> ws;
    for (int cas = 0; cas < cases; cas++)
    {
        string Kline;
        getline(cin, Kline);
        int K = atoi(Kline.c_str());
        int S = 2 * K - 1;
        string lines[S];

        for (int i = 0; i < S; i++)
        {
            getline(cin, lines[i]);
            while ((int) lines[i].size() < S)
                lines[i] += ' ';
        }

        int offv = INT_MAX;
        for (int s = 0; s < S; s++)
        {
            for (int i = 0; i < S; i++)
                for (int j = 0; j < S; j++)
                {
                    int j2 = 2 * s - j;
                    if (j2 >= 0 && j2 < S
                        && lines[i][j] >= '0' && lines[i][j2] >= '0'
                        && lines[i][j] != lines[i][j2])
                        goto asym1;
                }
            offv = min(offv, abs(K - 1 - s));
asym1:;
        }

        int offh = INT_MAX;
        for (int s = 0; s < S; s++)
        {
            for (int i = 0; i < S; i++)
            {
                int i2 = 2 * s - i;
                if (i2 >= 0 && i2 < S)
                    for (int j = 0; j < S; j++)
                    {
                        if (lines[i][j] >= '0' && lines[i2][j] >= '0'
                            && lines[i][j] != lines[i2][j])
                            goto asym2;
                    }
            }
            offh = min(offh, abs(K - 1 - s));
asym2:;
        }

        printf("Case #%d: %d\n", cas + 1, sqr(K + offv + offh) - sqr(K));
    }
    return 0;
}
