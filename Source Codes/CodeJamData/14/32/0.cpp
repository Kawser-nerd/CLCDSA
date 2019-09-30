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

struct invalid {};

#define MOD 1000000007

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    ll fact[101];
    fact[0] = 1;
    for (ll i = 1; i <= 100; i++)
        fact[i] = (fact[i - 1] * i) % MOD;

    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        cout << "Case #" << cas + 1 << ": ";
        try
        {
            int N;
            cin >> N;
            vs cars(N);
            vi loop(26);
            vector<vi> edges(26), redges(26);
            vector<bool> mid(26);
            for (int i = 0; i < N; i++)
                cin >> cars[i];
            for (int i = 0; i < 26; i++)
            {
                char c = i + 'a';
                for (int j = 0; j < N; j++)
                {
                    int last = -1;
                    int first = -1;
                    for (int k = 0; k < SZ(cars[j]); k++)
                        if (cars[j][k] == c)
                        {
                            if (first == -1)
                                first = k;
                            if (last != -1 && last != k - 1)
                                throw invalid();
                            last = k;
                        }
                    if (last >= 0)
                    {
                        if (first > 0 && last < SZ(cars[j]) - 1)
                        {
                            if (mid[i])
                                throw invalid();
                            mid[i] = true;
                        }
                    }
                }
            }
            for (int j = 0; j < N; j++)
            {
                int a = cars[j][0] - 'a';
                int b = cars[j][SZ(cars[j]) - 1] - 'a';
                if (mid[a] || mid[b])
                    throw invalid();
                if (a == b)
                    loop[a]++;
                else
                {
                    edges[a].push_back(b);
                    redges[b].push_back(a);
                }
            }

            ll ans = 1;
            int comps = 0;
            for (int i = 0; i < 26; i++)
            {
                if (SZ(edges[i]) > 1)
                    throw invalid();
                if (SZ(redges[i]) > 1)
                    throw invalid();
                ans = ans * fact[loop[i]] % MOD;
                if (edges[i].empty() && redges[i].empty() && loop[i] > 0)
                    comps++;
            }
            while (true)
            {
                int s;
                for (s = 0; s < 26; s++)
                    if (SZ(edges[s]) == 1 && SZ(redges[s]) == 0)
                        break;
                if (s == 26)
                    break;
                int cur = s;
                vector<int> path;
                do
                {
                    path.push_back(cur);
                    cur = edges[cur][0];
                } while (!edges[cur].empty());
                for (int v : path)
                {
                    edges[v].clear();
                    redges[v].clear();
                }
                comps++;
            }
            for (int i = 0; i < 26; i++)
                if (SZ(edges[i]))
                    throw invalid();
            ans = ans * fact[comps] % MOD;
            cout << ans << '\n';
        }
        catch (invalid &e)
        {
            cout << "0\n";
        }
    }
    return 0;
}
