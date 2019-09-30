#include <iostream>

using namespace std;

double bananas(char *a, char *x, int k, int n, int s)
{
    int alphabet[128] = {};

    for (; *a; a++)
        alphabet[*a]++;

    for (int i = 0; i < n; i++)
        if (!alphabet[x[i]])
            return 0;

    double q = 1;
    for (int i = 0; i < n; i++)
        q *= (double)alphabet[x[i]] / k;

    int p[128] = {};
    p[0] = -1;

    for (int i = 0, k = -1; i < n; p[++i] = ++k)
        for (; ~k && x[i] != x[k]; k = p[k]);

    return (s - p[n]) / (n - p[n]) - q * (s - n + 1);

/*
    double d[128][128] = {};
    d[0][0] = 1;

    for (int i = 0; i < s; i++)
        for (int j = 0; j < n; j++)
        {
            d[i + 1][j + 1] = d[i][j] * alphabet[x[i]] / k;
        }
*/
}

int main()
{
    int t;
    cin >> t;

    for (int tt=1; tt <= t; tt++)
    {
        int n, k, s;
        char a[128], x[128];

        cin >> k >> n >> s;
        cin >> a >> x;

        cout.setf(ios::fixed);
        cout.precision(15);
        cout << "Case #" << tt << ": " << bananas(a, x, k, n, s) << endl;
    }

    return 0;
}
