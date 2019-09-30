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

int S;
char square [150];
long long and_check, or_check;

void initialize ()
{

}

void initialize_case ()
{
    scanf ("%s", square);
    S = strlen (square);
    and_check = or_check = 0;

    for (int i = 0; i < S; i++)
    {
        and_check <<= 1;
        or_check <<= 1;

        if (square [i] == '1')
            and_check += 1;

        if (square [i] == '0')
            or_check += 1;
    }
}

string solve_case ()
{
    initialize_case ();
    ostringstream output;
    long long answer = -1;
    int count = 0;

    int n = 1;
    long long sq = n * n;

    while (sq <= 1LL << S)
    {
        if ((sq & and_check) == and_check && (sq & or_check) == 0)
        {
            answer = sq;
            count++;
        }

        n++;
        sq += 2 * n - 1;
    }

    assert (count == 1);

    int B = 0;

    while (answer >= (1LL << B))
        B++;

    for (int i = B - 1; i >= 0; i--)
        output << ((answer & 1LL << i) != 0 ? '1' : '0');

    fprintf (stderr, "%lld\n", answer);
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
