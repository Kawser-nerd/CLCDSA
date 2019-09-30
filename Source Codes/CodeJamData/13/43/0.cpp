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
#include <fcntl.h>
#include <unistd.h>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
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

    ios::sync_with_stdio(false);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        int N;
        cin >> N;
        vi X(N, -1), A(N), B(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];
        for (int i = 0; i < N; i++)
            cin >> B[i];

        vector<vi> edges(N);
        vi deg(N, 0);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (i != j)
                {
                    if ((A[i] >= A[j] && B[i] > B[j])
                        || (A[i] > A[j] && B[i] >= B[j]))
                        edges[j].push_back(i);
                }
        vi prev(N + 1, -1);
        for (int i = 0; i < N; i++)
        {
            if (A[i] > 1)
                edges[prev[A[i] - 1]].push_back(i);
            if (prev[A[i]] != -1)
                edges[i].push_back(prev[A[i]]);
            prev[A[i]] = i;
        }
        fill(RA(prev), -1);
        for (int i = N - 1; i >= 0; i--)
        {
            if (B[i] > 1)
                edges[prev[B[i] - 1]].push_back(i);
            if (prev[B[i]] != -1)
                edges[i].push_back(prev[B[i]]);
            prev[B[i]] = i;
        }

        set<int> act;
        for (int i = 0; i < N; i++)
            for (int e : edges[i])
                deg[e]++;
        for (int i = 0; i < N; i++)
            if (deg[i] == 0)
                act.insert(i);
        for (int i = 0; i < N; i++)
        {
            assert(!act.empty());
            int p = *act.begin();
            act.erase(p);
            X[p] = i + 1;
            for (int y : edges[p])
                if (--deg[y] == 0)
                    act.insert(y);
        }
        cout << "Case #" << cas + 1 << ":";
        for (int i = 0; i < N; i++)
            cout << ' ' << X[i];
        cout << '\n';

        vi a(N), b(N);
        for (int i = 0; i < N; i++)
        {
            a[i] = 1;
            for (int j = 0; j < i; j++)
                if (X[j] < X[i])
                    a[i] = max(a[i], a[j] + 1);
        }
        for (int i = N - 1; i >= 0; i--)
        {
            b[i] = 1;
            for (int j = i + 1; j < N; j++)
                if (X[j] < X[i])
                    b[i] = max(b[i], b[j] + 1);
        }
        assert(a == A);
        assert(b == B);
    }
    return 0;
}
