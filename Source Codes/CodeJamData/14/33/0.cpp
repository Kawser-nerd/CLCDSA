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

static const int dr[4] = {-1, 0, 1, 0};
static const int dc[4] = {0, -1, 0, 1};

static int small(int N, int M, int K)
{
    int ans = K;
    int S = N * M;
    for (int mask = 1; mask < (1 << S); mask++)
    {
        if (__builtin_popcount(mask) > K)
            continue;
        vector<vi> grid(N, vi(M));
        int empty = 0;
        queue<pii> q;
        for (int r = 0; r < N; r++)
            for (int c = 0; c < M; c++)
            {
                int id = r * M + c;
                if (mask & (1 << id))
                    grid[r][c] = 1;
                else if (r == 0 || r == N - 1 || c == 0 || c == M - 1)
                {
                    grid[r][c] = 2;
                    empty++;
                    q.push(pii(r, c));
                }
            }
        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int d = 0; d < 4; d++)
            {
                int r2 = r + dr[d];
                int c2 = c + dc[d];
                if (r2 >= 0 && r2 < N && c2 >= 0 && c2 < M && grid[r2][c2] == 0)
                {
                    grid[r2][c2] = 2;
                    empty++;
                    q.push(pii(r2, c2));
                }
            }
        }
        if (S - empty >= K)
            ans = min(ans, __builtin_popcount(mask));
    }
    return ans;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        int N, M, K;
        cin >> N >> M >> K;
        if (N < M)
            swap(N, M);
        int ans;
        if (M == 1)
            ans = K;
        else if (K <= 4)
            ans = K;
        else
        {
            ans = INT_MAX;
            for (int R = 2; R <= N; R++)
                for (int C = 2; C <= min(R, M); C++)
                {
                    if (R * C < K)
                        continue;
                    int cover = R * C;
                    int use = (R + C) * 2 - 4;
                    int cut[4] = {};
                    int next = 0;
                    while (cover >= K)
                    {
                        if (use < ans)
                            ans = use;
                        cut[next]++;
                        use--;
                        cover -= cut[next];
                        next = (next + 1) & 3;
                        if (cut[0] + cut[2] >= C)
                            break;
                    }
                }
        }
        cout << "Case #" << cas + 1 << ": " << ans << '\n';
    }
    return 0;
}
