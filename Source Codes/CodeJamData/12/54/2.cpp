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

static int dfs(bool *seen, const int *odeg, const vector<int> *edges, int cur)
{
    int ans = 0;
    if (seen[cur])
        return 0;
    seen[cur] = true;
    if (odeg[cur] > 0)
        ans += odeg[cur];

    for (int i = 0; i < SZ(edges[cur]); i++)
        ans += dfs(seen, odeg, edges, edges[cur][i]);
    return ans;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int cases;
    cin >> cases;

    const string extra = "oieastbg";

    for (int cas = 0; cas < cases; cas++)
    {
        int K;
        string S;
        cin >> K >> S;

        const int V = 34;
        bool seen[V] = {};
        int odeg[V] = {};
        vector<int> edges[V];
        ll ans = 0;
        set<pair<int, int> > pairs;
        for (int i = 0; i < SZ(S) - 1; i++)
        {
            int codes[2][2];
            for (int j = 0; j < 2; j++)
            {
                char c = S[i + j];
                codes[j][0] = c - 'a';
                if (extra.find(c) != string::npos)
                    codes[j][1] = extra.find(c) + 26;
                else
                    codes[j][1] = -1;
            }

            for (int j = 0; j < 2; j++)
                if (codes[0][j] != -1)
                    for (int k = 0; k < 2; k++)
                        if (codes[1][k] != -1)
                        {
                            int a = codes[0][j];
                            int b = codes[1][k];
                            pair<int, int> key(a, b);
                            if (!pairs.count(key))
                            {
                                pairs.insert(key);
                                edges[a].push_back(b);
                                edges[b].push_back(a);
                                odeg[a]++;
                                odeg[b]--;
                                ans++;
                            }
                        }
        }

        for (int i = 0; i < V; i++)
        {
            if (!seen[i] && !edges[i].empty())
            {
                int E = dfs(seen, odeg, edges, i);
                if (E == 0)
                    E = 1;
                ans += E;
            }
        }

        printf("Case #%d: %lld\n", cas + 1, ans);
    }
    return 0;
}
