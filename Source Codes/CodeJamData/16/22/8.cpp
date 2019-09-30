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

static bool compat(char a, char b)
{
    return a == '?' || b == '?' || a == b;
}

static char compat_low(char a, char b)
{
    if (a == '?' && b == '?')
        return '0';
    else if (a == '?')
        return b;
    else
        return a;
}

static void solve_case(int cas, ostream &cout, unique_ptr<promise<void> > &&input_done)
{
    string input[2];
    cin >> input[0] >> input[1];

    if (input_done) input_done->set_value();

    tuple<ll, string, string> best{LLONG_MAX, "", ""};
    for (int pass = 0; pass < 2; pass++)
    {
        string A0 = input[0];
        string B0 = input[1];
        int N = input[0].size();
        for (int i = 0; i <= N; i++)
        {
            string A1 = A0;
            string B1 = B0;
            if (i < N)
            {
                for (int j = i + 1; j < N; j++)
                {
                    if (A1[j] == '?')
                        A1[j] = '9';
                    if (B1[j] == '?')
                        B1[j] = '0';
                }
                for (char p = '0'; p < '9'; p++)
                    for (char q = p + 1; q <= '9'; q++)
                        if (compat(p, A1[i]) && compat(q, B1[i]))
                        {
                            A1[i] = p;
                            B1[i] = q;
                            assert(count(RA(A1), '?') == 0);
                            assert(count(RA(B1), '?') == 0);
                            ll a = stoll(A1);
                            ll b = stoll(B1);
                            tuple<ll, string, string> cur(llabs(a - b), pass ? B1 : A1, pass ? A1 : B1);
                            best = min(best, cur);
                            A1[i] = A0[i];
                            B1[i] = B0[i];
                        }
            }
            else
            {
                ll a = stoll(A1);
                ll b = stoll(B1);
                tuple<ll, string, string> cur(llabs(a - b), pass ? B1 : A1, pass ? A1 : B1);
                best = min(best, cur);
            }
            if (compat(A0[i], B0[i]))
                A0[i] = B0[i] = compat_low(A0[i], B0[i]);
            else
                break;
        }
        swap(input[0], input[1]);
    }

    cout << "Case #" << cas + 1 << ": " << get<1>(best) << ' ' << get<2>(best) << "\n";
}
