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
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

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
static const int mirror1[4] = {3, 2, 1, 0};
static const int mirror2[4] = {1, 0, 3, 2};

static bool legal(const vs &grid, int r, int c, int d)
{
    int R = SZ(grid);
    int C = SZ(grid[0]);
    while (true)
    {
        r += dr[d];
        c += dc[d];
        if (r < 0 || r >= R || c < 0 || c >= C || grid[r][c] == '#')
            return true;
        else if (grid[r][c] == '|')
            return false;
        else if (grid[r][c] == '/')
            d = mirror1[d];
        else if (grid[r][c] == '\\')
            d = mirror2[d];
    }
}

typedef vector<vector<array<int, 2>>> arrr;

static void apply(const vs &grid, int r, int c, int d, arrr &hits, int s)
{
    int R = SZ(grid);
    int C = SZ(grid[0]);
    while (true)
    {
        r += dr[d];
        c += dc[d];
        if (r < 0 || r >= R || c < 0 || c >= C || grid[r][c] == '#')
            return;
        else if (grid[r][c] == '|')
            assert(0);
        else if (grid[r][c] == '/')
            d = mirror1[d];
        else if (grid[r][c] == '\\')
            d = mirror2[d];
        else
        {
            assert(grid[r][c] == '.');
            assert(hits[r][c][d & 1] == -1);
            hits[r][c][d & 1] = s;
        }
    }
}

static void solve_case(int cas, ostream &cout, unique_ptr<promise<void> > &&input_done)
{
    int R, C;
    cin >> R >> C;
    vs grid(R);
    for (int i = 0; i < R; i++)
        cin >> grid[i];

    if (input_done) input_done->set_value();

    vector<pair<int, int>> shooters;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            if (grid[i][j] == '-')
                grid[i][j] = '|';
            if (grid[i][j] == '|')
                shooters.emplace_back(i, j);
        }

    arrr hits(R, vector<array<int, 2>>(C));
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            for (int k = 0; k < 2; k++)
                hits[i][j][k] = -1;

    int S = SZ(shooters);
    bool good = true;
    vector<vector<int>> g(2 * S, vector<int>(2 * S));
    for (int i = 0; i < S; i++)
    {
        int r = shooters[i].first;
        int c = shooters[i].second;
        if (legal(grid, r, c, 0) && legal(grid, r, c, 2))
        {
            apply(grid, r, c, 0, hits, 2 * i);
            apply(grid, r, c, 2, hits, 2 * i);
        }
        else
            g[2 * i][2 * i + 1] = true;
        if (legal(grid, r, c, 1) && legal(grid, r, c, 3))
        {
            apply(grid, r, c, 1, hits, 2 * i + 1);
            apply(grid, r, c, 3, hits, 2 * i + 1);
        }
        else
            g[2 * i + 1][2 * i] = true;
    }

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            if (grid[i][j] != '.')
                continue;
            vector<int> verts;
            for (int k = 0; k < 2; k++)
                if (hits[i][j][k] != -1)
                    verts.push_back(hits[i][j][k]);
            sort(RA(verts));
            verts.resize(unique(RA(verts)) - verts.begin());
            if (verts.empty())
                good = false;
            else if (verts.size() == 1)
                g[verts[0] ^ 1][verts[0]] = true;
            else
            {
                g[verts[0] ^ 1][verts[1]] = true;
                g[verts[1] ^ 1][verts[0]] = true;
            }
        }

    for (int y = 0; y < 2 * S; y++)
        for (int x = 0; x < 2 * S; x++)
            if (g[x][y])
            {
                for (int z = 0; z < 2 * S; z++)
                    g[x][z] = g[x][z] | g[y][z];
            }

    for (int i = 0; i < 2 * S; i += 2)
        if (g[i][i + 1] && g[i + 1][i])
            good = false;

    cout << "Case #" << cas + 1 << ": " << (good ? "POSSIBLE" : "IMPOSSIBLE") << "\n";

    if (good)
    {
        vector<int> flip(S, -1);
        for (int i = 0; i < S; i++)
            if (flip[i] == -1)
            {
                int v;
                if (g[2 * i][2 * i + 1])
                    flip[i] = 1, v = 2 * i + 1;
                else
                    flip[i] = 0, v = 2 * i;
                for (int j = 0; j < 2 * S; j++)
                    if (g[v][j])
                    {
                        assert(flip[j / 2] != !(j & 1));
                        flip[j / 2] = j & 1;
                    }
            }
        for (int i = 0; i < S; i++)
            if (flip[i])
                grid[shooters[i].first][shooters[i].second] = '-';
        for (int i = 0; i < R; i++)
            cout << grid[i] << '\n';

        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                hits[i][j][0] = hits[i][j][1] = -1;

        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
            {
                int r = i, c = j;
                if (grid[i][j] == '|')
                {
                    assert(legal(grid, r, c, 0));
                    assert(legal(grid, r, c, 2));
                    apply(grid, r, c, 0, hits, 1);
                    apply(grid, r, c, 2, hits, 1);
                }
                else if (grid[i][j] == '-')
                {
                    assert(legal(grid, r, c, 1));
                    assert(legal(grid, r, c, 3));
                    apply(grid, r, c, 1, hits, 1);
                    apply(grid, r, c, 3, hits, 1);
                }
            }
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                if (grid[i][j] == '.')
                    assert(hits[i][j][0] == 1 || hits[i][j][1] == 1);
    }
}
