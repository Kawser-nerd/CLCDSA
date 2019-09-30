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
#include <deque>

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

static int R, C;
static vs grid;

struct state
{
    int r;
    int c;
    int pr[2];
    int pc[2];
};

#define ADDR(state) state.r][state.c][state.pr[0]][state.pc[0]][state.pr[1]][state.pc[1]

static unsigned char prio[16][16][16][16][16][16];

static const int dr[4] = {-1, 0, 1, 0};
static const int dc[4] = {0, -1, 0, 1};

int main()
{
    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        cin >> R >> C;
        grid.clear();
        grid.resize(R + 2);

        state start;
        memset(&start, 0, sizeof(start));
        grid[0] = string(C + 2, '#');
        grid[R + 1] = grid[0];
        for (int i = 1; i <= R; i++)
        {
            string line;
            cin >> line;
            grid[i] = "#" + line + "#";
            if (grid[i].find("O") != string::npos)
            {
                start.r = i;
                start.c = grid[i].find("O");
                grid[i][start.c] = '.';
            }
        }

        memset(prio, 255, sizeof(prio));
        prio[ADDR(start)] = 0;
        deque<state> q;
        q.push_back(start);
        int ans = -1;
        while (!q.empty())
        {
            state cur = q.front();
            unsigned char pri = prio[ADDR(cur)];
            if (grid[cur.r][cur.c] == 'X')
            {
                ans = pri;
                break;
            }
            q.pop_front();

            for (int d = 0; d < 4; d++)
            {
                int hr = cur.r;
                int hc = cur.c;
                do
                {
                    hr += dr[d];
                    hc += dc[d];
                } while (grid[hr][hc] != '#');
                hr -= dr[d];
                hc -= dc[d];

                for (int p = 0; p < 2; p++)
                {
                    state nxt = cur;
                    nxt.pr[p] = hr;
                    nxt.pc[p] = hc;
                    if (prio[ADDR(nxt)] > pri)
                    {
                        prio[ADDR(nxt)] = pri;
                        q.push_front(nxt);
                    }
                }
            }

            for (int d = 0; d < 4; d++)
            {
                state nxt = cur;
                nxt.r += dr[d];
                nxt.c += dc[d];
                if (grid[nxt.r][nxt.c] != '#')
                {
                    if (prio[ADDR(nxt)] > pri + 1)
                    {
                        prio[ADDR(nxt)] = pri + 1;
                        q.push_back(nxt);
                    }
                }
            }
            if (cur.pr[0] > 0 && cur.pr[1] > 0)
                for (int p = 0; p < 2; p++)
                    if (cur.pr[p] == cur.r && cur.pc[p] == cur.c)
                    {
                        state nxt = cur;
                        nxt.r = cur.pr[1 - p];
                        nxt.c = cur.pc[1 - p];
                        if (prio[ADDR(nxt)] > pri + 1)
                        {
                            prio[ADDR(nxt)] = pri + 1;
                            q.push_back(nxt);
                        }
                    }
        }

        printf("Case #%d: ", cas + 1);
        if (ans == -1)
            printf("THE CAKE IS A LIE\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}
