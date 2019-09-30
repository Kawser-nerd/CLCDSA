#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <algorithm>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int rnd()
{
    return rand() ^ (rand() << 10);
}

int rnd(int n)
{
    return rnd() % n;
}

vector<int> bad(int n)
{
    vector<int> p(n);
    forn(i, n)
        p[i] = i;

    forn(i, n)
    {
        int j = rnd(n);
        swap(p[i], p[j]);
    }

    return p;
}

vector<int> good(int n)
{
    vector<int> p(n);
    forn(i, n)
        p[i] = i;

    forn(i, n)
    {
        int j = i + rnd(n - i);
        swap(p[i], p[j]);
    }

    return p;
}

double f(vector<int> a)
{
    int n = a.size();

    double sum = 0;
    forn(i, n)
        if (a[i] > i)
            sum += 1;

    return sum / (n * 1.0);
}

void print(vector<double> a)
{
    double ave = 0;
    forn(i, a.size())
        ave += a[i];
    ave /= a.size();

    double dis = 0;
    forn(i, a.size())
        dis += (a[i] - ave) * (a[i] - ave);
    dis /= a.size();
    dis = sqrt(dis);

    cerr << ave << " " << dis << endl;
}

int main(int argc, char* argv[])
{
    srand(time(NULL));

    int n = 1000;
    int m = 10000;

    vector<double> sa(m);
    vector<double> sb(m);

    forn(i, m)
    {

    vector<int> a = good(n);
    //cout << f(a) << endl;
    sa[i] = f(a);

    
    vector<int> b = bad(n);
    //cout << f(b) << endl;
    sb[i] = f(b);

    }

    print(sa);
    print(sb);

    int tt;
    cin >> tt;

    forn(tx, tt)
    {
        int n;
        cin >> n;
        vector<int> p(n);
        forn(i, n)
            cin >> p[i];
        double ff = f(p);
        bool ok = abs(ff - 0.5) < 0.015;
        cout << "Case #" << (tx + 1) << ": " << (ok ? "GOOD" : "BAD") << endl;
        //cout << (ok ? "GOOD" : "BAD") << endl;
    }
}
