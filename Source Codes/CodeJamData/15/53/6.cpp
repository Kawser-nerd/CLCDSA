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
    ios::sync_with_stdio(false);

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

    cin.exceptions(ios::failbit | ios::badbit);
}

/*** END OF TEMPLATE CODE ***/

struct quail
{
    ll start;
    ll speed;

    double pos_at(double t) const
    {
        return t * speed + start;
    }

    double catch_time(double t0, double p, double Y) const
    {
        return fabs(p - pos_at(t0)) / (Y - fabs(speed));
    }
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        int N;
        double Y;
        cin >> Y >> N;
        vector<int> start(N);
        vector<quail> q[2];
        for (int i = 0; i < N; i++)
            cin >> start[i];
        for (int i = 0; i < N; i++)
        {
            int speed;
            cin >> speed;
            if (start[i] < 0)
                q[0].push_back(quail{start[i], -speed});
            else
                q[1].push_back(quail{start[i], speed});
        }

        double ans = HUGE_VAL;
        for (int m = 0; m < (1 << N); m++)
        {
            if (__builtin_popcount(m) != SZ(q[1]))
                continue;
            double t = 0.0;
            double p = 0.0;
            int live[2];
            for (int i = 0; i < 2; i++)
                live[i] = (1 << SZ(q[i])) - 1;
            for (int i = 0; i < N; i++)
            {
                int dir = (m >> i) & 1;
                int next = -1;
                double tnext = HUGE_VAL;
                for (int j = 0; j < SZ(q[dir]); j++)
                    if (live[dir] & (1 << j))
                    {
                        double t1 = t + q[dir][j].catch_time(t, p, Y);
                        if (t1 < tnext)
                        {
                            tnext = t1;
                            next = j;
                        }
                    }
                live[dir] ^= 1 << next;
                t = tnext;
                p = q[dir][next].pos_at(t);
            }
            ans = min(ans, t);
        }
        cout << fixed << setprecision(6);
        cout << "Case #" << cas + 1 << ": " << ans << "\n";
    }
    return 0;
}
