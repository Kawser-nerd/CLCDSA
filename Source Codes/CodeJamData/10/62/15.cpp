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

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
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
        int ans = 0;
        map<pii, vector<int> > seen;
        cin >> N;

        int best[N];
        map<pii, int> ebest;
        int parents[N][2];
        fill(best, best + N, 0);
        seen[pii(0, 1)].push_back(2);
        parents[2][0] = 0;
        parents[2][1] = 1;

        for (int i = 3; i < N; i++)
        {
            int A, B;
            cin >> A >> B;
            A--;
            B--;
            if (A > B) swap(A, B);
            pii key(A, B);
            seen[key].push_back(i);
            // cout << "Adding " << i << " to (" << A << ", " << B << ")\n";
            parents[i][0] = A;
            parents[i][1] = B;
        }

        for (int i = N - 1; i >= 2; i--)
        {
            best[i] = 1;
            int ma = 0;
            int mb = 0;
            FE(j, seen[pii(parents[i][0], i)])
            {
                ma = max(ma, best[*j]);
            }
            FE(j, seen[pii(parents[i][1], i)])
            {
                mb = max(mb, best[*j]);
            }
            best[i] = 1 + ma + mb;
        }

        FE(e, seen)
        {
            int a = e->first.first;
            int b = e->first.second;

            int b1 = 0, b2 = 0;
            FE(i, e->second)
            {
                int v = best[*i];
                if (v > b1)
                {
                    b2 = b1;
                    b1 = v;
                }
                else if (v > b2)
                    b2 = v;
            }

            ans = max(ans, b1 + b2 + 2);
        }
        printf("Case #%d: %d\n", cas + 1, ans);
    }
    return 0;
}
