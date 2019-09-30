#include <bits/stdc++.h>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

/*** START OF TEMPLATE CODE ***/

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int, int> pii;

#define RA(x) begin(x), end(x)
#define FE(i, x) for (auto i = begin(x); i != end(x); ++i)
#define SZ(x) ((int) (x).size())

template<class T>
vector<T> splitstr(const string &s)
{
    istringstream in(s);
    vector<T> out;
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
    return out;
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

    ios::sync_with_stdio(false);
    cin.exceptions(ios::failbit | ios::badbit);
}

/*** END OF TEMPLATE CODE ***/

static int mod(int a, int m)
{
    a %= m;
    if (a < 0)
        a += m;
    return a;
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
        vector<int> s(N - K + 1);
        for (int i = 0; i < N - K + 1; i++)
            cin >> s[i];
        vi lo(K), hi(K), cur(K), diff(K);
        for (int i = 0; i < N - K; i++)
        {
            int k = i % K;
            cur[k] += s[i + 1] - s[i];
            lo[k] = min(lo[k], cur[k]);
            hi[k] = max(hi[k], cur[k]);
        }
        int base = 0;
        for (int i = 0; i < K; i++)
        {
            diff[i] = hi[i] - lo[i];
            base += -lo[i];
        }
        int bump = mod(s[0] - base, K);
        int maxdiff = *max_element(RA(diff));
        ll flex = 0;
        for (int i = 0; i < K; i++)
            flex += maxdiff - diff[i];
        int ans = (flex >= bump) ? maxdiff : maxdiff + 1;

        cout << "Case #" << cas + 1 << ": " << ans << "\n";
    }
    return 0;
}
