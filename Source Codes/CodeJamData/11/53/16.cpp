#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
#include <cassert>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXA = 10005, MAXB = 10005, INF = 1000000005;

struct DfsMatch
{
    int A, B, elast [MAXA];
    int start, vis [MAXA], prev [MAXB];
    vector <int> eadj, eprev;

    inline DfsMatch ()
    {
        A = B = -1;
    }

    inline void init (int a, int b)
    {
        A = a; B = b;
        memset (elast, -1, A * sizeof (int));
        eadj.clear ();
        eprev.clear ();
    }

    inline void addedge (int a, int b)
    {
        eadj.push_back (b); eprev.push_back (elast [a]); elast [a] = eprev.size () - 1;
    }

    bool dfs (int num)
    {
        if (vis [num] == start)
            return false;

        vis [num] = start;

        for (int i = elast [num]; i != -1; i = eprev [i])
            if (prev [eadj [i]] == -1)
            {
                prev [eadj [i]] = num;
                return true;
            }

        for (int i = elast [num]; i != -1; i = eprev [i])
            if (dfs (prev [eadj [i]]))
            {
                prev [eadj [i]] = num;
                return true;
            }

        return false;
    }

    int match ()
    {
        if (A == -1 && B == -1)
            return -INF;

        memset (prev, -1, B * sizeof (int));
        memset (vis, -1, A * sizeof (int));
        int total = 0;

        for (int i = 0; i < A; i++)
        {
            start = i;

            if (dfs (i))
                total++;
        }

        return total;
    }
};

const int MAX = 105, MAXN = MAX * MAX, MOD = 1000003;

int R, C, N;
char grid [MAX][MAX];
vector <int> adj [MAXN], radj [MAXN];
bool done [MAXN], rdone [MAXN];
DfsMatch graph;

void initialize ()
{

}

inline int mod (int a, int n)
{
    return (a % n + n) % n;
}

inline int to_num (int r, int c)
{
    return r * C + c;
}

inline pair <int, int> to_pair (int ind)
{
    return make_pair (ind / C, ind % C);
}

inline void add_edge (int r1, int c1, int r2, int c2)
{
    r1 = mod (r1, R);
    r2 = mod (r2, R);
    c1 = mod (c1, C);
    c2 = mod (c2, C);
    int n1 = to_num (r1, c1), n2 = to_num (r2, c2);
    adj [n1].push_back (n2);
    radj [n2].push_back (n1);
    graph.addedge (n1, n2);
}

inline void remove_edge (int a, int b)
{
//    adj [a].erase (lower_bound (adj [a].begin (), adj [a].end (), b));
    radj [b].erase (lower_bound (radj [b].begin (), radj [b].end (), a));
}

inline int other (const vector <int> &v, int x)
{
    for (int i = 0; i < (int) v.size (); i++)
        if (v [i] != x)
            return v [i];

    assert (false);
    return -1;
}

void dfs (int num, int prev)
{
//    printf ("dfs %d %d\n", num, prev);
    done [num] = true;
    int next = other (adj [num], prev);
    int next_next = other (radj [next], num);

    if (!done [next_next])
        dfs (next_next, next);
}

string solve_case ()
{
    for (int i = 0; i < MAXN; i++)
    {
        adj [i].clear ();
        radj [i].clear ();
    }

    scanf ("%d %d", &R, &C);
    N = R * C;
    graph.init (N, N);

    for (int i = 0; i < R; i++)
        scanf ("%s", grid [i]);

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (grid [i][j] == '|')
            {
                add_edge (i, j, i - 1, j);
                add_edge (i, j, i + 1, j);
            }
            else if (grid [i][j] == '-')
            {
                add_edge (i, j, i, j - 1);
                add_edge (i, j, i, j + 1);
            }
            else if (grid [i][j] == '/')
            {
                add_edge (i, j, i - 1, j + 1);
                add_edge (i, j, i + 1, j - 1);
            }
            else if (grid [i][j] == '\\')
            {
                add_edge (i, j, i - 1, j - 1);
                add_edge (i, j, i + 1, j + 1);
            }

    if (graph.match () != N)
        return "0";

    for (int i = 0; i < N; i++)
    {
        sort (adj [i].begin (), adj [i].end ());
        sort (radj [i].begin (), radj [i].end ());
    }

    memset (done, false, sizeof (done));
    memset (rdone, false, sizeof (rdone));
    queue <int> q;
    int sum = 0;

    for (int i = 0; i < N; i++)
    {
        sum += radj [i].size ();

        if (radj [i].size () == 0)
            return "0";

        if (radj [i].size () == 1)
        {
            rdone [i] = true;
            q.push (i);
        }
    }

    assert (sum == 2 * N);

    while (!q.empty ())
    {
        int top = q.front (); q.pop ();
        int neighbor = radj [top][0];
//        printf ("assign %d %d\n", neighbor, top);

        if (done [neighbor])
            return "0";

        done [neighbor] = rdone [top] = true;

        for (int i = 0; i < (int) adj [neighbor].size (); i++)
        {
            int next = adj [neighbor][i];
            remove_edge (neighbor, next);

            if (!rdone [next] && radj [next].size () == 1)
            {
                rdone [next] = true;
                q.push (next);
            }
        }

        adj [neighbor].clear ();
    }

    for (int i = 0; i < N; i++)
    {
        if (!done [i])
            assert (adj [i].size () == 2);

        if (!rdone [i])
        {
//            printf ("radj %d %d\n", i, (int) radj [i].size ());
            assert (radj [i].size () == 2);
        }
    }

    int components = 0;

    for (int i = 0; i < N; i++)
        if (!done [i])
        {
            dfs (i, -1);
            components++;
        }

    int answer = 1;

    while (components-- > 0)
        answer = 2 * answer % MOD;

    ostringstream out;
    out << answer;
    return out.str ();
}

int main ()
{
    initialize ();
    int T; scanf ("%d", &T);

    for (int tc = 1; tc <= T; tc++)
        printf ("Case #%d: %s\n", tc, solve_case ().c_str ());

    return 0;
}
