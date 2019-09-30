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

#define RA(x) std::begin(x), std::end(x)
#define FE(i, x) for (auto i = std::begin(x); i != std::end(x); ++i)
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

typedef unsigned char u8;

static int moves(const string &code)
{
    return count(RA(code), 'b') + count(RA(code), 'f');
}

#define BIG (1LL << 40)

struct modifier
{
    vector<u8> delta;
    ll base;
    ll end;

    ll operator[](ll pos) const
    {
        pos -= base;
        pos &= BIG - 1;
        if (pos < SZ(delta))
            return delta[pos];
        else
            return 0;
    }
};

static modifier make_modifier(const string &code)
{
    modifier cur;
    cur.base = 0;
    cur.end = 0;
    ll &base = cur.base;
    ll &end = cur.end;
    deque<u8> delta;
    delta.push_back(0);
    for (char c : code)
    {
        switch (c)
        {
        case 'f':
            end++;
            if (end - base >= SZ(delta))
                delta.push_back(0);
            break;
        case 'b':
            end--;
            if (end < base)
            {
                delta.push_front(0);
                base--;
            }
            break;
        case 'u':
            delta[end - base] -= 1;
            break;
        case 'd':
            delta[end - base] += 1;
            break;
        default:
            assert(0);
        }
    }
    cur.delta = vector<u8>(RA(delta));
    return cur;
}

static ll wrap(ll idx)
{
    idx &= BIG - 1;
    if (idx >= BIG / 2)
        idx -= BIG;
    return idx;
}

static void solve_case(int cas, ostream &cout, unique_ptr<promise<void> > &&input_done)
{
    // Load input
    string code;
    cin >> code;

    if (input_done) input_done->set_value();

    string prefix;
    string mid;
    string suffix;
    ll ans = moves(code);
    auto pos0 = code.find('(');
    auto pos1 = code.find(')');
    if (pos0 != string::npos)
    {
        prefix = code.substr(0, pos0);
        mid = code.substr(pos0 + 1, pos1 - pos0 - 1);
        suffix = code.substr(pos1 + 1);
        ll mmoves = moves(mid);
        modifier pmod = make_modifier(prefix);
        modifier mmod = make_modifier(mid);
        ll idx = mmod.end;
        u8 sum = mmod[mmod.end];
        while ((u8) (sum + pmod[idx + pmod.end]) != 0)
        {
            if (llabs(idx) >= 8000)
            {
                ll rep = (BIG - 13000) / abs(mmod.end);
                idx += mmod.end * rep;
                ans += mmoves * rep;
                idx = wrap(idx);
                assert(llabs(idx) < 8000 && llabs(idx) > 4000);
            }
            else
            {
                idx += mmod.end;
                sum += mmod[idx];
                ans += mmoves;
            }
        }
    }

    cout << "Case #" << cas + 1 << ": " << ans << "\n";
}
