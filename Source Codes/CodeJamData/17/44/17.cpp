#include <bits/stdc++.h>
#include <fcntl.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/time.h>
#include <sys/resource.h>

using namespace std;

/*** START OF TEMPLATE CODE ***/

typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define RA(x) begin(x), end(x)
#define FE(i, x) for (auto i = begin(x); i != end(x); ++i)
#define SZ(x) ((ll) (x).size())

template<class T>
vector<T> splitstr(const string &s)
{
    istringstream in(s);
    vector<T> out;
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
    return out;
}

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

static void solve_case(int cas, ostream &cout, unique_ptr<promise<void> > &&input_done);

namespace helpers
{

static sem_t thread_slots;

class sem_poster
{
private:
    sem_t *sem;
public:
    explicit sem_poster(sem_t *sem) : sem(sem) {}
    ~sem_poster() { sem_post(sem); }
    sem_poster(const sem_poster &) = delete;
    sem_poster &operator=(const sem_poster &) = delete;
};

static string run_case(int cas, unique_ptr<promise<void> > &&input_done)
{
    sem_poster poster(&thread_slots);
    ostringstream out;
    solve_case(cas, out, move(input_done));
    return out.str();
}

} // namespace helpers

int main(int argc, char * const *argv)
{
    using namespace helpers;
    ios::sync_with_stdio(false);
    struct rlimit stack_limit;
    getrlimit(RLIMIT_STACK, &stack_limit);
    stack_limit.rlim_cur = 1024 * 1024 * 1024;
    setrlimit(RLIMIT_STACK, &stack_limit);

    char opt;
    int threads = thread::hardware_concurrency();
    bool threaded = false;
    while ((opt = getopt(argc, argv, "pt:")) != -1)
    {
        switch (opt)
        {
        case 'p':
            threaded = true;
            break;
        case 't':
            {
                char *end;
                threads = strtol(optarg, &end, 0);
                if (end == optarg || *end || threads <= 0)
                {
                    cerr << "Invalid thread count\n";
                    return 2;
                }
            }
            break;
        case ':':
        case '?':
            return 2;
        }
    }

    if (optind < argc)
    {
        int fd = open(argv[optind], O_RDONLY);
        if (fd == -1) { perror(argv[optind]); exit(1); }
        if (-1 == dup2(fd, 0)) { perror(argv[optind]); exit(1); }
        if (-1 == close(fd)) { perror(argv[optind]); exit(1); }
    }
    if (optind + 1 < argc)
    {
        int fd = open(argv[optind + 1], O_WRONLY | O_CREAT, 0666);
        if (fd == -1) { perror(argv[optind + 1]); exit(1); }
        if (-1 == dup2(fd, 1)) { perror(argv[optind + 1]); exit(1); }
        if (-1 == close(fd)) { perror(argv[optind + 1]); exit(1); }
    }
    cin.exceptions(ios::failbit | ios::badbit);

    int cases;
    cin >> cases;
    if (!threaded)
    {
        for (int cas = 0; cas < cases; cas++)
            solve_case(cas, cout, unique_ptr<promise<void> >());
    }
    else
    {
        sem_init(&thread_slots, 0, threads);
        deque<future<string> > outputs;
        for (int cas = 0; cas < cases; cas++)
        {
            sem_wait(&thread_slots);
            // Flush any output we can
            while (!outputs.empty())
            {
                auto status = outputs[0].wait_for(std::chrono::seconds(0));
                if (status != future_status::ready)
                    break;
                cout << outputs[0].get() << flush;
                outputs.pop_front();
            }
            unique_ptr<promise<void> > input_done{new promise<void>()};
            auto input_done_future = input_done->get_future();
            outputs.push_back(async(launch::async, run_case, cas, move(input_done)));
            // Wait until it consumes input before continuing
            input_done_future.get();
        }
        while (!outputs.empty())
        {
            cout << outputs[0].get() << flush;
            outputs.pop_front();
        }
    }
    return 0;
}

/*** END OF TEMPLATE CODE ***/

static const int dr[4] = {-1, 0, 1, 0};
static const int dc[4] = {0, -1, 0, 1};

static void solve_case(int cas, ostream &cout, unique_ptr<promise<void> > &&input_done)
{
    int C, R, M;
    cin >> C >> R >> M;
    vs grid(R);
    for (int i = 0; i < R; i++)
        cin >> grid[i];

    if (input_done) input_done->set_value();

    vector<pii> soldiers, turrets;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            if (grid[i][j] == 'S')
            {
                soldiers.emplace_back(i, j);
                grid[i][j] = '.';
            }
            else if (grid[i][j] == 'T')
            {
                turrets.emplace_back(i, j);
                grid[i][j] = '.';
            }
        }

    int S = SZ(soldiers);
    int T = SZ(turrets);
    vector<vi> hitmask(R, vi(C));
    for (int i = 0; i < T; i++)
    {
        int r0 = turrets[i].first;
        int c0 = turrets[i].second;
        for (int d = 0; d < 4; d++)
        {
            int r = r0;
            int c = c0;
            while (r >= 0 && r < R && c >= 0 && c < C && grid[r][c] == '.')
            {
                hitmask[r][c] |= 1 << i;
                r += dr[d];
                c += dc[d];
            }
        }
    }

    vector<vi> dp(1 << T, vi(1 << S));
    vector<vector<pii>> mov(1 << T, vector<pii>(1 << S));
    for (int tmask = 0; tmask < (1 << T); tmask++)
    {
        vector<int> rmasks(S);
        for (int s = 0; s < S; s++)
        {
            vector<vi> dist(R, vi(C, -1));
            int r0 = soldiers[s].first;
            int c0 = soldiers[s].second;
            dist[r0][c0] = 0;
            queue<pii> q;
            q.emplace(r0, c0);
            int reach = 0;
            while (!q.empty())
            {
                int r, c;
                tie(r, c) = q.front();
                q.pop();
                reach |= hitmask[r][c];
                if (dist[r][c] == M || (tmask & hitmask[r][c]))
                    continue;
                for (int d = 0; d < 4; d++)
                {
                    int r2 = r + dr[d];
                    int c2 = c + dc[d];
                    if (r2 >= 0 && r2 < R && c2 >= 0 && c2 < C && grid[r2][c2] == '.' && dist[r2][c2] == -1)
                    {
                        dist[r2][c2] = dist[r][c] + 1;
                        q.emplace(r2, c2);
                    }
                }
            }
            rmasks[s] = reach & tmask;
        }
        for (int smask = 0; smask < (1 << S); smask++)
        {
            int v = 0;
            pii m(-1, -1);
            for (int s = 0; s < S; s++)
                if (smask & (1 << s))
                    for (int t = 0; t < T; t++)
                        if (rmasks[s] & (1 << t))
                        {
                            int score = 1 + dp[tmask ^ (1 << t)][smask ^ (1 << s)];
                            if (score > v)
                            {
                                v = score;
                                m = pii(s, t);
                            }
                        }
            dp[tmask][smask] = v;
            mov[tmask][smask] = m;
        }
    }

    int ans = dp[(1 << T) - 1][(1 << S) - 1];
    cout << "Case #" << cas + 1 << ": " << ans << "\n";
    int tmask = (1 << T) - 1;
    int smask = (1 << S) - 1;
    vector<pii> path;
    for (int i = 0; i < ans; i++)
    {
        int s, t;
        tie(s, t) = mov[tmask][smask];
        path.emplace_back(s, t);
        tmask ^= 1 << t;
        smask ^= 1 << s;
    }
    for (int i = 0; i < ans; i++)
        cout << path[i].first + 1 << ' ' << path[i].second + 1 << '\n';
}
