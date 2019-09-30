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
    vi primes;
    const int top = 1000000;
    vector<bool> is_prime(top + 1, true);
    for (int i = 2; i <= top; i++)
        if (is_prime[i])
        {
            primes.push_back(i);
            for (int j = i + i; j <= top; j += i)
                is_prime[j] = false;
        }

    for (int cas = 0; cas < cases; cas++)
    {
        ll N;
        cin >> N;

        int sq = int(sqrt(double(N)) + 2.0);
        ll ans = 0;
        for (int i = 0; i < SZ(primes) && primes[i] <= sq; i++)
        {
            int d = 0;
            int p = primes[i];
            ll N0 = N;
            while (N0 >= p)
            {
                N0 /= p;
                d++;
            }
            if (d > 0)
                ans += d - 1;
        }
        if (N > 1) ans++;
        printf("Case #%d: %lld\n", cas + 1, ans);
    }
    return 0;
}
