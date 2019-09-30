#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

const int MAXN = 10, PERMS = 1500, HASH = 1009;

int N, P, sequence [MAXN];
vector <int> perms [PERMS];

inline bool match (int *values, vector <int> perm)
{
    for (int i = 0; i < N; i++)
        if (values [i] != -1 && values [i] != perm [i])
            return false;

    return true;
}

bool remain [MAXN];
map <long long, bool> save;

bool worst_case (int steps, int *values)
{
    if (steps == N)
        return true;

    long long hash = steps;

    for (int i = 0; i < N; i++)
        hash = hash * HASH + values [i];

    if (save.count (hash))
        return save [hash];
/*
    printf ("%d\n", steps);

    for (int i = 0; i < N; i++)
        printf ("%d%c", values [i], i + 1 < N ? ' ' : '\n');
*/
    memset (remain, false, sizeof (remain));

    for (int i = 0; i < P; i++)
        if (match (values, perms [i]))
        {
            for (int j = 0; j < N; j++)
                if (perms [i][j] == 0)
                    remain [j] = true;
        }

    for (int i = 0; i < N; i++)
        if (values [i] == -1 && !remain [i])
            return save [hash] = false;

    for (int strat = 0; strat < N; strat++)
        if (values [strat] == -1)
        {
            bool any = false;

            for (int i = 0; i < N; i++)
            {
                values [strat] = i;

                if (worst_case (steps + 1, values))
                {
                    any = true;
                    values [strat] = -1;
                    break;
                }
            }

            values [strat] = -1;

            if (!any)
                return save [hash] = false;
        }

    return save [hash] = true;
}

void initialize ()
{
}

bool valid (vector <int> perm)
{
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            for (int k = j + 1; k < N; k++)
                if (perm [i] > perm [j] && perm [j] > perm [k])
                    return false;

    return true;
}

void initialize_case ()
{
    vector <int> perm (N, 0);

    for (int i = 0; i < N; i++)
        perm [i] = i;

    P = 0;

    do
    {
        if (valid (perm))
            perms [P++] = perm;
    }
    while (next_permutation (perm.begin (), perm.end ()));

    sort (perms, perms + P);
    reverse (perms, perms + P);
//    printf ("%d perms\n", P);
}

string solve_case ()
{
    scanf ("%d", &N);
    initialize_case ();
    ostringstream output;

    for (int i = 0; i < N; i++)
    {
        scanf ("%d", sequence + i);
        sequence [i]--;
//        printf ("%d %d\n", i, sequence [i]);
    }

    int values [MAXN];

    for (int p = 0; p < P; p++)
    {
        memset (values, -1, sizeof (values));
        bool good = true;

        for (int i = 0; i < N; i++)
        {
//            puts ("hi");

            if (!worst_case (i, values))
            {
                good = false;
                break;
            }

            values [sequence [i]] = perms [p][sequence [i]];
        }

        if (good)
        {
            for (int i = 0; i < N; i++)
            {
                output << perms [p][i] + 1;

                if (i + 1 < N)
                    output << ' ';
            }

            break;
        }
    }

    return output.str ();
}

int main ()
{
    initialize ();
    int T; scanf ("%d", &T);

    for (int tc = 1; tc <= T; tc++)
        printf ("Case #%d: %s\n", tc, solve_case ().c_str ());

    return 0;
}
