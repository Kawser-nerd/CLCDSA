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

static vector<ll> load_seq(int N)
{
    ll z, A, C, R;
    cin >> z >> A >> C >> R;
    vector<ll> out{z};
    for (int i = 1; i < N; i++)
        out.push_back((out.back() * A + C) % R);
    return out;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        int N;
        ll D;
        cin >> N >> D;
        vector<ll> S = load_seq(N);
        vector<ll> M = load_seq(N);
        for (int i = 1; i < N; i++)
            M[i] %= i;
        vector<pair<ll, ll> > rng(N);
        rng[0] = make_pair(S[0], S[0]);
        vector<pair<ll, int> > events;
        for (int i = 0; i < N; i++)
        {
            if (i > 0)
                rng[i] = make_pair(min(S[i], rng[M[i]].first),
                                   max(S[i], rng[M[i]].second));
            if (rng[i].second - rng[i].first <= D)
            {
                events.emplace_back(rng[i].second - D, -1);
                events.emplace_back(rng[i].first, 1);
            }
        }
        sort(RA(events));
        int best = 0;
        int cur = 0;
        for (const auto &e : events)
        {
            cur -= e.second;
            best = max(best, cur);
        }
        cout << "Case #" << cas + 1 << ": " << best << "\n";
    }
    return 0;
}
