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
}

static void do_swap(vector<int> &remap, vector<int> &rmap, int src, int trg)
{
    int tmp = rmap[trg];
    swap(remap[src], remap[tmp]);
    rmap[remap[src]] = src;
    rmap[remap[tmp]] = tmp;
    assert(remap[src] == trg);
}

static void do_remap(const vector<int> &out_ref, vector<int> &out_trg, int sz)
{
    vector<int> remap(sz);
    vector<int> rmap(sz);
    for (int i = 0; i < sz; i++)
    {
        remap[i] = i;
        rmap[i] = i;
    }
    do_swap(remap, rmap, out_trg[0], out_ref.back());
    do_swap(remap, rmap, out_trg.back(), out_ref[0]);
    assert(remap[out_trg[0]] == out_ref.back());
    assert(remap[out_trg.back()] == out_ref[0]);
    for (size_t i = 0; i < out_trg.size(); i++)
        out_trg[i] = remap[out_trg[i]];
}

static bool recurse(int N, int C, const vector<pii> &edges, vector<int> &out)
{
    out.resize(N);
    if (edges.empty())
    {
        if (N < C)
            return false;

        for (int i = 0; i < N; i++)
            out[i] = i % C;
        if (out.back() == 0)
            out.back() = 1;
        return true;
    }
    else
    {
        vector<pii> ccw;
        vector<pii> cw;
        vector<int> out_ccw;
        vector<int> out_cw;
        int A = edges[0].first;
        int B = edges[0].second;
        if (B < A) swap(A, B);
        for (size_t i = 1; i < edges.size(); i++)
        {
            const pii &e = edges[i];
            if ((e.first > A && e.first < B)
                || (e.second > A && e.second < B))
            {
                cw.push_back(pii(e.first - A, e.second - A));
            }
            else
            {
                int a = e.first - B; if (a < 0) a += N;
                int b = e.second - B; if (b < 0) b += N;
                ccw.push_back(pii(a, b));
            }
        }

        if (!recurse(B - A + 1, C, cw, out_cw)
            || !recurse(A - B + N + 1, C, ccw, out_ccw))
            return false;

        do_remap(out_cw, out_ccw, C);

        for (int i = A; i <= B; i++)
            out[i] = out_cw[i - A];
        for (int i = B; i < N; i++)
            out[i] = out_ccw[i - B];
        for (int i = 0; i <= A; i++)
            out[i] = out_ccw[i + N - B];

        for (int i = 0; i + 1 < N; i++)
            assert(out[i] != out[i + 1]);
        assert(out[0] != out[N - 1]);
        return true;
    }
}

static void verify(int N, const vector<pii> &edges, int ans, const vector<int> &out)
{
    assert(out.size() == N);
    if (edges.empty())
    {
        vector<bool> seen(ans);
        for (int i = 0; i < N; i++)
        {
            assert(out[i] >= 0 && out[i] < ans);
            seen[out[i]] = true;
        }
        assert(count(RA(seen), true) == ans);
    }
    else
    {
        vector<pii> ccw;
        vector<pii> cw;
        int A = edges[0].first;
        int B = edges[0].second;
        if (B < A) swap(A, B);
        for (size_t i = 1; i < edges.size(); i++)
        {
            const pii &e = edges[i];
            if ((e.first > A && e.first < B)
                || (e.second > A && e.second < B))
            {
                cw.push_back(pii(e.first - A, e.second - A));
            }
            else
            {
                int a = e.first - B; if (a < 0) a += N;
                int b = e.second - B; if (b < 0) b += N;
                ccw.push_back(pii(a, b));
            }
        }

        vector<int> out_cw(B - A + 1);
        for (int i = A; i <= B; i++)
            out_cw[i - A] = out[i];
        verify(out_cw.size(), cw, ans, out_cw);

        vector<int> out_ccw(A - B + N + 1);
        for (int i = B; i < N; i++)
            out_ccw[i - B] = out[i];
        for (int i = 0; i <= A; i++)
            out_ccw[i - B + N] = out[i];
        verify(out_ccw.size(), ccw, ans, out_ccw);
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        int N, M;
        cin >> N >> M;
        vector<pii> edges(M);
        for (int i = 0; i < M; i++)
        {
            cin >> edges[i].first;
            edges[i].first--;
        }
        for (int i = 0; i < M; i++)
        {
            cin >> edges[i].second;
            edges[i].second--;
        }

        int L = 3, R = N + 1;
        while (R - L > 1)
        {
            vector<int> out;
            int mid = (L + R) / 2;
            if (recurse(N, mid, edges, out))
                L = mid;
            else
                R = mid;
        }
        int ans = L;
        vector<int> out;
        recurse(N, ans, edges, out);
        verify(N, edges, ans, out);

        printf("Case #%d: %d\n", cas + 1, ans);
        for (int i = 0; i < N; i++)
        {
            if (i) cout << ' ';
            cout << out[i] + 1;
        }
        cout << '\n';
    }
    return 0;
}
