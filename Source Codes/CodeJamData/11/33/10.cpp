#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define PI 3.1415926535897932384626433832795

const long long inf = 1000ll * 1000 * 1000 * 1000 * 1000 * 1000;

vector <long long> notes;
long long l, h, best;
int n;

long long nod(long long a, long long b)
{
    if (b == 0)
        return a;
    else
        return nod(b, a % b);
}

long long findnok(int lb, int rb)
{
    if (lb > rb)
        return 1;
    long long nk = notes[lb], d;
    int i;
    for (i = lb + 1; i <= rb; i++)
    {
        d = nod(nk, notes[i]);
        if (inf / (notes[i] / d) < nk)
            return inf;
        else
            nk = nk * (notes[i] / d);
    }
    return nk;
}

bool check(long long d)
{
    if (d < l || d > h)
        return false;
    int i;
    for (i = 0; i < n; i++)
        if (!(notes[i] % d == 0 || d % notes[i] == 0))
            return false;
    return true;
}

long long findnod(int lb, int rb, long long nk)
{
    if (lb > rb)
        return -1;
    if (nk > h)
        return inf;
    int i;
    for (i = lb; i <= rb; i++)
        if (notes[i] % nk != 0)
            return inf;
    long long d = notes[lb] / nk;
    for (i = lb + 1; i <= rb; i++)
        d = nod(d, notes[i] / nk);
    return d;
}

inline bool good(long long val, long long l, long long h, long long mul)
{
    if ((inf / mul) < val)
        return false;
    return (val * mul >= l && val * mul <= h);
}

void process(int v)
{
    int i;
    long long nk = findnok(0, v);
    long long nd = findnod(v + 1, n - 1, nk);
    cerr << v << ' ' << nk << ' ' << nd << endl;
    if (nk == inf || nd == inf)
        return;
    if (nd == -1)
    {
        long long hh = l / nk;
        long long th = nk * hh;
        while (th < l)
            th += nk;
        nk = th;
    }
    if (nd != 1 && nd != -1)
    {
        long long nkr = inf;
        long long lm = (long long) sqrt(nd * 1.0);
        for (i = 1; i <= lm; i++)
        {
            if (nd % i == 0)
            {
                if (good(nk, l, h, i))
                    nkr = min(nkr, nk * i);
                if (good(nk, l, h, nd / i))
                    nkr = min(nkr, nk * (nd / i));
            }
        }
        if (nkr == inf)
            return;
        nk = nkr;
    }
    if (nk >= l && nk <= h && check(nk))
        best = min(best, nk);
}

int main()
{
    int tc, t, i;
    long long c;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> tc;
    for (t = 0; t < tc; t++)
    {
        cin >> n >> l >> h;
        notes.clear();
        for (i = 0; i < n; i++)
        {
            cin >> c;
            notes.pb(c);
        }
        sort(notes.begin(), notes.end());
        best = inf;
        for (i = -1; i < n; i++)
            process(i);
        cout << "Case #" << t + 1 << ": ";
        if (best == inf)
            cout << "NO" << endl;
        else
            cout << best << endl;
    }

    return 0;
}
