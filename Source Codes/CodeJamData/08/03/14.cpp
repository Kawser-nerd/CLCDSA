/* This is my Google Code Jam C++ solution template.
 * 
 * For the real solution code, scroll down to part 6. The rest of the file
 * contains pre-written library and framework code.
 *
 * The code is intended to work with a standard C++ compiler on a POSIX
 * platform. I use GCC 4.3 on Linux 2.6 with an x86-64 processor.
 *  
 * All code in this file was written by me, unless otherwise noted. I hereby
 * grant permission to copy, modify and reuse my code for any purpose.
 *  
 * Maks Verver [Soultaker]  <maksverver@geocities.com>   July 2008
 */

/* GCJ template part 01 -- Common headers */
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <fstream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

/* GCJ template part 02 -- Common macro definitions */
#define FOR(i, a, b)    for(int i = int(a); i < int(b); ++i)
#define REP(i, n)       FOR(i, 0, n)
#define FORE(i, a, b)   for(int i = int(a); i <= int(b); ++i)
#define REPE(i, n)      FORE(i, 0, n)
#define FORD(i, a, b)   for(int i = int(b) - 1; i >= int(a); --i)
#define REPD(i, n)      FORD(i, 0, n)
#define FORDE(i, a, b)  for(int i = int(b); i >= int(a); --i)
#define REPDE(i, n)     FORDE(i, 0, n)
#define IT(c)           __typeof((c).begin())
#define FORIT(i, c)     for(IT(c) i = (c).begin(); i != (c).end(); ++i)
#define SZ(c)           (int((c).size()))
#define ALL(c)          (c).begin(), (c).end()
#define SET(m, v)       memset((m), (v), sizeof(m))
#define REVERSE(c)      reverse(ALL(c))
#define SORT(c)         sort(ALL(c))
#define UNIQ(c)         SORT(c), (c).erase(unique(ALL(c)), (c).end())
#define PB              push_back
#define MP              make_pair
#define MAPRET(m, x)    { IT(m) _ = m.find(x); if(_ != m.end()) return _->second; }
/* GCJ template part 03 -- Common type definitions */
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<string> VS;
typedef vector<double> VD;
typedef vector<VI> VVI;
typedef vector<VLL> VVLL;
typedef vector<VS> VVS;
typedef vector<VD> VVD;

/* GCJ template part 04 -- Utility function definitions */

/* Reads and returns the next line from standard input. */
inline string LINE()
{
    string line;
    getline(cin, line);
    assert(cin);
    return line;
}

/* Convert a value to a string */
template<class T> inline string STR(const T &v) {
    ostringstream oss;
    oss << v;
    return oss.str();
}


//
// Basic parsing
//

template<class T> T PARSE(const string &s) {
    T r;
    istringstream iss(s);
    if(!(iss >> r)) throw "Type conversion failed!";
    return r;
}

VI PARSEVI(const string &s) {
    VI vi;
    istringstream iss(s);
    int i;
    while(iss >> i) vi.PB(i);
    return vi;
}

VVI PARSEVVI(const VS &vs) {
    VVI vvi;
    vvi.reserve(SZ(vs));
    FORIT(i, vs) vvi.PB(PARSEVI(*i));
    return vvi;
}

// Split string 's' by single characters, occuring in "sep"
VS SPLITC(const string &s, const string &seps = " ") {
    VS vs;
    if (s.empty()) return vs;
    string::size_type i, j;
    for(i = 0; (j = s.find_first_of(seps, i)) != string::npos; i = j + 1) vs.PB(string(s, i, j - i));
    vs.PB(string(s, i, j));
    return vs;
}

// Split string 's' by string 'sep'
VS SPLITS(const string &s, const string &sep) {
    VS vs;
    if (s.empty()) return vs;
    string::size_type i, j;
    for(i = 0; (j = s.find(sep, i)) != string::npos; i = j + SZ(sep)) vs.PB(string(s, i, j - i));
    vs.PB(string(s, i, j));
    return vs;
}

// Note: library code should not use overloading, as the unused code remover
//       doesn't handle this.
#define BIT(n) (1<<(n))
inline int BITCOUNT(unsigned x)             { return __builtin_popcount(x); }
inline int BITCOUNTL(unsigned long long x)  { return __builtin_popcountll(x); }
inline int TZEROS(unsigned x)               { return __builtin_ctz(x); }
inline int TZEROSL(unsigned long long x)    { return __builtin_ctzll(x); }
inline int LZEROS(unsigned x)               { return __builtin_clz(x); }
inline int LZEROSL(unsigned long long x)    { return __builtin_clzll(x); }
#define LOBIT(x) TZEROS(x)
#define HIBIT(x) (8*(sizeof(x)) - 1 - LZEROS(x))

// Tests if string a starts with string b
inline bool startswith(const string &a, const string &b) {
    return a.size() >= b.size() && a.compare(0, b.size(), b) == 0;
}

// Tests if string a end with string b
inline bool endswith(const string &a, const string &b) {
    return a.size() >= b.size() && a.compare(a.size() - b.size(), b.size(), b) == 0;
}

template<class T> inline T SQR(T x) { return x*x; }

inline LL GCD(LL a, LL b) { while(b) { LL c = b; b = a%b; a = c; } return a; }
inline LL LCM(LL a, LL b) { return (a / GCD(a, b))*b; }

// Tests wether an integer is prime
// Testing all integers from 1 to 1,000,000 takes about 1.5s
bool PRIME(int n) {
    if (n < 2) return false;
    if ((n&1) == 0) return n == 2;
    for (int d = 3; d*d <= n; d += 2) if(n%d == 0) return false;
    return true;
}

// A fast prime sieve, generating prime numbers upto (and including)
// `max` using `max`/16 bytes of memory.
 // Takes about 0.2s for max=10M.
void GENPRIMES(vector<int> &primes, int max) {
    primes.clear();
    if (max < 2)
        return;

    /* Sieve (odd numbers only) */
    vector<bool> comp((max + 1)/2);
    for (int n = 3; n*n <= max; n += 2)
        if (!comp[n/2])
            for (int m = n*n; m <= max; m += 2*n)
                comp[m/2] = true;

    /* Collect primes */
    primes.push_back(2);
    for (int n = 3; n <= max; n += 2)
        if (!comp[n/2])
            primes.push_back(n);
}

// Hashing
template<class It> ULL HASH(It i, It j) {
    ULL h = 14695981039346656037ULL;
    while (i != j)
    {
        h *= 1099511628211ULL;
        h ^= *(i++);
    }
    return h;
}
inline ULL HASH(const string &s) { return HASH(ALL(s)); }

// Binary searches for the first index '_' in the range [a,b) so that (cond)
// is true, and returns this index if found, or b otherwise.
// Note that a and b should be of the same integral type!
#define BINSEARCH(a,b,cond) ({ __typeof(a) l = (a), h = (b), _; \
    while(l<h) { _=(l>>1)+(h>>1)+(l&h&1); if(cond) h=_; else l=_+1; } h; })

/* GCJ template part 05 -- Execution framework */

class Result
{
    bool single;
    VS results;

public:
    Result()                        { clear(); };
    void clear()                    { results.clear(); single = true; };
    bool isEmpty() const            { return single && results.empty(); };
    bool isSingle() const           { return single; };
    void set(const string &s)       { clear(); results.push_back(s); };
    void set(const VS &vs)          { single = false; results = vs; };
    void add(const string &s)       { single = false; results.push_back(s); };
    const string getSingle() const  { return results.empty() ?
                                          string() : results.front(); };
    const VS &getMany() const       { return results; };
};


/* Represents a test case */
struct Case
{
    virtual ~Case() { };
    virtual void solve(Result &res) = 0;
};

/* To be implemented for the problem */
Case *read_case();

/*
 * Framework code starts here.
 */

#include <sys/resource.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

struct Job
{
    int  filedes;
    bool success;

    Job(int fd) : filedes(fd), success(0) { };
    virtual ~Job() { };
    virtual void wait() { success = true; };
};

struct ForkedJob : public Job
{
    pid_t pid;
    int   status;

    ForkedJob(int fd, pid_t pid) : Job(fd), pid(pid) { };
    void wait() {
        if (waitpid(pid, &status, 0) < 0) { perror("waitpid failed"); abort(); }
        success = (status == 0);
    }
};


int max_procs = 4;
int single_case = 0;
bool show_prog = false;
bool do_fork = true;

/* Options understood:
    -p N    Use at most N child processes (0 to prevent forking)
    -c N    Only process case N (useful for debugging)
    <name>  Read input from <name>.in and write output to <name>.out
*/
void parse_args(int argc, char *argv[])
{
    int opt;
    while ((opt = getopt(argc, argv, "p:c:")) != -1)
    {
        switch (opt)
        {
        case 'p':
            max_procs = atoi(optarg);
            if (max_procs < 0 || max_procs > 1000)
            {
                cerr << "Invalid number of processes: " << max_procs << endl;
                exit(1);
            }
            break;

        case 'c':
            single_case = atoi(optarg);
            if (single_case < 1)
            {
                cerr << "Invalid case number: " << single_case << endl;
                exit(1);
            }
            /* run in foreground by default, for debugging */
            max_procs = 0;
            break;

        default:
            cerr << "Unrecognized option!\n" << endl;
            exit(1);
        }
    }

    if (max_procs == 0)
    {
        max_procs = 1;
        do_fork   = false;
    }

    if (optind < argc)
    {
        if (argc - optind > 1)
        {
            cerr << "Too many arguments!" << endl;
            exit(1);
        }

        char path_in[512];
        char path_out[512];

        strncpy(path_in, argv[optind], sizeof(path_in));
        strncat(path_in, ".in", sizeof(path_in));
        strncpy(path_out, argv[optind], sizeof(path_in));
        strncat(path_out, ".out", sizeof(path_in));

        if (freopen(path_in, "rt", stdin) == NULL)
        {
            cerr << "Unable to open input file " << path_in << endl;
            exit(1);
        }

        if (freopen(path_out, "wt", stdout) == NULL)
        {
            cerr << "Unable to open output file " << path_out << endl;
            exit(1);
        }

        show_prog = true;
    }
}

Job *create_job(int id, Case *test_case)
{
    /* Open output file */
    char out_path[] = "job-XXXXXX";
    int fd = mkstemp(out_path);
    if (fd < 0) {
        perror("mkstemp failed");
        abort();
    }
    unlink(out_path);

    /* Create child process (if forking) */
    pid_t child_pid = 0;
    if (do_fork)
    {
        child_pid = fork();
        if (child_pid < 0)
        {
            perror("fork failed");
            abort();
        }
    }

    if (child_pid == 0)
    {
        /* Child process */

        /* Enable core dumps */
        struct rlimit rlim = { RLIM_INFINITY, RLIM_INFINITY };
        setrlimit(RLIMIT_CORE, &rlim);

        char log_path[64];
        if (do_fork)
        {
            /* Create log file */
            sprintf(log_path, "job-%03d.txt", id);
            if (freopen(log_path, "wt", stdout) == NULL) abort();
        }

        /* Solve case */
        Result result;
        test_case->solve(result);

        if (do_fork)
        {
            if (ftell(stdout) == 0) unlink(log_path);
        }

        /* Write output to file */
        if (!result.isEmpty())
        {
            char buf[64];
            sprintf(buf, "Case #%d:", id);
            write(fd, buf, strlen(buf));
            if (result.isSingle())
            {
                string line = result.getSingle();
                write(fd, " ", 1);
                write(fd, line.data(), line.size());
                write(fd, "\n", 1);
            }
            else
            {
                write(fd, "\n", 1);
                const VS &vs = result.getMany();
                FORIT(it, vs) {
                    write(fd, it->data(), it->size());
                    write(fd, "\n", 1);
                }
            }
        }

        /* Succesfully terminate to signal parent */
        if (do_fork) exit(0);
    }

    return do_fork ? new ForkedJob(fd, child_pid) : new Job(fd);
}

void sig_handler(int sig)
{
    fprintf(stderr, "Process %d exiting on signal %d!\n", (int)getpid(), sig);
    exit(sig);
}

int main(int argc, char* argv[])
{
    parse_args(argc, argv);

    signal(SIGINT, sig_handler);
    signal(SIGTERM, sig_handler);

    int cases = PARSE<int>(LINE());
    if (cases == 0) return 0;

    time_t time_start = time(NULL);
    if (single_case > 0)
    {
        if (single_case > cases)
        {
            cerr << "Selected case out of range!" << endl;
            exit(1);
        }
        REP(c, single_case - 1)
        {
            Case *case_ = read_case();
            delete case_;
        }
        cases = 1;
    }

    vector<Job*> jobs;
    int caseno = single_case ? single_case : 1;
    REP(n, cases + max_procs)
    {
        if (n >= max_procs)
        {
            int jobid = n - max_procs + 1;
            Job *job = jobs[jobid - 1];

            job->wait();

            if (!job->success)
            {
                cout << "Case #" << jobid << " failed!\n";
            }
            else
            {
                char buffer[4096];
                size_t total_read = 0;
                ssize_t nread;

                lseek(job->filedes, 0, SEEK_SET);
                while ((nread = read(job->filedes, buffer, sizeof(buffer))) > 0)
                {
                    total_read += nread;
                    cout.write(buffer, nread);
                }
                if (!total_read)
                {
                    job->success = false;
                    cout << "Case #" << jobid << " produced no output!\n";
                }
                cout.flush();
                close(job->filedes);
            }
        }
        if (n < cases)
        {
            Case *case_ = read_case();
            jobs.push_back(create_job(caseno++, case_));
            delete case_;
        }

        if (show_prog)
        {
            int secs = (int)(time(NULL) - time_start);
            fprintf(stderr, "\r%02d:%02d [", secs/60, secs%60);
            REP(c, cases) fputc(c > n ? '.' : c > n - max_procs ? '~' :
                                jobs[c]->success ? 'v' : '-', stderr);
            fprintf(stderr, "] %3d%% ", 100*(max(0, n - max_procs + 1))/cases);
            fflush(stderr);
        }
    }
    if (show_prog) fputc('\n', stderr);
}

/* GCJ template part 06 -- Solution implementation */

struct RealCase : public Case
{
    RealCase();
    void solve(Result &result);

    double f, R, t, r, g;
};

Case *read_case() { return new RealCase(); }

RealCase::RealCase()
{
    cin >> f >> R >> t >> r >> g;
}


const double pi = 3.1415926535897932384626433832795;

struct Point
{
    double x, y;

    bool operator==(const Point &p) const {
        return abs(x - p.x) < 1e-9 && abs(y - p.y) < 1e-9;
    }

    bool operator!=(const Point &p) const {
        return abs(x - p.x) >= 1e-9 || abs(y - p.y) >= 1e-9;
    }

    bool operator<(const Point &p) const {
        return (abs(x - p.x) >= 1e-9) ? x < p.x : (abs(y - p.y) >= 1e-9) ? (y < p.y) : 0;
    }

    Point &operator=(const Point &v) {
        x = v.x;
        y = v.y;
        return *this;
    }

    Point operator*(double f) const {
        return (Point) { x*f, y*f };
    }

    Point operator/(double f) const {
        return (Point) { x/f, y/f };
    }

    Point operator+(const Point &v) const {
        return (Point) { x + v.x, y + v.y };
    }

    Point operator-(const Point &v) const {
        return (Point) { x - v.x, y - v.y };
    }

    double lensq() const {
        return x*x + y*y; // Pythagoras
    }

    double len() const {
        return sqrt(lensq());
    }

    Point normal() const {
        return (Point) { -y, x };
    }
};

typedef vector<Point> Poly;


/*  Double signed area of triangle.
    abs(0.5*area(p,q,r)) == area of triangle p,q,r

    Triangle from p to q to r counterclockwise iff
    r on the left of the line from p to q iff

        |  p.x  p.y  1  |
    det |  q.y  q.y  1  | > 0
        |  r.y  r.y  1  |
*/
double area(const Point &p, const Point &q, const Point &r)
{
    return  p.x * q.y - p.y * q.x +
            p.y * r.x - p.x * r.y +
            q.x * r.y - r.x * q.y;
}

/* Double signed area of a polygon.
   abs(area(poly))/2 == area of polygon 'poly' */
double area(const vector<Point> &polygon)
{
   double area = 0;
   REP(i, polygon.size()) {
      int j = (i + 1) % polygon.size();
      area += polygon[i].x * polygon[j].y;
      area -= polygon[i].y * polygon[j].x;
   }

   return area;
}

inline Point pt(double T, double u)
{
    return (Point) { (1.0-T)*cos(u), (1.0-T)*sin(u) };
}

inline void add_arc(Poly &pol, double T, double u, double v)
{
    while (u < v) { pol.PB(pt(T, u)); u += 0.0001; };
    pol.PB(pt(T, v));
}

double angle(double T, const Point &p, const Point &q)
{
    double lo = 0, hi = M_PI/2;
    REP(_,50)
    {
        double mid = (hi + lo)/2;
        if (area(p, q, pt(T, mid)) < 0)
            lo = mid;
        else
            hi = mid;
    }
    return (hi + lo)/2;
}

double doSolve(const double T, const double R, const double G)
{
    if (T < 0 || G < 0) return 1;

#ifdef SVG
    cout << "<?xml version=\"1.0\" standalone=\"no\"?>\n";
    cout << "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n";
    cout << "<svg width=\"100\" height=\"100\"><g transform=\"scale(100)\">";
    cout << "<circle r=\"1.0\" fill=\"none\" stroke=\"black\" stroke-width=\"0.01\" />\n";
    cout << "<circle r=\"" << 1.0 - T << "\" fill=\"none\" stroke=\"red\" stroke-width=\"0.01\" />\n";
#endif

    double stride = 2*R + G;
    double res = 0;
    int row = 0;
    for (;;)
    {
        int col = 0;
        for (;;)
        {
            Poly pol;
            Point a = (Point) { col*stride + R,     row*stride + R };
            Point b = (Point) { col*stride + R + G, row*stride + R };
            Point c = (Point) { col*stride + R,     row*stride + R + G };
            Point d = (Point) { col*stride + R + G, row*stride + R + G };
            if (a.len() >= 1.0 - T) break;
#ifdef SVG
            cout << "<rect x=\"" << a.x << "\" y=\"" << a.y << "\" width=\"" << (d.x - a.x) << "\" height=\"" << (d.y - a.y) << "\" fill=\"none\" stroke=\"black\" stroke-width=\"0.001\" />\n";
#endif

            if (d.len() <= 1.0 - T)
            {
                pol.PB(a);
                pol.PB(b);
                pol.PB(d);
                pol.PB(c);
            }
            else
            if (b.len() <= 1.0 - T && c.len() <= 1.0 - T)
            {
                double u = angle(T, b, d);
                double v = angle(T, c, d);
                pol.PB(a);
                pol.PB(b);
                add_arc(pol, T, u, v);
                pol.PB(c);
            }
            else
            if (b.len() <= 1.0 - T)
            {
                double u = angle(T, b, d);
                double v = angle(T, a, c);
                pol.PB(a);
                pol.PB(b);
                add_arc(pol, T, u, v);
            }
            else
            if (c.len() <= 1.0 - T)
            {
                double u = angle(T, a, b);
                double v = angle(T, c, d);
                pol.PB(a);
                add_arc(pol, T, u, v);
                pol.PB(c);
            }
            else
            {
                double u = angle(T, a, b);
                double v = angle(T, a, c);
                pol.PB(a);
                add_arc(pol, T, u, v);
            }
            res += 0.5*area(pol);
            ++col;

#ifdef SVG
            cout << "<polygon fill=\"blue\" points=\"";
            FORIT(it, pol) {
                if (it != pol.begin()) cout << " ";
                cout << it->x << ',' << it->y;
            }
            cout << "\" />\n";
#endif
        }
        if (col == 0) break;
        ++row;
    }

#ifdef SVG
    cout << "</g></svg>\n";
#endif
    return 1.0 - 4.0*res/M_PI;
}

void RealCase::solve(Result &result)
{
    char buf[64];
    sprintf(buf, "%.10f", doSolve((t + f)/R, (r + f)/R, (g - 2*f)/R));
    result.set(buf);
}
