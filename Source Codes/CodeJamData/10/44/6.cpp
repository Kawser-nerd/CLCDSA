#include <cstdio>
#include <complex>
#include <cmath>
using namespace std;

const int MAXN = 5005, MAXM = 1005;

int TC = 1, T, N, M;
complex <double> goat [MAXN], pole [MAXM];

double intersect (complex <double> X, complex <double> Y, complex <double> P)
{
    double R = abs (X - P);
    double ang = abs (arg (P - X) - arg (Y - X));

    if (ang > M_PI)
        ang = 2 * M_PI - ang;

    return ang * R * R - 0.5 * R * R * sin (2 * ang);
}

int main ()
{
    for (scanf ("%d", &T); TC <= T; TC++)
    {
        scanf ("%d %d", &N, &M);

        for (int i = 0, x, y; i < N; i++)
        {
            scanf ("%d %d", &x, &y);
            goat [i] = complex <double> (x, y);
        }

        for (int i = 0, x, y; i < M; i++)
        {
            scanf ("%d %d", &x, &y);
            pole [i] = complex <double> (x, y);
        }

        printf ("Case #%d:", TC);

        for (int i = 0; i < M; i++)
            printf (" %.7lf", intersect (goat [0], goat [1], pole [i]) + intersect (goat [1], goat [0], pole [i]));

        printf ("\n");
    }

    return 0;
}
