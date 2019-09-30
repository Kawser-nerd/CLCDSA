#include <cstdio>
using namespace std;

int TC = 1, T, N, K;

int main ()
{
    for (scanf ("%d", &T); TC <= T; TC++)
    {
        scanf ("%d %d", &N, &K);
        printf ("Case #%d: ", TC);
        puts ((K + 1) % (1 << N) == 0 ? "ON" : "OFF");
    }

    return 0;
}
