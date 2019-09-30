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

static void solve_case(int cas, ostream &cout, unique_ptr<promise<void> > &&input_done)
{
    // Load input

    int N, M;
    cin >> N >> M;
    vector<vi> spells(N);
    for (int i = 0; i < N; i++)
    {
        spells[i].resize(M);
        for (int j = 0; j < M; j++)
            cin >> spells[i][j];
    }

    if (input_done) input_done->set_value();

    int ans = 0;
    if (M == 1)
    {
        for (int i = 0; i < N; i++)
            if (spells[i][0] > 0)
                ans += spells[i][0];
    }
    else
    {
        int sum = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                sum += spells[i][j];

        vi axes(M);
        for (int i = 0; i < M; i++)
            axes[i] = i;
        int mmost = 0;
        do
        {
            vi pos(M, 0);
            vi most(M, 0);
            vector<bool> used(N);
            for (int axi = 0; axi < SZ(axes); axi++)
            {
                int ax = axes[axi];
                for (int i = 0; i < N; i++)
                {
                    if (!used[i] && spells[i][ax] < 0)
                    {
                        int delta = 0;
                        for (int axj = axi; axj < SZ(axes); axj++)
                            delta += spells[i][axes[axj]];
                        if (delta < 0)
                        {
                            used[i] = true;
                            for (int j = 0; j < M; j++)
                            {
                                pos[j] += spells[i][j];
                                most[j] = min(most[j], pos[j]);
                            }
                            mmost = min(mmost, accumulate(RA(most), 0));
                        }
                    }
                }
            }
        } while (next_permutation(RA(axes)));
        ans = sum - mmost;
    }

    cout << "Case #" << cas + 1 << ": " << ans << "\n";
}
