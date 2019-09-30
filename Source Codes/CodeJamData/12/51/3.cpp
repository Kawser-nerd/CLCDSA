#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
struct fun
{
    int a, b, id;
} data[1000];

bool operator < (const fun& a, const fun& b)
{
    int tmp = a.b*b.a-a.a*b.b;
    if (tmp != 0) return tmp < 0;
    return a.id < b.id;
}

int main ()
{
    int t, ct;
    scanf ("%d", &t);

    for (ct = 1; ct <= t; ct ++)
    {
        scanf ("%d", &n);

        for (int i = 0; i < n; i ++)
            scanf ("%d", &data[i].b);
        for (int i = 0; i < n; i ++)
            scanf ("%d", &data[i].a);
        for (int i = 0; i < n; i ++)
            data[i].id = i;

        sort(data, data + n);

        printf ("Case #%d:", ct);
        for (int i = 0; i < n; i ++)
            printf (" %d", data[i].id);
        printf ("\n");
    }

    return 0;
}
