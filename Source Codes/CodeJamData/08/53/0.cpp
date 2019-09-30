#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <set>
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

static bool done[10000];
static int back[10000];
static vector<int> edges[10000];

static bool augment(int x)
{
    if (x == -1)
        return true;
    else if (done[x])
        return false;
    done[x] = true;

    for (int i = 0; i < SZ(edges[x]); i++)
    {
        int y = edges[x][i];
        int old = back[y];
        back[y] = x;
        if (augment(old))
            return true;
        back[y] = old;
    }
    return false;
}

int main()
{
    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        int R, C;
        int id[100][100];
        int pool[2] = {0, 0};
        cin >> R >> C;
        for (int i = 0; i < R; i++)
        {
            string l;
            cin >> l;
            for (int j = 0; j < C; j++)
            {
                if (l[j] == '.')
                    id[i][j] = pool[j & 1]++;
                else
                    id[i][j] = -1;
            }
        }
        for (int i = 0; i < 10000; i++)
            edges[i].clear();
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j += 2)
                if (id[i][j] != -1)
                {
                    int x = id[i][j];
                    if (j > 0 && id[i][j - 1] != -1)
                        edges[x].push_back(id[i][j - 1]);
                    if (j < C - 1 && id[i][j + 1] != -1)
                        edges[x].push_back(id[i][j + 1]);
                    if (i > 0)
                    {
                        if (j > 0 && id[i - 1][j - 1] != -1)
                            edges[x].push_back(id[i - 1][j - 1]);
                        if (j < C - 1 && id[i - 1][j + 1] != -1)
                            edges[x].push_back(id[i - 1][j + 1]);
                    }
                    if (i < R - 1)
                    {
                        if (j > 0 && id[i + 1][j - 1] != -1)
                            edges[x].push_back(id[i + 1][j - 1]);
                        if (j < C - 1 && id[i + 1][j + 1] != -1)
                            edges[x].push_back(id[i + 1][j + 1]);
                    }
                }

        memset(back, -1, sizeof(back));
        int ans = pool[0] + pool[1];
        for (int i = 0; i < pool[0]; i++)
        {
            memset(done, 0, sizeof(done));
            if (augment(i))
                ans--;
        }
        printf("Case #%d: %d\n", cas + 1, ans);
    }
    return 0;
}
