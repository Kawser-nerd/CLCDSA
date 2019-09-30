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

const int MAX = 1005, ITER = 500;

int W, L, U, G;
complex <int> lower [MAX], upper [MAX];

void initialize ()
{

}

void initialize_case ()
{

}

inline double poly_area (int n, complex <int> points [MAX], double x)
{
    double total = 0;

    for (int i = 0; i + 1 < n; i++)
        if (x > points [i + 1].real ())
        {
            total += (points [i + 1].real () - points [i].real ()) * 0.5 * (points [i].imag () + points [i + 1].imag ());
        }
        else
        {
            double y = points [i].imag () + (x - points [i].real ()) / (points [i + 1].real () - points [i].real ()) * (points [i + 1].imag () - points [i].imag ());
            total += (x - points [i].real ()) * 0.5 * (points [i].imag () + y);
            break;
        }

    return total;
}

inline double area (double x)
{
    return poly_area (U, upper, x) - poly_area (L, lower, x);
}

string solve_case ()
{
    initialize_case ();
    ostringstream output;

    scanf ("%d %d %d %d", &W, &L, &U, &G);

    for (int i = 0; i < L; i++)
        scanf ("%d %d", &lower [i].real (), &lower [i].imag ());

    for (int i = 0; i < U; i++)
        scanf ("%d %d", &upper [i].real (), &upper [i].imag ());

    double total_area = area (W);

    for (int g = 1; g <= G - 1; g++)
    {
        double lo = 0, hi = W;

        for (int it = 0; it < ITER; it++)
        {
            double mid = (lo + hi) / 2;

            if (area (mid) < g * total_area / G)
                lo = mid;
            else
                hi = mid;
        }

        output << setprecision (15) << lo << '\n';
    }

    return output.str ();
}

int main ()
{
    initialize ();
    int T; scanf ("%d", &T);

    for (int tc = 1; tc <= T; tc++)
        printf ("Case #%d:\n%s", tc, solve_case ().c_str ());

    return 0;
}
