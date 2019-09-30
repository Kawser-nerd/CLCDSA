#include <cstdio>
#include <map>
#include <cstring>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int T;
map <int, bool> hap [11];
char line [1000];

inline bool happy (int b, int x)
{
    if (b == 2 || b == 4)
        return true;

    if (x == 1)
        return true;

    if (x == 0)
        return false;

    int sum = 0;

    while (x > 0)
    {
        sum += (x % b) * (x % b);
        x /= b;
    }

    x = sum;

    if (hap [b].find (x) != hap [b].end ())
        return hap [b][x];

    hap [b][x] = false;
    return hap [b][x] = happy (b, x);
}

int main ()
{
    srand (time (NULL));
    scanf ("%d", &T);

    for (int t = 1; t <= T; t++)
    {
        fprintf (stderr, "Test %d\n", t);

        do
            fgets (line, sizeof (line), stdin);
        while (strlen (line) <= 1);

        istringstream in (line);
        int x;
        vector <int> bases;

        while (in >> x)
            bases.push_back (x);

        random_shuffle (bases.begin (), bases.end ());
        int best = 2;

        while (true)
        {
            bool good = true;

            for (int i = 0; i < (int) bases.size () && good; i++)
                if (!happy (bases [i], best))
                    good = false;

            if (good)
            {
                printf ("Case #%d: %d\n", t, best);
                fflush (stdout);
                break;
            }

            best++;
        }
    }

    return 0;
}
