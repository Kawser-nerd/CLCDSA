#include <bits/stdc++.h>
#include <fcntl.h>
#include <unistd.h>
#include <semaphore.h>

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

struct fraction
{
    __int128 n = 0, d = 1;

    fraction() = default;
    fraction(__int128 n, __int128 d) : n(n), d(d) {}

    fraction operator-(const fraction &b) const
    {
        return fraction(n * b.d - d * b.n, d * b.d);
    }

    bool operator==(const fraction &b) const
    {
        return n * b.d == d * b.n;
    }

    bool operator<(const fraction &b) const
    {
        return n * b.d < d * b.n;
    }

    fraction operator*(__int128 x) const
    {
        return fraction(n * x, d);
    }

    fraction abs() const
    {
        if (n < 0)
            return fraction(-n, d);
        else
            return fraction(n, d);
    }
};

static void solve_case(int cas, ostream &cout, unique_ptr<promise<void> > &&input_done)
{
    // Load input
    int N;
    double Fd;
    string bits;
    cin >> N >> Fd >> bits;

    if (input_done) input_done->set_value();

    ll Fi = (ll) round(Fd * 1000000);
    fraction F(Fi, 1000000);
    fraction best(1000, 1);
    int besti = INT_MAX;
    vector<pair<fraction, int>> g(N + 1);
    vector<int> S(N + 1);
    g[0].first = fraction(0, 1);
    g[0].second = 0;
    int ones = 0;
    for (int i = 1; i <= N; i++)
    {
        ones += bits[i - 1] - '0';
        g[i].first = fraction(ones, 1) - F * i;
        g[i].second = i;
        S[i] = ones;
    }
    sort(RA(g));
    for (int i = 0; i < N; i++)
    {
        int a = g[i].second;
        int b = g[i + 1].second;
        if (a > b)
            swap(a, b);
        fraction cur(S[b] - S[a], b - a);
        cur = (cur - F).abs();
        if (cur < best || (cur == best && a < besti))
        {
            besti = a;
            best = cur;
        }
    }
    cout << "Case #" << cas + 1 << ": " << besti << "\n";
}
