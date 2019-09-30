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
        printf("Case #%d:\n", cas + 1);
        int N;
        cin >> N;
        vector<vector<int> > score(N, vector<int>(N));
        for (int i = 0; i < N; i++)
        {
            string line;
            cin >> line;
            for (int j = 0; j < N; j++)
                if (line[j] == '.')
                    score[i][j] = -1;
                else
                    score[i][j] = line[j] - '0';
        }

        vector<int> win(N, 0);
        vector<int> loss(N, 0);
        vector<double> WP(N);
        vector<double> OWP(N);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (score[i][j] == 1)
                    win[i]++;
                else if (score[i][j] == 0)
                    loss[i]++;
            }
            WP[i] = (double) win[i] / (win[i] + loss[i]);
        }
        for (int i = 0; i < N; i++)
        {
            int opps = 0;
            double towp = 0.0;
            for (int j = 0; j < N; j++)
                if (score[i][j] != -1)
                {
                    opps++;
                    double W = 0;
                    double L = 0;
                    for (int k = 0; k < N; k++)
                        if (k != i)
                        {
                            if (score[j][k] == 1)
                                W++;
                            else if (score[j][k] == 0)
                                L++;
                        }
                    towp += W / (W + L);
                }
            OWP[i] = towp / opps;
        }

        for (int i = 0; i < N; i++)
        {
            double toowp = 0.0;
            int opps = 0;
            for (int j = 0; j < N; j++)
                if (score[i][j] != -1)
                {
                    toowp += OWP[j];
                    opps++;
                }
            double OOWP = toowp / opps;
            double RPI = 0.25 * WP[i] + 0.5 * OWP[i] + 0.25 * OOWP;
            printf("%.12f\n", RPI);
        }
    }
    return 0;
}
