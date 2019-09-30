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

static bool augment(int x, const std::vector<std::vector<int> > &edges, std::vector<int> &back, std::vector<bool> &done)
{
    if (x == -1)
        return true;
    if (done[x])
        return false;
    done[x] = true;
    for (int y : edges[x])
    {
        int old = back[y];
        back[y] = x;
        if (augment(old, edges, back, done))
            return true;
        back[y] = old;
    }
    return false;
}

// back must be sized to the number of vertices on the right
int matching(const std::vector<std::vector<int> > &edges, std::vector<int> &back)
{
    std::fill(RA(back), -1);
    int ans = 0;
    int L = SZ(edges);
    for (int i = 0; i < L; i++)
    {
        std::vector<bool> done(L);
        if (augment(i, edges, back, done))
            ans++;
    }
    return ans;
}

static int get_label(map<string, int> &labels, const string &word)
{
    if (labels.count(word))
        return labels[word];
    else
    {
        int ans = labels.size();
        labels[word] = ans;
        return ans;
    }
}

static void solve_case(int cas, ostream &cout, unique_ptr<promise<void> > &&input_done)
{
    int N;
    cin >> N;
    vector<pair<string, string>> topics(N);
    for (int i = 0; i < N; i++)
    {
        cin >> topics[i].first >> topics[i].second;
    }

    if (input_done) input_done->set_value();

    map<string, int> labels[2];
    vector<vector<int>> edges(N);
    for (int i = 0; i < N; i++)
    {
        int a = get_label(labels[0], topics[i].first);
        int b = get_label(labels[1], topics[i].second);
        edges[a].push_back(b);
    }
    int P = labels[0].size();
    int Q = labels[1].size();
    edges.resize(P);
    vector<int> back(Q, -1);
    int match = matching(edges, back);
    int ans = N - P - Q + match;
    cout << "Case #" << cas + 1 << ": " << ans << "\n";
}
