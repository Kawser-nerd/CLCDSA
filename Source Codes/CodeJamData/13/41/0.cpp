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

static ll cost(ll start, ll end, ll N)
{
    ll d = end - start;
    return d * (2 * N - d + 1) / 2;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        vector<pii> events;
        int N, M;
        cin >> N >> M;
        ll orig = 0;
        for (int i = 0; i < M; i++)
        {
            int s, e, p;
            cin >> s >> e >> p;
            events.push_back(pii(s, -p));
            events.push_back(pii(e, p));
            orig += p * cost(s, e, N);
        }
        sort(RA(events));
        stack<pii> st;
        ll ans = 0;
        for (pii e : events)
        {
            if (e.second < 0)
                st.emplace(e.first, -e.second);
            else
            {
                int m = e.second;
                while (m > 0)
                {
                    assert(!st.empty());
                    int u = min(st.top().second, m);
                    ans += u * cost(st.top().first, e.first, N);
                    st.top().second -= u;
                    if (st.top().second == 0)
                        st.pop();
                    m -= u;
                }
            }
        }
        cout << "Case #" << cas + 1 << ": " << orig - ans << "\n";
    }
    return 0;
}
