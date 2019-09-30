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

const int MAXC = 50005;

int N, cards [MAXC];

void initialize ()
{

}

void initialize_case ()
{
    memset (cards, 0, sizeof (cards));
}

bool possible (int k)
{
    vector <int> straights;

    for (int c = 0; c < MAXC; c++)
    {
        int ncards = cards [c];

        sort (straights.begin (), straights.end ());
        int n = straights.size (), i = 0;

        while (i < n && straights [i] < k)
        {
            if (ncards <= 0)
                return false;

            straights [i]++;
            ncards--;
            i++;
        }

        while (i < n && ncards > 0)
        {
            straights [i]++;
            ncards--;
            i++;
        }

        if (i < n)
            straights.resize (i);

        while (ncards > 0)
        {
            straights.push_back (1);
            ncards--;
        }
    }

    for (int i = 0; i < (int) straights.size (); i++)
        if (straights [i] < k)
            return false;

    return true;
}

string solve_case ()
{
    initialize_case ();
    ostringstream output;

    scanf ("%d", &N);

    if (N == 0)
        return "0";

    for (int card, i = 0; i < N; i++)
    {
        scanf ("%d", &card);
        cards [card]++;
    }

    int lo = 0, hi = MAXC;

    while (lo < hi)
    {
        int mid = (lo + hi + 1) >> 1;

        if (possible (mid))
            lo = mid;
        else
            hi = mid - 1;
    }

    output << lo;
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
