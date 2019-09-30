#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <sstream>
#include <cstddef>
#include <algorithm>
#include <utility>
#include <iterator>
#include <numeric>
#include <list>
#include <complex>
#include <cstdio>
#include <climits>
#include <boost/dynamic_bitset.hpp>
#include <tr1/unordered_map>
#include <tr1/random>
#include <fcntl.h>
#include <unistd.h>

using namespace std;
using namespace std::tr1;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef complex<double> pnt;
typedef pair<int, int> pii;

#define RA(x) (x).begin(), (x).end()
#define FE(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())

template<class T>
void splitstr(const string &s, vector<T> &out)
{
    istringstream in(s);
    out.clear();
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
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
}

typedef boost::dynamic_bitset<unsigned int> db;

static ll ssum(const vll &V, const db &mask)
{
    ll t = 0;
    for (int i = 0; i < SZ(V); i++)
        if (mask[i])
            t += V[i];
    return t;
}

static void dump(const vll &V, const db &mask)
{
    bool first = true;
    for (int i = 0; i < SZ(V); i++)
        if (mask[i])
        {
            if (!first)
                printf(" ");
            first = false;
            printf("%lld", V[i]);
        }
    printf("\n");
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        printf("Case #%d:\n", cas + 1);
        int N;
        cin >> N;
        vll V(N);
        for (int i = 0; i < N; i++)
            cin >> V[i];

        unordered_map<ll, db> sols;
        db guess(N);
        mt19937 engine;
        const unsigned int sz = (N + 31) / 32;
        unsigned int blocks[sz];
        for (int pass = 0; pass < 100000000; pass++)
        {
            for (unsigned int i = 0; i < sz; i++)
                blocks[i] = engine();
            guess.clear();
            guess.append(blocks, blocks + sz);
            ll t = 0;
            for (int j = 0; j < N; j++)
                if (guess[j])
                    t += V[j];
            if (sols.count(t))
            {
                db mb = sols[t];
                db com = guess & mb;
                mb ^= com;
                guess ^= com;
                if (mb.count())
                {
                    dump(V, mb);
                    dump(V, guess);
                    goto found;
                }
            }
            sols[t] = guess;
        }

        printf("Impossible\n");
        continue;
found:;
    }
    return 0;
}
